//
// Created by Alex LAZAREV on 7/1/18.
//

#include "AnimalModule.hpp"

AnimalModule::AnimalModule() {
     animal[0][0] ="      .-\"-.";
     animal[0][1] ="    _/_-.-_\\_";
     animal[0][2] ="   / __} {__ \\";
     animal[0][3] ="  / //  \"  \\\\ \\";
     animal[0][4] =" / / \\'---'/ \\ \\";
     animal[0][5] =" \\ \\_/`\"\"\"`\\_/ /";
     animal[0][6] ="  \\           /";

     animal[1][0] ="      .-\"-.";
     animal[1][1] ="    _/.-.-.\\_";
     animal[1][2] ="   /|( o o )|\\";
     animal[1][3] ="  | //  \"  \\\\ |";
     animal[1][4] =" / / \\'---'/ \\ \\";
     animal[1][5] =" \\ \\_/`\"\"\"`\\_/ /";
     animal[1][6] ="  \\           /";

     animal[2][0] ="      .-\"-.";
     animal[2][1] ="    _/.-.-.\\_";
     animal[2][2] ="   ( ( o o ) )";
     animal[2][3] ="    |/  \"  \\|";
     animal[2][4] ="     \\'/^\\'/";
     animal[2][5] ="     /`\\ /`\\";
     animal[2][6] ="    /  /|\\  \\";

     animal[3][0] ="      .-\"-.";
     animal[3][1] ="    _/.-.-.\\_";
     animal[3][2] ="   ( ( o o ) )";
     animal[3][3] ="    |/  \"  \\|";
     animal[3][4] ="     \\ .-. /";
     animal[3][5] ="     /`\"\"\"`\\";
     animal[3][6] ="    /       \\";

}

AnimalModule::~AnimalModule() {

}

AnimalModule::AnimalModule(AnimalModule const &obj) {
    *this = obj;
}

AnimalModule &AnimalModule::operator=(AnimalModule const &src) {
    if (this != &src){
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 7; j++)
                this->animal[i][j] = src.animal[i][j];
    }
    return *this;
}

const char *AnimalModule::getPart(int frame, int i) {
    return animal[frame][i].c_str();
}
