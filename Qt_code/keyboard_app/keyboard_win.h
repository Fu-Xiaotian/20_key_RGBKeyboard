#ifndef __KEYBOARD_WIN_H
#define __KEYBOARD_WIN_H

#include <iostream>
#include "windows.h"
#include "string.h"
#include <tlhelp32.h>    //进程快照函数头文件
#include <fstream>


extern HANDLE hCom;
extern int drive_port;
extern std::string process_name[20];
extern int process_on_num;
extern bool process_state[20];
extern bool old_process_state[20];

void process_name_init(void);
bool auto_layer_chang(void);
/**
 * 向目标串口号写键盘层设置
 * 输入：
 *      port_num : 串口编号
 *      key_layer ： 键盘层编号（层数-1）
 * */
bool set_key_layer(int port_num, int key_layer);
/**
 * com口初始化
 * 输入：
 *      Unicode编码字符串，\\\.\\COM20
 * 返回：
 *      bool型变量，操作是否成功
 * */
bool com_init(char* port);
/**
 * 发送键盘层数据
 * 输入：
 *      key_state 键盘层数，从0开始到19
 * 返回：
 *      bool型变量，操作是否成功
 * */
bool send_key_state(int key_state);
/**
 * 遍历串口，找到目标设备所在串口号并返回串口号
 * 返回：
 *      int型，设备所在串口对应编号
 * */
int find_drive(void);
bool getProcess(const char *procressName);
std::wstring CharToWchar(const char* c, size_t m_encode = CP_ACP);
std::string WcharToChar(const wchar_t* wp, size_t m_encode = CP_ACP);
void save_setting(void);
void read_setting(void);

#endif
