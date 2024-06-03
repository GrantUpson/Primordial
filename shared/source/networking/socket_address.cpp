#include "networking/socket_address.h"


SocketAddress::SocketAddress(uint8 a, uint8 b, uint8 c, uint8 d, uint16 port) {
    this->address = (a << 24) | (b << 16) | (c << 8) | d;
    this->port = port;
}


uint32 SocketAddress::GetAddress() const {
    return address;
}


uint8 SocketAddress::GetA() const {
    return (address >> 8) & 0xFF;
}


uint8 SocketAddress::GetB() const {
    return (address >> 16) & 0xFF;
}


uint8 SocketAddress::GetC() const {
    return (address >> 24) & 0xFF;
}


uint8 SocketAddress::GetD() const {
    return (address) & 0xFF;
}


uint16 SocketAddress::GetPort() const {
    return port;
}