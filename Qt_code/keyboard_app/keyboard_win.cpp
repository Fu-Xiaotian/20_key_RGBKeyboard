#include "mainwindow.h"
#include "keyboard_win.h"
using namespace std;

HANDLE hCom;  //全局变量，串口句柄

std::string process_name[20] = {"nan"};
int drive_port = 0;

bool default_layer = FALSE;
int process_on_num = 0;
bool process_state[20] = {FALSE};
bool old_process_state[20] = {FALSE};

void process_name_init(void)
{
    for(int i = 0; i < 20; i++)
    {
        process_name[i] = "nan";
    }
}

bool auto_layer_chang(void)
{
    bool connect_flag = false;
    for(int i = 1; i < 20; i++)
    {
        if(process_name[i] != "nan")
        {
            process_state[i] = getProcess(process_name[i].c_str());
            if(process_state[i])
            {
                process_on_num++;
            }
            if(process_state[i] != old_process_state[i])
            {
                old_process_state[i] = process_state[i];
                if(process_state[i])
                {
                    connect_flag = set_key_layer(drive_port, i);
                    default_layer = FALSE;
                }
                else
                {
                    connect_flag = set_key_layer(drive_port, 0);
                    default_layer = TRUE;
                }
                break;
            }
        }
    }
    if(process_on_num == 0 && !default_layer)
    {
        connect_flag = set_key_layer(drive_port, 0);
        default_layer = TRUE;
    }
    else
    {
        process_on_num = 0;
    }
    return connect_flag;
}

/**
 * 向目标串口号写键盘层设置
 * 输入：
 *      port_num : 串口编号
 *      key_layer ： 键盘层编号（层数-1）
 * */
bool set_key_layer(int port_num, int key_layer)
{
    bool connect_flag;
    char port_buf[] = "\\\.\\COM1";
    sprintf(port_buf, "\\\.\\COM%d", port_num);
    if(com_init(port_buf))
    {
        connect_flag = send_key_state(key_layer);
        CloseHandle(hCom); //关闭串口
        return connect_flag;
    }
}

/**
 * com口初始化
 * 输入：
 *      字符串，\\\.\\COM20
 * 返回：
 *      bool型变量，操作是否成功
 * */
bool com_init(char* port)
{
    //CreateFile有两个分支函数，分别是CreateFileA和CreateFileW
    //这两个函数分别对应于char*型字符串和wchar_t*型字符串
    hCom=CreateFileA(port,//port口  
    GENERIC_READ|GENERIC_WRITE, //允许读和写  
    0, //独占方式  
    NULL,  
    OPEN_EXISTING, //打开而不是创建  
    0, //同步方式  
    NULL);  
    if(hCom==(HANDLE)-1)  
    {  
        qDebug("Open COM error!\n");  
        return FALSE;  
    }  
    SetupComm(hCom,1024,1024); //输入缓冲区和输出缓冲区的大小都是1024  
 
    COMMTIMEOUTS TimeOuts;  
    //设定读超时  
    TimeOuts.ReadIntervalTimeout=1000;  
    TimeOuts.ReadTotalTimeoutMultiplier=500;  
    TimeOuts.ReadTotalTimeoutConstant=5000;  
    //设定写超时  
    TimeOuts.WriteTotalTimeoutMultiplier=500;  
    TimeOuts.WriteTotalTimeoutConstant=2000;  
    SetCommTimeouts(hCom,&TimeOuts); //设置超时  
    
    DCB dcb;  
    GetCommState(hCom,&dcb);  
    dcb.BaudRate=9600; //波特率为9600  
    dcb.ByteSize=8; //每个字节有8位  
    dcb.Parity=NOPARITY; //无奇偶校验位  
    dcb.StopBits=ONESTOPBIT; //一个停止位  
    SetCommState(hCom,&dcb);  
    
    PurgeComm(hCom,PURGE_TXCLEAR|PURGE_RXCLEAR);
    return TRUE; 
}

/**
 * 发送键盘层数据
 * 输入：
 *      key_state 键盘层数，从0开始到19
 * 返回：
 *      bool型变量，操作是否成功
 * */
bool send_key_state(int key_state)
{
    //输入数据范围保护
    if(key_state < 0 || key_state >=20)
    {
        qDebug("Set Key State : Data Overflow\n");
        qDebug("Data Value : 0 ~ 19\n");
        return FALSE;
    }

    //串口写
    char lpOutBuffer = (char)key_state;  
    DWORD dwBytesWrite = 1;  
    COMSTAT ComStat;  
    DWORD dwErrorFlags;  
    BOOL bWriteStat;  
    ClearCommError(hCom,&dwErrorFlags,&ComStat);  
    bWriteStat=WriteFile(hCom,& lpOutBuffer,dwBytesWrite,& dwBytesWrite,NULL);  
    if(!bWriteStat)  
    {  
        qDebug("Set Key State : Write error\n"); 
        return FALSE;
    }

    //串口读设置反馈
    char Receive_data[10];  
    DWORD wCount;//读取的字节数  
    BOOL bReadStat;  
    bReadStat=ReadFile(hCom,Receive_data,10,&wCount,NULL);  
    if(!bReadStat)  
    {  
        qDebug("Set Key State : Read error\n");  
        return FALSE;  
    }
    
    //处理设置反馈以决定是否重新设置
    char Receive_data_buf[10];
    char str_buf[10];
    // printf("%s\n",Receive_data); //显示接收到的串口数据
    sscanf(Receive_data,"%*[^/]/%[^@]",Receive_data_buf); //返回格式为a/编号@a 从中分离编号内容
    // printf("%s\n",Receive_data_buf); //显示处理后的串口数据
    sprintf(str_buf,"%d",key_state); //将按键层格式化为字符串以便判断
    if(strcmp(Receive_data_buf,str_buf) == 0) //判断返回数据是否与目标设置相同
    {
        qDebug("Set Key State : Finish\n");
    }
    else
    {
        qDebug("Set Key State : Error & Reset\n");
        send_key_state(key_state);
    }

    //清串口缓存
    PurgeComm(hCom, PURGE_TXABORT|  
        PURGE_RXABORT|PURGE_TXCLEAR|PURGE_RXCLEAR);
    return TRUE;
}

/**
 * 遍历串口，找到目标设备所在串口号并返回串口号
 * 返回：
 *      int型，设备所在串口对应编号
 * */
int find_drive(void)
{
    int i = 1;
    char buf[] = "\\\.\\COM1";
    for(i = 1; i <= 20; i++)
    {
        qDebug("Find in COM%d : ", i);
        sprintf(buf,"\\\.\\COM%d",i);
        if(com_init(buf))
        {
            //串口写
            char lpOutBuffer = 200;  
            DWORD dwBytesWrite = 1;  
            COMSTAT ComStat;  
            DWORD dwErrorFlags;  
            BOOL bWriteStat;  
            ClearCommError(hCom,&dwErrorFlags,&ComStat);  
            bWriteStat=WriteFile(hCom,& lpOutBuffer,dwBytesWrite,& dwBytesWrite,NULL);  
            if(!bWriteStat)  
            {  
                qDebug("Find Drive : Write error\n"); 
                return 0;
            }

            //串口读设置反馈
            char Receive_data[10];  
            DWORD wCount;//读取的字节数  
            BOOL bReadStat;  
            bReadStat=ReadFile(hCom,Receive_data,10,&wCount,NULL);  
            if(!bReadStat)  
            {  
                qDebug("Find Drive : Read error\n");  
                return 0;  
            }

            //处理设置反馈以判断是否为目标设备
            char Receive_data_buf[10];
            sscanf(Receive_data,"%*[^/]/%[^@]",Receive_data_buf); //返回格式为a/ok@a 从中分离编号内容
            if(strcmp(Receive_data_buf,"ok") == 0) //判断返回数据是否与目标设置相同
            {
                qDebug("Find Drive in COM%d\n", i);
                //清串口缓存
                PurgeComm(hCom, PURGE_TXABORT|  
                    PURGE_RXABORT|PURGE_TXCLEAR|PURGE_RXCLEAR);
                CloseHandle(hCom); //关闭串口
                return i;
                
            }
            else
            {
                //清串口缓存
                PurgeComm(hCom, PURGE_TXABORT|  
                    PURGE_RXABORT|PURGE_TXCLEAR|PURGE_RXCLEAR);
                CloseHandle(hCom); //关闭串口
            }
        }
    }
}

bool getProcess(const char *procressName)                //此函数进程名不区分大小写
{
    char pName[MAX_PATH];                                //和PROCESSENTRY32结构体中的szExeFile字符数组保持一致，便于比较
    strcpy(pName,procressName);                            //拷贝数组
    CharLowerBuffA(pName,MAX_PATH);                        //将名称转换为小写
    PROCESSENTRY32 currentProcess;                        //存放快照进程信息的一个结构体
    currentProcess.dwSize = sizeof(currentProcess);        //在使用这个结构之前，先设置它的大小
    HANDLE hProcess = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);//给系统内的所有进程拍一个快照

    if (hProcess == INVALID_HANDLE_VALUE)
    {
        qDebug("CreateToolhelp32Snapshot()调用失败!\n");
        return false;
    }

    bool bMore=Process32First(hProcess,&currentProcess);        //获取第一个进程信息
    while(bMore)
    {
        CharLowerBuff(currentProcess.szExeFile,MAX_PATH);        //将进程名转换为小写
        string buf = WcharToChar(currentProcess.szExeFile);
        if (strcmp(buf.c_str(),pName)==0)            //比较是否存在此进程
        {
            CloseHandle(hProcess);                                //清除hProcess句柄
            return true;
        }
        bMore=Process32Next(hProcess,&currentProcess);            //遍历下一个
    }

    CloseHandle(hProcess);    //清除hProcess句柄
    return false;
}


std::wstring CharToWchar(const char* c, size_t m_encode)
{
    std::wstring str;
    int len = MultiByteToWideChar(m_encode, 0, c, strlen(c), NULL, 0);
    wchar_t*	m_wchar = new wchar_t[len + 1];
    MultiByteToWideChar(m_encode, 0, c, strlen(c), m_wchar, len);
    m_wchar[len] = '\0';
    str = m_wchar;
    delete m_wchar;
    return str;
}

std::string WcharToChar(const wchar_t* wp, size_t m_encode)
{
    std::string str;
    int len = WideCharToMultiByte(m_encode, 0, wp, wcslen(wp), NULL, 0, NULL, NULL);
    char	*m_char = new char[len + 1];
    WideCharToMultiByte(m_encode, 0, wp, wcslen(wp), m_char, len, NULL, NULL);
    m_char[len] = '\0';
    str = m_char;
    delete m_char;
    return str;
}

void save_setting(void)
{
    ofstream fp("setting");
    if(fp.is_open())
    {
        for(int i = 1; i < 20; i++)
        {
            fp << process_name[i] <<endl;
        }
        fp.close();
    }
    else
    {
        qDebug("Open file error");
    }
}

void read_setting(void)
{
    ifstream fp("setting");
    if(fp.is_open())
    {
        for(int i = 1; i < 20; i++)
        {
            getline(fp, process_name[i]);
        }
        fp.close();
    }
    else
    {
        qDebug("Build file");
        save_setting();
    }
}
