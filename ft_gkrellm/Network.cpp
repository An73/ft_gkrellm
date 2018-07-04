//
// Created by Alex LAZAREV on 6/30/18.
//

#include "Network.hpp"

Network::Network() {
    buf = new char(NETWORK_BUF_SIZE);
}

Network::~Network() {
    delete buf;
}

const char *Network::getPacketsIn() const {
    FILE* top = popen("top -l 1 | grep \"Networks\" | cut -d' ' -f3", "r");
    if (top)
        fgets(buf, NETWORK_BUF_SIZE, top);
    pclose(top);
    return buf;
}

const char *Network::getPacketsOut() const {
    FILE* top = popen("top -l 1 | grep \"Networks\" | cut -d' ' -f5", "r");
    if (top)
        fgets(buf, NETWORK_BUF_SIZE, top);
    pclose(top);
    return buf;
}

Network::Network(Network const &obj) {
    *this = obj;
}

Network &Network::operator=(Network const &src) {
    if (this != &src)
        for(int i = 0; i < NETWORK_BUF_SIZE; i++)
            buf[i] = src.buf[i];
    return *this;
}
