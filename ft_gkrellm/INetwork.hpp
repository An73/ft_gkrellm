//
// Created by Alex LAZAREV on 7/1/18.
//

#ifndef RUSH01_INETWORK_HPP
#define RUSH01_INETWORK_HPP

class   INetwork{

public:
	virtual		~INetwork(){}
    virtual const char *getPacketsIn() const = 0;
    virtual const char *getPacketsOut() const = 0;
};

#endif //RUSH01_INETWORK_HPP
