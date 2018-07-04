//
// Created by Alex LAZAREV on 7/1/18.
//

#ifndef LOLE_ANIMALMODULE_HPP
#define LOLE_ANIMALMODULE_HPP


#include <string>
#include "IAnimalModule.hpp"

class AnimalModule : public IAnimalModule{

private:
std::string animal[4][7];

public:
    const char  *getPart(int frame, int i);
    AnimalModule();
    virtual ~AnimalModule();
    AnimalModule(AnimalModule const &obj);

    AnimalModule &operator=(AnimalModule const &src);

};


#endif //LOLE_ANIMALMODULE_HPP
