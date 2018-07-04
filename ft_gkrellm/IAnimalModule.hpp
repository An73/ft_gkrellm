//
// Created by Alex LAZAREV on 7/1/18.
//

#ifndef LOLE_IANIMALMODULE_HPP
#define LOLE_IANIMALMODULE_HPP
class IAnimalModule{

public:
    virtual ~IAnimalModule(){}
    virtual const char *getPart(int frame, int i) = 0;
};

#endif //LOLE_IANIMALMODULE_HPP

