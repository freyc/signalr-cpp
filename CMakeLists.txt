cmake_minimum_required(VERSION 3.0)
project(signalr-server-cpp CXX)

add_library(signalr-cpp-server 
    src/SignalRServer/SignalRServer.cpp 
    src/SignalRServer/PersistentConnection.cpp 
    src/SignalRServer/Request.cpp 
    src/SignalRServer/PersistentConnectionFactory.cpp 
    src/SignalRServer/Helper.cpp 
    src/SignalRServer/Log.cpp 
    src/SignalRServer/Hubs/HubDispatcher.cpp 
    src/SignalRServer/Hubs/Hub.cpp 
    src/SignalRServer/Hubs/HubFactory.cpp 
    src/SignalRServer/Messaging/ClientMessage.cpp 
    src/SignalRServer/Hubs/HubSubscriber.cpp 
    src/SignalRServer/Hubs/HubManager.cpp 
    src/SignalRServer/Messaging/SubscriberList.cpp 
    src/SignalRServer/Transports/Transport.cpp 
    src/SignalRServer/Transports/LongPollingTransport.cpp 
    src/SignalRServer/Messaging/Subscriber.cpp 
    src/SignalRServer/Hubs/HubSubscriberList.cpp 
    src/SignalRServer/Hubs/HubClientMessage.cpp 
    src/SignalRServer/Hubs/HubGroupList.cpp 
    src/SignalRServer/Hubs/Group.cpp 
    src/SignalRServer/GarbageCollector.cpp 
    src/SignalRServer/Transports/ServerSentEventsTransport.cpp
)

target_include_directories(signalr-cpp-server PUBLIC src/SignalRServer)
target_link_libraries(signalr-cpp-server PUBLIC CONAN_PKG::jsoncpp uuid)