//
// Created by Alex LAZAREV on 7/1/18.
//

#ifndef RUSH01_IOS_HPP
#define RUSH01_IOS_HPP

class IOS {

public:
	virtual				~IOS(){}
    virtual const char *getSysname() const = 0;

    virtual const char *getNodeName() const = 0;

    virtual const char *getRealese() const = 0;

    virtual const char *getVersion() const = 0;

    virtual const char *getMachine() const = 0;
};

#endif //RUSH01_IOS_HPP
