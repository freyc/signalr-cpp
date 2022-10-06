#include "HubClientMessage.h"

namespace P3 { namespace SignalR { namespace Server {

HubClientMessage::HubClientMessage(const char *hub, const char *func, Json::Value &args)
    : ClientMessage(func, args)
{
    _hubName = hub;
}
string HubClientMessage::hubName() const
{
    return _hubName;
}

Json::Value HubClientMessage::toMap() const
{
#if 1
    return Json::Value();
#else
    VariantMap message = ClientMessage::toMap();
    message.insert(VARIANT_PAIR("H", std::string(hubName())));
    return message;
#endif
}

}}}
