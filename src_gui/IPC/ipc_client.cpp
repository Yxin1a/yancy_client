#include "ipc_client.h"
#include "ipc_protocol.h"

#include <iostream>

IpcClient::IpcClient(QObject *parent) 
    : QObject(parent)
{

}

int IpcClient::init(int ipc_port)
{
    m_is_connected = false;
    m_port = ipc_port;
    int connfd = m_tcp_client.createsocket(ipc_port);
    if (connfd < 0)
    {
        return -20;
    }

    m_tcp_client.onConnection = std::bind(&IpcClient::onConnection, this, std::placeholders::_1);
    m_tcp_client.onMessage = std::bind(&IpcClient::onMessage, this, std::placeholders::_1, std::placeholders::_2);
    m_tcp_client.onWriteComplete = std::bind(&IpcClient::onWriteComplete, this, std::placeholders::_1, std::placeholders::_2);

    unpack_setting_t unpack_setting;
    memset((void *)&unpack_setting, 0, sizeof(unpack_setting_t));
    unpack_setting.package_max_length = DEFAULT_PACKAGE_MAX_LENGTH;
    unpack_setting.mode = UNPACK_BY_DELIMITER;
    unpack_setting.delimiter[0] = '\r';
    unpack_setting.delimiter[1] = '\n';
    unpack_setting.delimiter_bytes = 2;
    m_tcp_client.setUnpack(&unpack_setting);

    // reconnect: 1,2,4,8,10,10,10...
    reconn_setting_t reconn;
    reconn_setting_init(&reconn);
    reconn.min_delay = 1000;
    reconn.max_delay = 10000;
    reconn.delay_policy = 2;
    m_tcp_client.setReconnect(&reconn);

    m_tcp_client.start();
}

void IpcClient::close()
{
    m_tcp_client.stop();
    m_tcp_client.closesocket();
}

int IpcClient::sendMessage(const std::string &message)
{
    int retval = 0;
    if(m_tcp_channel!= nullptr)
    {
        retval = m_tcp_channel->write(message.c_str(), message.length());
    }
    else
    {
        retval = -1;
        std::cout << "m_tcp_channel is null" << std::endl;
    }
    return retval;
}

void IpcClient::onConnection(const hv::SocketChannelPtr& channel)
{
    std::string localaddr = channel->localaddr();
    std::string peeraddr = channel->peeraddr();

    if(channel->isConnected())
    {
        m_tcp_channel = channel;
        m_is_connected = true;
        std::cout << "连接成功 " << peeraddr << std::endl;
    }
    else
    {
        m_tcp_channel = nullptr;
        std::cout << "连接失败 " << peeraddr << std::endl;
    }

    if(m_tcp_client.isReconnect())
    {
        std::cout << "正在重连 " << peeraddr << std::endl;
    }
}
void IpcClient::onMessage(const hv::SocketChannelPtr& channel, hv::Buffer* msg)
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
void IpcClient::onWriteComplete(const hv::SocketChannelPtr& channel, hv::Buffer* msg)
{
    std::cout<<"onWriteComplete发送成功"<<msg->data()<<std::endl;
}
