#ifndef IPC_PROTOCOL_H
#define IPC_PROTOCOL_H

#include <QObject>
#include "../../tools/singleton.h"

/**
 * @brief IPC协议类型
 */
class IpcProtocolType
{
public:
    enum class MsgType
    {
        MSG_TYPE_UNKNOWN,   // 0未知消息
        MSG_TYPE_REQUEST,   // 1请求消息
        MSG_TYPE_RESPONSE,  // 2响应消息
        MSG_TYPE_REPORT     // 3上报消息
    };

    enum class MsgFunc
    {
        MSG_FUNC_UNKNOWN,   // 未知
        MSG_FUNC_LOGIN,     // 登录
        MSG_FUNC_LOGOUT     // 登出
    };

    static MsgType getMsgType(uint32_t msgType);
    static uint32_t getMsgTypeInt(MsgType msgType);

    static MsgFunc getMsgFunc(uint32_t msgFunc);
    static uint32_t getMsgFuncInt(MsgFunc msgFunc);
};

class IpcProtocol : public QObject
{
    Q_OBJECT
public:
    explicit IpcProtocol(QObject *parent = nullptr);

    struct MsgInfo
    {
        MsgInfo() 
            : m_msg_type(IpcProtocolType::MsgType::MSG_TYPE_UNKNOWN)
            , m_msg_func(IpcProtocolType::MsgFunc::MSG_FUNC_UNKNOWN)
        {}

        IpcProtocolType::MsgType m_msg_type;
        IpcProtocolType::MsgFunc m_msg_func;
        std::string m_msg_data;
    };

    int parseMessage(const std::string& msg); // 解析消息头部

    void parseProtocol(MsgInfo* msgInfo); // 解析协议

    void parseRequest(MsgInfo* msgInfo); // 解析请求

    void parseResponse(MsgInfo* msgInfo); // 解析响应

    void parseReport(MsgInfo* msgInfo); // 解析上报

    void sendMessage(const std::string& msg); // 发送消息

signals:

public slots:
};

typedef SingletonPtr<IpcProtocol> g_ipc_protocol;

#endif // IPC_PROTOCOL_H
