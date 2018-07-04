//
// Created by Alex LAZAREV on 7/1/18.
//

#ifndef RUSH01_IUSER_HPP
#define RUSH01_IUSER_HPP

class IUser{

public:
	virtual						~IUser(){}
    virtual const char *getHost() const = 0;

    virtual const char *getUser() const = 0;
};

#endif //RUSH01_IUSER_HPP
