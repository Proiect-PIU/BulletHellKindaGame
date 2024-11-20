//
// Created by francisc on 11/13/24.
//

#ifndef CPPGAMEDARCUOPENGL_COCCI_HPP
#define CPPGAMEDARCUOPENGL_COCCI_HPP


#include "../../../Entities.hpp"

class Cocci: public Entities{

public:
    Cocci(Entity *e, Weapon *w): Entities(*e, *w){};
    ~Cocci() = default;
};


#endif //CPPGAMEDARCUOPENGL_COCCI_HPP
