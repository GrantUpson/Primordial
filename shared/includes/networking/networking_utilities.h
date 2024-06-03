#ifndef PRIMORDIAL_NETWORKING_UTILITIES_H
#define PRIMORDIAL_NETWORKING_UTILITIES_H

#include "types.h"


namespace Networking {
    enum SocketStatus : uint8 {
        Success =                   0,
        CreationFailed =            1,
        BindFailed =                2,
        SetNonBlockingFailed =      3,
        AddressResolutionFailed =   4,
        InvalidAddress =            5,
        NetworkUnreachable =        6,
        SendFailed =                7,
        ReceiveFailed =             8,
        ConnectionClosed =          9,
        ClosingConnectionFailed =   10,
        Timeout =                   11,
    };

    uint32 StringToIPAddress(std::string& stringIPAddress);
}


#endif
