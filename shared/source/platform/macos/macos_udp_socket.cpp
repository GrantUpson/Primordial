#include "networking/udp_socket.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include "networking/networking_utilities.h"


Networking::SocketStatus UDPSocket::Open(uint16 port) {
    handle = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    if(handle <= 0) {
        return Networking::CreationFailed;
    }

    sockaddr_in address {};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if(bind(handle, (const sockaddr*)&address, sizeof(sockaddr_in)) < 0) {
        return Networking::BindFailed;
    }

    if(fcntl(handle, F_SETFL, O_NONBLOCK, 1) == -1) {
        return Networking::SetNonBlockingFailed;
    }

    return Networking::Success;
}


Networking::SocketStatus UDPSocket::Close() const {
    return (close(handle) == 0) ? Networking::Success : Networking::ClosingConnectionFailed;
}


Networking::SocketStatus UDPSocket::Send(const SocketAddress& destination, const void* data, uint32 bufferSize) const {
    sockaddr_in address {};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(destination.GetAddress());
    address.sin_port = htons(destination.GetPort());

    size_t sentBytes = sendto(handle, data, bufferSize, 0, (sockaddr*)&address, sizeof(sockaddr_in));

    return (sentBytes != bufferSize) ? Networking::SendFailed : Networking::Success;
}


uint32 UDPSocket::Receive(SocketAddress& sender, void* data, uint32 bufferSize) const {
    sockaddr_in from {};
    socklen_t fromLength = sizeof(from);
    uint32 bytes = recvfrom(handle, data, bufferSize, 0, (sockaddr*)&from, &fromLength);

    // 'Generally' indicates that there is nothing to receive atm if the value is -1
    if(bytes == -1) {
        bytes = 0;
    }

    return bytes;
}


UDPSocket::~UDPSocket() {
    Close();
}