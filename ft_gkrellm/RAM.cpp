//
// Created by Alex LAZAREV on 6/30/18.
//

#include <sys/sysctl.h>
#include <iostream>
#include "RAM.hpp"

RAM::RAM() {
    size_t len;
    len = sizeof(size);
    sysctlbyname("hw.memsize", &size, &len, NULL, 0);
    buf = new char(RAM_BUF_SIZE);
}

RAM::~RAM() {
}

RAM::RAM(RAM const &obj) {
    *this = obj;
}

RAM &RAM::operator=(RAM const &src) {
    if (this != &src) {
        size = src.size;
        for (int i = 0; i < RAM_BUF_SIZE; i++)
            buf[i] = src.buf[i];
    }
    return *this;
}

size_t RAM::getRAMSize() const {
    return size;
}

const char *RAM::getRAMUsed() const {
    FILE* top = popen("top -l 1 | grep \"PhysMem\" | cut -d'(' -f 1 | cut -d' ' -f 2", "r");
    if (top)
        fgets(buf, RAM_BUF_SIZE, top);
    pclose(top);
    return buf;
}

const char *RAM::getRAMWired() const {
    FILE* top = popen("top -l 1 | grep \"PhysMem\" | cut -d' ' -f 4", "r");
    if (top)
        fgets(buf, RAM_BUF_SIZE, top);
    pclose(top);
    return buf;
}

const char *RAM::getRAMUnused() const {
    FILE* top = popen("top -l 1 | grep \"PhysMem\" | cut -d' ' -f 6", "r");
    if (top)
        fgets(buf, RAM_BUF_SIZE, top);
    pclose(top);
    return buf;
}
