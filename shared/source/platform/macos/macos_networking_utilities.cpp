#include "networking/networking_utilities.h"
#include <arpa/inet.h>


namespace Networking {

    uint32 StringToIPAddress(std::string& stringIPAddress) {
        struct in_addr addr {};
        inet_pton(AF_INET, stringIPAddress.c_str(), &addr);

        return ntohl(addr.s_addr);
    }

}