//
// Created by Alex LAZAREV on 6/30/18.
//

#ifndef RUSH01_DATETIMEMODULE_H
#define RUSH01_DATETIMEMODULE_H

#include <ctime>
#include <string>
#include "Defines.hpp"
#include "IDate.hpp"

class Date : public IDate{

public:

    const std::string getDate() const;

    Date();
    Date(Date const &obj);
    Date &operator=(Date const &src);
};


#endif //RUSH01_DATETIMEMODULE_H
