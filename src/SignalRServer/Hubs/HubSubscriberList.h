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


#ifndef HUBSUBSCRIBERLIST_H
#define HUBSUBSCRIBERLIST_H

#include <string>
#include "Messaging/SubscriberList.h"

using namespace std;
namespace P3 { namespace SignalR { namespace Server {

class Hub;

class HubSubscriberList : public SubscriberList
{
public:
    HubSubscriberList allExcept(const char* connectionId);
    HubSubscriberList group(const char* group);
    HubSubscriberList groups(std::vector<std::string>& groups);
    HubSubscriberList othersInGroup(Hub* hub,const char* g);
    HubSubscriberList othersInGroups(Hub* hub,std::vector<std::string>& groups);
    HubSubscriberList clients(std::vector<std::string>& connectionIds);
    HubSubscriberList client(const char* connectionId);
    HubSubscriberList byHub(const char* hubName);
    bool contains(Subscriber *s);
    bool exists(const char* hubName, const char* connectionId);
    void send(const char *hub, const char *func, Json::Value &args);
    void send(Hub *h, const char* func, Json::Value& args);
    void subscribe(const char* hubName, const char* connectionId);
    void unsubscribe(const char* connectionId);
    std::string generateKey();
};

}}}
#endif // HUBSUBSCRIBERLIST_H
