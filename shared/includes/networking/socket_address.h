#ifndef PRIMORDIAL_SOCKET_ADDRESS_H
#define PRIMORDIAL_SOCKET_ADDRESS_H

#include "types.h"


class SocketAddress {
public:
    SocketAddress() = default;
    SocketAddress(uint8 a, uint8 b, uint8 c, uint8 d, uint16 port);
    SocketAddress(uint32 address, uint16 port) : address(address), port(port) {};

    uint32 GetAddress() const;
    uint8 GetA() const;
    uint8 GetB() const;
    uint8 GetC() const;
    uint8 GetD() const;
    uint16 GetPort() const;

private:
    uint32 address;
    uint16 port;
};


#endif
