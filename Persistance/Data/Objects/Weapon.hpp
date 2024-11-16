//
// Created by francisc on 11/16/24.
//

#ifndef CPPGAMEDARCUOPENGL_WEAPON_HPP
#define CPPGAMEDARCUOPENGL_WEAPON_HPP


#include "../../../Renderer/Canvas/Element/Element.hpp"
#include "../Stats/WeaponStats.hpp"

class Weapon{
public:
    Element *element;
    Graphics *graphics;
    WeaponStats *stats;
    Weapon(Graphics *graphics, WeaponStats *stats): graphics(graphics), stats(stats){
        element = new Element(graphics);
    };
    ~Weapon(){
        delete element;
        delete graphics;
        delete stats;
    }
};


#endif //CPPGAMEDARCUOPENGL_WEAPON_HPP
