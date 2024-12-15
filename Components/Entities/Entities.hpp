//
// Created by francisc on 10/10/24.
//

#ifndef CPPGAMEDARCUOPENGL_ENTITIES_HPP
#define CPPGAMEDARCUOPENGL_ENTITIES_HPP


#include <GLFW/glfw3.h>

#include "../../Core/Utility/Enums/Directions.h"
#include "../../Persistance/Data/Objects/Entity.hpp"
#include "Bullets/BulletTypes.h"
#include "../../Core/Utility/Timer.hpp"

class Entities{
public:
    Entity *self;
    Timer *timer;
    BulletType type;

    Entities(Entity &e, BulletType bt, Timer &t):
    self(&e), type(bt), timer(&t){};
    virtual void update() = 0;
    void move(Directions dir);
    [[nodiscard]] BulletType getType() const;
    virtual ~Entities();
};


#endif //CPPGAMEDARCUOPENGL_ENTITIES_HPP
