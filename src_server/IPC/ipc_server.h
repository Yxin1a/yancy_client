#ifndef __IPC_SERVER_H__
#define __IPC_SERVER_H__

#include <memory>
#include <string>

#include "../../tools/singleton.h"
#include "../../tools/thread.h"

#include <hv/TcpServer.h>

namespace yancy
{
    /**
     * @brief IPC服务器
     */
    class IpcServer
    {
    public:
        std::shared_ptr<IpcServer> ptr;
        
        int init(int port);
        void start();
        void stop();
        
        void sendMessage(const std::string& message);

        IpcServer();

    private:

        void onConnect(const hv::SocketChannelPtr& channel);
        void onMessage(const hv::SocketChannelPtr& channel, hv::Buffer* msg);
        void onWriteComplete(const hv::SocketChannelPtr& channel, hv::Buffer* msg);
        /**
         * @brief 线程函数
         *      另开一条线程来执行服务器，避免阻塞主线程
         */
        void thread();

    private:
        /// 端口
        int m_port;
        yancy::Thread<IpcServer> m_thread;
        hv::TcpServer m_tcp_Server;
        hv::SocketChannelPtr m_tcp_channel;
    };

    typedef SingletonPtr<yancy::IpcServer> g_ipc_server;
}

#endif // __IPC_SERVER_H__