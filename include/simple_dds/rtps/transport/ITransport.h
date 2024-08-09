#pragma once

#include <string>

namespace simple_dds
{
namespace dds
{
class ITransportListener;

class TransportAttribute
{
    bool isMulticast;
};

class ITransport
{
public:
    using ID = std::uint64_t;

    virtual ~ITransport() = 0;

    virtual Send() = 0;

    virtual ID GetId() = 0;

    virtual void AddListener(ITransportListener *listener);
};

class ITransportListener
{
public:
    virtual ~ITransportListener() = default;

    virtual void OnReceived() = 0;

    virtual void OnConnected() = 0;

    virtual void OnDisconnected() = 0;
};
}
}