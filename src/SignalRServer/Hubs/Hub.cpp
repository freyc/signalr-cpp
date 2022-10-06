#include "Hub.h"
#include "HubSubscriberList.h"
#include "HubManager.h"

namespace P3 { namespace SignalR { namespace Server {

HubManager Hub::_hubManager;

Hub::Hub(const char* name)
{
    _hubName = name;
}

Hub::~Hub()
{

}


void Hub::onConnected()
{


}

void Hub::onReconnected()
{

}

void Hub::onDisconnected()
{

}

Json::Value Hub::onMessage(const char* , vector<Json::Value>& )
{

    return Json::Value();
}
const string &Hub::hubName() const
{
    return _hubName;
}

void Hub::handleConnected()
{
    onConnected();
}

void Hub::handleReconnected()
{
    onReconnected();
}

void Hub::handleDisconnected()
{
    onDisconnected();
}

Json::Value Hub::handleMessage(const char *functionName, vector<Json::Value>& params)
{
   return onMessage(functionName, params);
}

HubSubscriberList Hub::getClients()
{
    return getHubManager().getSubscribers().byHub(_hubName.c_str());
}

HubGroupList& Hub::getGroups()
{
    return getHubManager().getGroups();
}


}}}
