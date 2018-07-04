//
// Created by Alex LAZAREV on 7/1/18.
//

#ifndef RUSH01_ICPU_HPP
#define RUSH01_ICPU_HPP

#include <stdio.h>

class ICPU{

public:
	virtual						~ICPU(){}
    virtual const char          *getModel() const = 0;
    virtual size_t              getCore_count() const = 0;
    virtual size_t              getClockSpeed() const = 0;
    virtual const char          *getProcessCount() const = 0;
    virtual const char          *getActivities() const = 0;
};

#endif //RUSH01_ICPU_HPP
