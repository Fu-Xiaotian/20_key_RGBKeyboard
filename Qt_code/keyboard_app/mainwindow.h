#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "keyboard_win.h"
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QTimerEvent>
#include <QMouseEvent>
#include <QIcon>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void createActions();
    void createMenu();

private slots:
    void sysicon_init(void);

    void on_pushButton_21_clicked();

    void on_setButton_2_clicked();

    void on_save_button_clicked();

    void on_read_button_clicked();

    void on_setButton_3_clicked();

    void on_setButton_4_clicked();

    void on_setButton_5_clicked();

    void on_setButton_6_clicked();

    void on_setButton_7_clicked();

    void on_setButton_8_clicked();

    void on_setButton_9_clicked();

    void on_setButton_10_clicked();

    void on_setButton_11_clicked();

    void on_setButton_12_clicked();

    void on_setButton_13_clicked();

    void on_setButton_14_clicked();

    void on_setButton_15_clicked();

    void on_setButton_16_clicked();

    void on_setButton_17_clicked();

    void on_setButton_18_clicked();

    void on_setButton_19_clicked();

    void on_setButton_20_clicked();

    void on_Hide_button_clicked();

    void on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason);

    void on_showMainAction();

    void on_exitAppAction();

private:
    Ui::MainWindow *ui;
    QPoint m_point;
    QSystemTrayIcon *mSysTrayIcon;
    QMenu *mMenu;
    QAction *mShowMainAction;
    QAction *mExitAppAction;
protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
};

class MyTimer : public QObject
{
    Q_OBJECT

public:
    MyTimer(QObject* parent = NULL);
    ~MyTimer();
    void  handleTimeout();  //超时处理函数
    virtual void timerEvent( QTimerEvent *event);
private:
    int m_nTimerID;
};

#endif // MAINWINDOW_H
