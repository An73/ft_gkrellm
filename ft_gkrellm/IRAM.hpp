//
// Created by Alex LAZAREV on 7/1/18.
//

#ifndef RUSH01_IRAM_HPP
#define RUSH01_IRAM_HPP

#include <cstddef>

class IRAM{

public:
	virtual						~IRAM(){}
    virtual size_t              getRAMSize() const = 0;
    virtual const char          *getRAMUsed() const = 0;
    virtual const char          *getRAMWired() const = 0;
    virtual const char          *getRAMUnused() const = 0;
};

#endif //RUSH01_IRAM_HPP
