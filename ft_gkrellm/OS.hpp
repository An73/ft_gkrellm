//
// Created by Alex LAZAREV on 6/30/18.
//

#ifndef RUSH01_OS_HPP
#define RUSH01_OS_HPP


#include <sys/utsname.h>
#include "IOS.hpp"

class OS : public IOS{

private:
    utsname     *uts;

public:
                OS();
                OS(OS const &obj);
    virtual     ~OS();
    const char  *getSysname() const;

    const char  *getNodeName() const;

    const char  *getRealese() const;

    const char  *getVersion() const;

    const char  *getMachine() const;

    OS &operator=(OS const &src);
};


#endif //RUSH01_OS_HPP
