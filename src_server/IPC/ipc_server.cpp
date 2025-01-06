#include "ipc_server.h"
#include "ipc_protocol.h"
#include <functional>
#include <iostream>

namespace yancy
{
    int IpcServer::init(int port)
    {
        m_port = port;
        int listenfd = m_tcp_Server.createsocket(port);
        if (listenfd < 0)
        {
            return -20;
        }

        m_tcp_Server.onConnection = std::bind(&IpcServer::onConnect, this, std::placeholders::_1);
        m_tcp_Server.onMessage = std::bind(&IpcServer::onMessage, this, std::placeholders::_1, std::placeholders::_2);
        m_tcp_Server.onWriteComplete = std::bind(&IpcServer::onWriteComplete, this, std::placeholders::_1, std::placeholders::_2);

        m_tcp_Server.setThreadNum(3); // 设置线程数量
    }

    void IpcServer::start()
    {
        if(!m_thread.running())
        {
            m_thread.start();
        }
    }

    void IpcServer::stop()
    {
        if(m_thread.running())
        {
            m_thread.stop();
            m_thread.wait();
        }
    }
    
    void IpcServer::sendMessage(const std::string& message)
    {
        if(m_tcp_channel)
        {
            m_tcp_channel->write(message);
        }
        else
        {
            std::cout << "no client connected" << std::endl;
        }
    }

    IpcServer::IpcServer()
        :m_thread(this,&IpcServer::thread)
    {}

    void IpcServer::onConnect(const hv::SocketChannelPtr& channel)
    {
        std::string peeraddr = channel->peeraddr();
        if (channel->isConnected())
        {
            std::cout << "client connected: " << peeraddr << std::endl;
            m_tcp_channel = channel;
        }
        else
        {
            std::cout << "client disconnected: " << peeraddr << std::endl;
            m_tcp_channel = nullptr;
        }
    }

    void IpcServer::onMessage(const hv::SocketChannelPtr& channel, hv::Buffer* msg)
    {
        std::cout << "onMessage: "<<msg->data()<<std::endl;
        m_tcp_channel = channel;
        std::string msg_str((char *)msg->data(), msg->size());
        if(g_ipc_protocol::GetInstance()->parseMessage(msg_str)<0)
        {
            //解析失败
            channel->write("msg error");
        }
    }

    void IpcServer::onWriteComplete(const hv::SocketChannelPtr& channel, hv::Buffer* msg)
    {
        std::cout<<"onWriteComplete发送成功"<<msg->data()<<std::endl;
    }

    void IpcServer::thread()
    {
        m_tcp_Server.start();
    }

}