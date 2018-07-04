//
// Created by Alex LAZAREV on 6/30/18.
//

#ifndef RUSH01_NETWORK_HPP
#define RUSH01_NETWORK_HPP


#include <string>
#include "Defines.hpp"
#include "INetwork.hpp"

class Network : public INetwork{

private:
    char *buf;

public:
                Network();
                Network(Network const &obj);
    virtual     ~Network();
    const char  *getPacketsIn() const;
    const char  *getPacketsOut() const;

    Network &operator=(Network const &src);
};


#endif //RUSH01_NETWORK_HPP
