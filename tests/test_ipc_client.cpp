#include <iostream>
#include "../src_gui/IPC/ipc_client.h"

int main()
{
    g_ipc_client::GetInstance()->init(5354);
    g_ipc_client::GetInstance()->sendMessage("hello world");
    g_ipc_client::GetInstance()->close();
    return 0;
}