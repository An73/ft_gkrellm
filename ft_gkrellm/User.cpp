//
// Created by Alex LAZAREV on 6/30/18.
//

#include "User.hpp"
#include <unistd.h>

User::User() {
    gethostname(host, HOST_NAME_SIZE);
    getlogin_r(user, USER_NAME_SIZE);
}

const char *User::getHost() const {
    return host;
}

const char *User::getUser() const {
    return user;
}

User::User(User const &obj) {
    *this = obj;
}

User::~User() {

}

User &User::operator=(User const &src) {
    if (this != &src) {
        for (int i = 0; i < HOST_NAME_SIZE; i++)
            host[i] = src.host[i];
        for (int i = 0; i < USER_NAME_SIZE; i++)
            user[i] = src.user[i];
    }
    return *this;
}
