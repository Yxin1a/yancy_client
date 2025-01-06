#include "ipc_protocol.h"
#include "ipc_client.h"
#include <cjson/cJSON.h>

IpcProtocolType::MsgType IpcProtocolType::getMsgType(uint32_t msgType)
{
    return static_cast<IpcProtocolType::MsgType>(msgType);
}
uint32_t IpcProtocolType::getMsgTypeInt(MsgType msgType)
{
    return static_cast<uint32_t>(msgType);
}

IpcProtocolType::MsgFunc IpcProtocolType::getMsgFunc(uint32_t msgFunc)
{
    return static_cast<IpcProtocolType::MsgFunc>(msgFunc);
}
uint32_t IpcProtocolType::getMsgFuncInt(MsgFunc msgFunc)
{
    return static_cast<uint32_t>(msgFunc);
}

IpcProtocol::IpcProtocol(QObject *parent) : QObject(parent)
{

}

int IpcProtocol::parseMessage(const std::string& msg)
{
    cJSON* root = cJSON_Parse(msg.c_str());
    if (!root)
    {
        return -1;
    }

    cJSON* msgType = cJSON_GetObjectItem(root, "msg_type");
    if (!msgType)
    {
        cJSON_Delete(root);
        return -1;
    }
    uint32_t msgTypeInt = cJSON_GetNumberValue(msgType);

    cJSON* msgFunc = cJSON_GetObjectItem(root, "msg_func");
    if (!msgFunc)
    {
        cJSON_Delete(root);
        return -1;
    }
    uint32_t msgFuncInt = cJSON_GetNumberValue(msgFunc);

    MsgInfo * msgInfo = new MsgInfo();
    msgInfo->m_msg_type = IpcProtocolType::getMsgType(msgTypeInt);
    msgInfo->m_msg_func = IpcProtocolType::getMsgFunc(msgFuncInt);
    msgInfo->m_msg_data = msg;

    //处理消息
    parseProtocol(msgInfo);

    cJSON_Delete(root);
    return 0;
}

void IpcProtocol::parseProtocol(MsgInfo* msgInfo) // 解析协议
{
    switch (msgInfo->m_msg_type)
    {
    case IpcProtocolType::MsgType::MSG_TYPE_REQUEST:
        parseRequest(msgInfo);
        break;
    case IpcProtocolType::MsgType::MSG_TYPE_RESPONSE:
        parseResponse(msgInfo);
        break;
    case IpcProtocolType::MsgType::MSG_TYPE_REPORT:
        parseReport(msgInfo);
        break;
    default:
        break;
    }
}
void IpcProtocol::parseRequest(MsgInfo* msgInfo) // 解析请求
{
    // switch (msgInfo->m_msg_func)
    // {
    // case :
    //     break;
    
    // default:
    //     break;
    // }
}
void IpcProtocol::parseResponse(MsgInfo* msgInfo) // 解析响应
{
    // switch (msgInfo->m_msg_func)
    // {
    // case :
    //     break;
    
    // default:
    //     break;
    // }
}
void IpcProtocol::parseReport(MsgInfo* msgInfo) // 解析上报
{
    // switch (msgInfo->m_msg_func)
    // {
    // case :
    //     break;
    
    // default:
    //     break;
    // }
}