#include "ClientMessage.h"
#include "Helper.h"

namespace P3 { namespace SignalR { namespace Server {

ClientMessage::ClientMessage(const char* func, Json::Value& args)
{
    _clientMethod = func;
    _arguments = args;
    _messageId = -1;
}


ClientMessage::~ClientMessage()
{
}

const string &ClientMessage::clientMethod() const
{
    return _clientMethod;
}

const Json::Value &ClientMessage::arguments() const
{
    return _arguments;
}

Json::Value ClientMessage::toMap() const
{
#if 1
    Json::Value message;
    message["M"] = std::string(clientMethod());
    message["A"] = arguments();
    return message;
#else
    VariantMap message;
    message.insert(VARIANT_PAIR("M", std::string(clientMethod())));
    message.insert(VARIANT_PAIR("A", arguments()));
    return message;
#endif
}

}}}
