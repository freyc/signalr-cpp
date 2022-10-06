/*
 * Copyright (c) 2014, p3root - Patrik Pfaffenbauer (patrik.pfaffenbauer@p3.co.at) and
 * Norbert Kleininger
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */


#ifndef HUB_H
#define HUB_H

#include <strings.h>
#include <vector>
#include <json/value.h>
#include "HubSubscriberList.h"
#include "HubGroupList.h"
#include "PersistentConnection.h"
#include "Request.h"

#define P3_MACROSTR(k) #k

using namespace std;
namespace P3 { namespace SignalR { namespace Server {

class HubManager;

class Hub
{
public:
    Hub(const char* name);
    virtual ~Hub();

protected:
    virtual void onConnected();
    virtual void onReconnected();
    virtual void onDisconnected();
    virtual Json::Value onMessage(const char* functionName, vector<Json::Value>& params);

    static HubManager _hubManager;

public:
    string _hubName; //TODO: remove and add getter setter
    PersistentConnection* _pConnection;
    Request* _pRequest;

public:
    void handleConnected();
    void handleReconnected();
    void handleDisconnected();
    Json::Value handleMessage(const char* functionName, vector<Json::Value>& params);

public:
    static HubManager& getHubManager() { return _hubManager; }
    HubSubscriberList getClients();
    HubGroupList& getGroups();
    const string &hubName() const;
    std::string connectionId() { return _pConnection->_connectionId; }
};

}}}
#endif // HUB_H
