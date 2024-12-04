//
// Created by francisc on 10/10/24.
//

#ifndef CPPGAMEDARCUOPENGL_ENTITIES_HPP
#define CPPGAMEDARCUOPENGL_ENTITIES_HPP


#include <GLFW/glfw3.h>
#include "../../Renderer/Canvas/Element/Element.hpp"
#include "../../Core/Utility/Utils.hpp"
#include "../../Persistance/Data/Objects/Entity.hpp"
#include "../../Persistance/Data/Objects/Weapon.hpp"

class Entities{
public:
    Entity *self;
    Weapon *weapon;
    explicit Entities(Entity &e, Weapon &w): self(&e), weapon(&w){};
    virtual void update(Canvas &c, CollisionMatrix &matrix, float deltaTime, GLFWwindow &window) = 0;
    void move(Directions dir, float deltaTime);
    ~Entities();
};


#endif //CPPGAMEDARCUOPENGL_ENTITIES_HPP
