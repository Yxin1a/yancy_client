#ifndef __IPC_PROTOCOL_H__
#define __IPC_PROTOCOL_H__

#include <memory>
#include "../../tools/singleton.h"
#include "../../tools/list.h"

namespace yancy
{
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
    
    /**
     * @brief Ipc协议
     */
    class IpcProtocol
    {
    public:
        typedef std::shared_ptr<IpcProtocol> ptr;

        struct MsgInfo
        {
            IpcProtocolType::MsgType m_msg_type;
            IpcProtocolType::MsgFunc m_msg_func;
            std::string m_msg_data;
        };

        IpcProtocol();

        int parseMessage(const std::string& msg);

    private:
        void push_queue(MsgInfo* msgInfo);
        MsgInfo* pop_queue();

    private:
        /// @brief  互斥锁
        std::mutex m_mutex;
        /// @brief  消息队列
        MessageQueue<MsgInfo*>::ptr m_messageQueue;
    };

    typedef SingletonPtr<IpcProtocol> g_ipc_protocol;
}

#endif