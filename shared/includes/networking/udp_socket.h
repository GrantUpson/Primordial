#ifndef PRIMORDIAL_UDP_SOCKET_H
#define PRIMORDIAL_UDP_SOCKET_H

#include "types.h"
#include "socket_address.h"
#include "networking_utilities.h"


class UDPSocket {
public:
    UDPSocket() = default;
    ~UDPSocket();

    Networking::SocketStatus Open(uint16 port);
    Networking::SocketStatus Close() const;

    Networking::SocketStatus Send(const SocketAddress& destination, const void* data, uint32 bufferSize) const;
    uint32 Receive(SocketAddress& sender, void* data, uint32 bufferSize) const;

private:
    int handle;
};


#endif
