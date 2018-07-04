//
// Created by Alex LAZAREV on 6/30/18.
//

#include <sys/sysctl.h>
#include <iostream>
#include <sstream>
#include "CPU.hpp"
#include "Defines.hpp"

const char *CPU::getModel() const {
    return model.c_str();
}

CPU::CPU() {
    char    str[40];
    size_t  len = sizeof(str);
    sysctlbyname("machdep.cpu.brand_string", str, &len, NULL, 0);
    model = str;
    sysctlbyname("machdep.cpu.core_count", &core_count, &len, NULL, 0);
    buf = new char(CPU_BUF_SIZE);
}


CPU::~CPU() {

}

size_t CPU::getCore_count() const {
    return core_count;
}

size_t CPU::getClockSpeed() const {
    size_t  freq;
    size_t  len;

    len = sizeof(freq);
    sysctlbyname("hw.cpufrequency", &freq, &len, NULL, 0);
    return freq;
}

const char *CPU::getProcessCount() const {
    FILE* top = popen("top -l 1 | grep \"Processes\" |  cut -d' ' -f2", "r");
    if (top)
        fgets(buf, CPU_BUF_SIZE, top);
    pclose(top);
    return buf;
}

const char *CPU::getActivities() const {
    FILE* top = popen("top -l 1 | grep \"CPU usage:\" |  cut -d ' ' -f3", "r");
    if (top)
        fgets(buf, CPU_BUF_SIZE, top);
    pclose(top);
    return buf;
}

CPU::CPU(CPU const &obj) {
    *this = obj;
}

CPU &CPU::operator=(CPU const &src) {
    if (this != &src){
        model = src.model;
        core_count = src.core_count;
        buf = src.buf;
    }
    return *this;
}

