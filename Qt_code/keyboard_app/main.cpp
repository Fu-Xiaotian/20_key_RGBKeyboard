#include "mainwindow.h"
#include <QApplication>
#include "keyboard_win.h"

int main(int argc, char *argv[])
{
    process_name_init();
    drive_port = find_drive();
    read_setting();

    QApplication a(argc, argv);
    MainWindow w;
    MyTimer t1;
    w.show();

    return a.exec();
}
