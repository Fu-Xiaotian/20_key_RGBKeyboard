#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "keyboard_win.h"
using namespace std;

#define TIMER_TIMEOUT 500

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QIcon icon = QIcon("rgb.png");
    this->setWindowIcon(icon);
    this->setWindowFlag(Qt::FramelessWindowHint);
    ui->COM_num->setNum(drive_port);
    ui->lineEdit_2->setText(QString::fromStdString(process_name[1]));
    ui->lineEdit_3->setText(QString::fromStdString(process_name[2]));
    ui->lineEdit_4->setText(QString::fromStdString(process_name[3]));
    ui->lineEdit_5->setText(QString::fromStdString(process_name[4]));
    ui->lineEdit_6->setText(QString::fromStdString(process_name[5]));
    ui->lineEdit_7->setText(QString::fromStdString(process_name[6]));
    ui->lineEdit_8->setText(QString::fromStdString(process_name[7]));
    ui->lineEdit_9->setText(QString::fromStdString(process_name[8]));
    ui->lineEdit_10->setText(QString::fromStdString(process_name[9]));
    ui->lineEdit_11->setText(QString::fromStdString(process_name[10]));
    ui->lineEdit_12->setText(QString::fromStdString(process_name[11]));
    ui->lineEdit_13->setText(QString::fromStdString(process_name[12]));
    ui->lineEdit_14->setText(QString::fromStdString(process_name[13]));
    ui->lineEdit_15->setText(QString::fromStdString(process_name[14]));
    ui->lineEdit_16->setText(QString::fromStdString(process_name[15]));
    ui->lineEdit_17->setText(QString::fromStdString(process_name[16]));
    ui->lineEdit_18->setText(QString::fromStdString(process_name[17]));
    ui->lineEdit_19->setText(QString::fromStdString(process_name[18]));
    ui->lineEdit_20->setText(QString::fromStdString(process_name[19]));
    //初始化托盘
    this->sysicon_init();
    //修改背景图片
    setAutoFillBackground(true);
    QPalette pal = this->palette();
    pal.setBrush(backgroundRole(), QPixmap("background.jpg"));
    setPalette(pal);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sysicon_init(void)
{
    //新建QSystemTrayIcon对象
    mSysTrayIcon = new QSystemTrayIcon(this);
    //新建托盘要显示的icon
    QIcon icon = QIcon("rgb.png");
    //将icon设到QSystemTrayIcon对象中
    mSysTrayIcon->setIcon(icon);
    //当鼠标移动到托盘上的图标时，会显示此处设置的内容
    mSysTrayIcon->setToolTip(QObject::trUtf8("键盘层自动控制程序"));
    //给QSystemTrayIcon添加槽函数
    connect(mSysTrayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,
           SLOT(on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason)));
    //建立托盘操作的菜单
    createActions();
    createMenu();
    //在系统托盘显示此对象
    mSysTrayIcon->show();
}

//计时器
MyTimer::MyTimer(QObject *parent)
    :QObject(parent)
{
    m_nTimerID = this->startTimer(TIMER_TIMEOUT);
}

MyTimer::~MyTimer()
{
    killTimer(m_nTimerID);
}

void MyTimer::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == m_nTimerID){
        handleTimeout();
    }
}

//定时器溢出事件处理函数
void MyTimer::handleTimeout()
{
    auto_layer_chang();
}

//按键事件
void MainWindow::on_pushButton_21_clicked()
{
    find_drive();
    ui->COM_num->setNum(drive_port);
}

void MainWindow::on_save_button_clicked()
{
    QString buf[20];
    //2
    if(ui->lineEdit_2->text().isEmpty())
    {
        process_name[1] = "nan";
    }
    else
    {
        QString buf = ui->lineEdit_2->text();
        process_name[1] = buf.toStdString();
    }

    //3
    if(ui->lineEdit_3->text().isEmpty())
    {
        process_name[2] = "nan";
    }
    else
    {
        QString buf = ui->lineEdit_3->text();
        process_name[2] = buf.toStdString();
    }

    //4
    if(ui->lineEdit_4->text().isEmpty())
    {
        process_name[3] = "nan";
    }
    else
    {
        QString buf = ui->lineEdit_4->text();
        process_name[3] = buf.toStdString();
    }

    //5
    if(ui->lineEdit_5->text().isEmpty())
    {
        process_name[4] = "nan";
    }
    else
    {
        QString buf = ui->lineEdit_5->text();
        process_name[4] = buf.toStdString();
    }

    //6
    if(ui->lineEdit_6->text().isEmpty())
    {
        process_name[5] = "nan";
    }
    else
    {
        QString buf = ui->lineEdit_6->text();
        process_name[5] = buf.toStdString();
    }

    //7
    if(ui->lineEdit_7->text().isEmpty())
    {
        process_name[6] = "nan";
    }
    else
    {
        QString buf = ui->lineEdit_7->text();
        process_name[6] = buf.toStdString();
    }

    //8
    if(ui->lineEdit_8->text().isEmpty())
    {
        process_name[7] = "nan";
    }
    else
    {
        QString buf = ui->lineEdit_8->text();
        process_name[7] = buf.toStdString();
    }

    //9
    if(ui->lineEdit_9->text().isEmpty())
    {
        process_name[8] = "nan";
    }
    else
    {
        QString buf = ui->lineEdit_9->text();
        process_name[8] = buf.toStdString();
    }
    //10
    if(ui->lineEdit_10->text().isEmpty())
    {
        process_name[9] = "nan";
    }
    else
    {
        QString buf = ui->lineEdit_10->text();
        process_name[9] = buf.toStdString();
    }

    //11
    if(ui->lineEdit_11->text().isEmpty())
    {
        process_name[10] = "nan";
    }
    else
    {
        QString buf = ui->lineEdit_11->text();
        process_name[10] = buf.toStdString();
    }

    //12
    if(ui->lineEdit_12->text().isEmpty())
    {
        process_name[11] = "nan";
    }
    else
    {
        QString buf = ui->lineEdit_12->text();
        process_name[11] = buf.toStdString();
    }

    //13
    if(ui->lineEdit_13->text().isEmpty())
    {
        process_name[12] = "nan";
    }
    else
    {
        QString buf = ui->lineEdit_13->text();
        process_name[12] = buf.toStdString();
    }

    //14
    if(ui->lineEdit_14->text().isEmpty())
    {
        process_name[13] = "nan";
    }
    else
    {
        QString buf = ui->lineEdit_14->text();
        process_name[13] = buf.toStdString();
    }

    //15
    if(ui->lineEdit_15->text().isEmpty())
    {
        process_name[14] = "nan";
    }
    else
    {
        QString buf = ui->lineEdit_15->text();
        process_name[14] = buf.toStdString();
    }

    //16
    if(ui->lineEdit_16->text().isEmpty())
    {
        process_name[15] = "nan";
    }
    else
    {
        QString buf = ui->lineEdit_16->text();
        process_name[15] = buf.toStdString();
    }

    //17
    if(ui->lineEdit_17->text().isEmpty())
    {
        process_name[16] = "nan";
    }
    else
    {
        QString buf = ui->lineEdit_17->text();
        process_name[16] = buf.toStdString();
    }

    //18
    if(ui->lineEdit_18->text().isEmpty())
    {
        process_name[17] = "nan";
    }
    else
    {
        QString buf = ui->lineEdit_18->text();
        process_name[17] = buf.toStdString();
    }

    //19
    if(ui->lineEdit_19->text().isEmpty())
    {
        process_name[18] = "nan";
    }
    else
    {
        QString buf = ui->lineEdit_19->text();
        process_name[18] = buf.toStdString();
    }

    //20
    if(ui->lineEdit_20->text().isEmpty())
    {
        process_name[19] = "nan";
    }
    else
    {
        QString buf = ui->lineEdit_20->text();
        process_name[19] = buf.toStdString();
    }
    save_setting();
}

void MainWindow::on_read_button_clicked()
{
    read_setting();
    ui->lineEdit_2->setText(QString::fromStdString(process_name[1]));
    ui->lineEdit_3->setText(QString::fromStdString(process_name[2]));
    ui->lineEdit_4->setText(QString::fromStdString(process_name[3]));
    ui->lineEdit_5->setText(QString::fromStdString(process_name[4]));
    ui->lineEdit_6->setText(QString::fromStdString(process_name[5]));
    ui->lineEdit_7->setText(QString::fromStdString(process_name[6]));
    ui->lineEdit_8->setText(QString::fromStdString(process_name[7]));
    ui->lineEdit_9->setText(QString::fromStdString(process_name[8]));
    ui->lineEdit_10->setText(QString::fromStdString(process_name[9]));
    ui->lineEdit_11->setText(QString::fromStdString(process_name[10]));
    ui->lineEdit_12->setText(QString::fromStdString(process_name[11]));
    ui->lineEdit_13->setText(QString::fromStdString(process_name[12]));
    ui->lineEdit_14->setText(QString::fromStdString(process_name[13]));
    ui->lineEdit_15->setText(QString::fromStdString(process_name[14]));
    ui->lineEdit_16->setText(QString::fromStdString(process_name[15]));
    ui->lineEdit_17->setText(QString::fromStdString(process_name[16]));
    ui->lineEdit_18->setText(QString::fromStdString(process_name[17]));
    ui->lineEdit_19->setText(QString::fromStdString(process_name[18]));
    ui->lineEdit_20->setText(QString::fromStdString(process_name[19]));
}

void MainWindow::on_setButton_2_clicked()
{
    if(ui->lineEdit_2->text().isEmpty())
    {
        process_name[1] = "nan";
    }
    else
    {
        QString buf = ui->lineEdit_2->text();
        process_name[1] = buf.toStdString();
    }
    save_setting();
}

void MainWindow::on_setButton_3_clicked()
{
    if(ui->lineEdit_3->text().isEmpty())
    {
        process_name[2] = "nan";
    }
    else
    {
        QString buf = ui->lineEdit_3->text();
        process_name[2] = buf.toStdString();
    }
    save_setting();
}

void MainWindow::on_setButton_4_clicked()
{
    if(ui->lineEdit_4->text().isEmpty())
    {
        process_name[3] = "nan";
    }
    else
    {
        QString buf = ui->lineEdit_4->text();
        process_name[3] = buf.toStdString();
    }
    save_setting();
}

void MainWindow::on_setButton_5_clicked()
{
    if(ui->lineEdit_5->text().isEmpty())
    {
        process_name[4] = "nan";
    }
    else
    {
        QString buf = ui->lineEdit_5->text();
        process_name[4] = buf.toStdString();
    }
    save_setting();
}

void MainWindow::on_setButton_6_clicked()
{
    if(ui->lineEdit_6->text().isEmpty())
    {
        process_name[5] = "nan";
    }
    else
    {
        QString buf = ui->lineEdit_6->text();
        process_name[5] = buf.toStdString();
    }
    save_setting();
}

void MainWindow::on_setButton_7_clicked()
{
    if(ui->lineEdit_7->text().isEmpty())
    {
        process_name[6] = "nan";
    }
    else
    {
        QString buf = ui->lineEdit_7->text();
        process_name[6] = buf.toStdString();
    }
    save_setting();
}

void MainWindow::on_setButton_8_clicked()
{
    if(ui->lineEdit_8->text().isEmpty())
    {
        process_name[7] = "nan";
    }
    else
    {
        QString buf = ui->lineEdit_8->text();
        process_name[7] = buf.toStdString();
    }
    save_setting();
}

void MainWindow::on_setButton_9_clicked()
{
    if(ui->lineEdit_9->text().isEmpty())
    {
        process_name[8] = "nan";
    }
    else
    {
        QString buf = ui->lineEdit_9->text();
        process_name[8] = buf.toStdString();
    }
    save_setting();
}

void MainWindow::on_setButton_10_clicked()
{
    if(ui->lineEdit_10->text().isEmpty())
    {
        process_name[9] = "nan";
    }
    else
    {
        QString buf = ui->lineEdit_10->text();
        process_name[9] = buf.toStdString();
    }
    save_setting();
}

void MainWindow::on_setButton_11_clicked()
{
    if(ui->lineEdit_11->text().isEmpty())
    {
        process_name[10] = "nan";
    }
    else
    {
        QString buf = ui->lineEdit_11->text();
        process_name[10] = buf.toStdString();
    }
    save_setting();
}

void MainWindow::on_setButton_12_clicked()
{
    if(ui->lineEdit_12->text().isEmpty())
    {
        process_name[11] = "nan";
    }
    else
    {
        QString buf = ui->lineEdit_12->text();
        process_name[11] = buf.toStdString();
    }
    save_setting();
}

void MainWindow::on_setButton_13_clicked()
{
    if(ui->lineEdit_13->text().isEmpty())
    {
        process_name[12] = "nan";
    }
    else
    {
        QString buf = ui->lineEdit_13->text();
        process_name[12] = buf.toStdString();
    }
    save_setting();
}

void MainWindow::on_setButton_14_clicked()
{
    if(ui->lineEdit_14->text().isEmpty())
    {
        process_name[13] = "nan";
    }
    else
    {
        QString buf = ui->lineEdit_14->text();
        process_name[13] = buf.toStdString();
    }
    save_setting();
}

void MainWindow::on_setButton_15_clicked()
{
    if(ui->lineEdit_15->text().isEmpty())
    {
        process_name[14] = "nan";
    }
    else
    {
        QString buf = ui->lineEdit_15->text();
        process_name[14] = buf.toStdString();
    }
    save_setting();
}

void MainWindow::on_setButton_16_clicked()
{
    if(ui->lineEdit_16->text().isEmpty())
    {
        process_name[15] = "nan";
    }
    else
    {
        QString buf = ui->lineEdit_16->text();
        process_name[15] = buf.toStdString();
    }
    save_setting();
}

void MainWindow::on_setButton_17_clicked()
{
    if(ui->lineEdit_17->text().isEmpty())
    {
        process_name[16] = "nan";
    }
    else
    {
        QString buf = ui->lineEdit_17->text();
        process_name[16] = buf.toStdString();
    }
    save_setting();
}

void MainWindow::on_setButton_18_clicked()
{
    if(ui->lineEdit_18->text().isEmpty())
    {
        process_name[17] = "nan";
    }
    else
    {
        QString buf = ui->lineEdit_18->text();
        process_name[17] = buf.toStdString();
    }
    save_setting();
}

void MainWindow::on_setButton_19_clicked()
{
    if(ui->lineEdit_19->text().isEmpty())
    {
        process_name[18] = "nan";
    }
    else
    {
        QString buf = ui->lineEdit_19->text();
        process_name[18] = buf.toStdString();
    }
    save_setting();
}

void MainWindow::on_setButton_20_clicked()
{
    if(ui->lineEdit_20->text().isEmpty())
    {
        process_name[19] = "nan";
    }
    else
    {
        QString buf = ui->lineEdit_20->text();
        process_name[19] = buf.toStdString();
    }
    save_setting();
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton) {
        m_point = e->globalPos() - pos();
        e->accept();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    if (e->buttons() & Qt::LeftButton) {
        move(e->globalPos() - m_point);
        e->accept();
    }
}

void MainWindow::on_Hide_button_clicked()
{
    //隐藏程序主窗口
    this->hide();
}

void MainWindow::on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason){
    case QSystemTrayIcon::Trigger:
        {
            //单击托盘图标
            int buf = 0;
            for(int i = 1; i < 20; i++)
            {
                if(process_state[i])
                {
                  buf = i;
                   break;
                }
                else
                {
                    buf = 0;
                }
            }
            if(buf)
            {
                mSysTrayIcon->showMessage(QObject::trUtf8("自动检测程序"),
                                                QObject::trUtf8("检测到目标进程运行，请查看键盘OLED"),
                                                QSystemTrayIcon::Information,
                                                1000);
            }
            else
            {
                mSysTrayIcon->showMessage(QObject::trUtf8("自动检测程序"),
                                                QObject::trUtf8("未检测到目标进程运行"),
                                                QSystemTrayIcon::Information,
                                                1000);
            }
        }
        break;
    default:
        break;
    }
}

void MainWindow::createActions()
{
    mShowMainAction = new QAction(QObject::trUtf8("显示主界面"),this);
    connect(mShowMainAction,SIGNAL(triggered()),this,SLOT(on_showMainAction()));

    mExitAppAction = new QAction(QObject::trUtf8("退出"),this);
    connect(mExitAppAction,SIGNAL(triggered()),this,SLOT(on_exitAppAction()));

}

void MainWindow::createMenu()
{
    mMenu = new QMenu(this);
    //新增菜单项---显示主界面
    mMenu->addAction(mShowMainAction);
    //增加分隔符
    mMenu->addSeparator();
    //新增菜单项---退出程序
    mMenu->addAction(mExitAppAction);
    //把QMenu赋给QSystemTrayIcon对象
    mSysTrayIcon->setContextMenu(mMenu);
}
/*
* 当在系统托盘点击菜单内的显示主界面操作
*/
void MainWindow::on_showMainAction()
{
    this->show();
}

/*
* 当在系统托盘点击菜单内的退出程序操作
*/
void MainWindow::on_exitAppAction()
{
    exit(0);
}
