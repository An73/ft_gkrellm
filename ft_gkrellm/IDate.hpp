//
// Created by Alex LAZAREV on 7/1/18.
//

#ifndef RUSH01_IDATE_HPP
#define RUSH01_IDATE_HPP

#include <string>

class IDate{

public:
	virtual						~IDate(){}
    virtual const std::string 	getDate() const = 0;
};

#endif //RUSH01_IDATE_HPP
