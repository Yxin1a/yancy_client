#include "mainwindow.h"
#include <QApplication>
#include "IPC/ipc_client.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    g_ipc_client::GetInstance()->init(5354);
    g_ipc_client::GetInstance()->sendMessage("hello world");
    g_ipc_client::GetInstance()->close();

    w.show();

    return a.exec();
}
