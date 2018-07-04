//
// Created by Alex LAZAREV on 6/30/18.
//

#include "OS.hpp"

const char *OS::getSysname() const {
    return uts->sysname;
}

const char *OS::getNodeName() const {
    return uts->nodename;
}

const char *OS::getRealese() const {
    return uts->release;
}

const char *OS::getVersion() const {
    return uts->version;
}

const char *OS::getMachine() const {
    return uts->machine;
}

OS::OS() {
    uts = new utsname();
    uname(uts);
}

OS::~OS() {
    delete uts;
}

OS::OS(OS const &obj) {
    *this = obj;
}

OS &OS::operator=(OS const &src) {
    if (this != &src)
        uts = src.uts;
    return *this;
}
