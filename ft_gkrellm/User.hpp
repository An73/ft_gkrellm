//
// Created by Alex LAZAREV on 6/30/18.
//

#ifndef RUSH01_HOSTUSERMODULE_H
#define RUSH01_HOSTUSERMODULE_H

#include "Defines.hpp"
#include "IUser.hpp"

class User : public IUser{

private:
    char    host[HOST_NAME_SIZE];
    char    user[USER_NAME_SIZE];

public:
                User();
                User(User const &obj);
    virtual     ~User();
    const char  *getHost() const;

    const char  *getUser() const;

    User &operator=(User const &src);
};


#endif //RUSH01_HOSTUSERMODULE_H
