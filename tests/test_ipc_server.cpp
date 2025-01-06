#include <iostream>
#include "../src_server/IPC/ipc_server.h"
int main()
{
    yancy::g_ipc_server::GetInstance()->init(5354);
    yancy::g_ipc_server::GetInstance()->start();
    
    return 0;
}