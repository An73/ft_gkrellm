//
// Created by Alex LAZAREV on 6/30/18.
//

#ifndef RUSH01_CPU_H
#define RUSH01_CPU_H

#include <string>
#include "ICPU.hpp"

class CPU : public ICPU{

private:
    std::string         model;
    size_t              core_count;
    char                *buf;

public:
                        CPU();
                        CPU(CPU const &obj);
    virtual             ~CPU();
    const char          *getModel() const;
    size_t              getCore_count() const;
    size_t              getClockSpeed() const;
    const char          *getProcessCount() const;
    const char          *getActivities() const;
    CPU &operator=(CPU const &src);
};


#endif //RUSH01_CPU_H
