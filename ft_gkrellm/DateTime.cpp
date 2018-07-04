//
// Created by Alex LAZAREV on 6/30/18.
//

#include <iomanip>
#include <sstream>
#include "DateTime.hpp"

Date::Date() {

}

const std::string Date::getDate() const {
    time_t seconds = time(NULL);
    tm* timeinfo = localtime(&seconds);
    std::stringstream buf;

    buf << "[" << timeinfo->tm_year + 1900 << "-";
    buf << std::setw(2) << std::setfill('0') << timeinfo->tm_mon + 1 << "-";
    buf << std::setw(2) << std::setfill('0') << timeinfo->tm_mday;
    buf << "][" << std::setw(2) << std::setfill('0') <<timeinfo->tm_hour << ":";
    buf << std::setw(2) << std::setfill('0') << timeinfo->tm_min << ":";
    buf << std::setw(2) << std::setfill('0') << timeinfo->tm_sec;
    buf << "] ";
    return buf.str();
}

Date::Date(Date const &obj) {
    *this = obj;
}

Date &Date::operator=(Date const &src) {
    if (this != &src)
        ;
    return *this;
}
