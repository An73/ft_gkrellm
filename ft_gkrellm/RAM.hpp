//
// Created by Alex LAZAREV on 6/30/18.
//

#ifndef RUSH01_RAM_HPP
#define RUSH01_RAM_HPP


#include "Defines.hpp"
#include "IRAM.hpp"

class RAM : public IRAM{

private:
    size_t              size;
    char                *buf;

public:
                        RAM();
                        RAM(RAM const & obj);
    virtual             ~RAM();

    size_t getRAMSize() const;

    const char *getRAMUsed() const;

    const char *getRAMWired() const;

    const char *getRAMUnused() const;

    RAM &operator=(RAM const &src);

};


#endif //RUSH01_RAM_HPP
