#ifndef IPC_CLIENT_H
#define IPC_CLIENT_H

#include <QObject>
#include <hv/TcpClient.h>
#include <string>

#include "../../tools/singleton.h"

class IpcClient : public QObject
{
    Q_OBJECT
public:
    explicit IpcClient(QObject *parent = nullptr);

    int init(int ipc_port);
    void close();
    // void start();
    // void stop();
    int sendMessage(const std::string& message);

private:
    void onConnection(const hv::SocketChannelPtr& channel);
    void onMessage(const hv::SocketChannelPtr& channel, hv::Buffer* msg);
    void onWriteComplete(const hv::SocketChannelPtr& channel, hv::Buffer* msg);

private:
    bool m_is_connected;
    int m_port;
    hv::TcpClient m_tcp_client;
    hv::SocketChannelPtr m_tcp_channel;
};

typedef SingletonPtr<IpcClient> g_ipc_client;

#endif // IPC_CLIENT_H
