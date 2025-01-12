//
// Created by francisc on 10/10/24.
//

#ifndef CPPGAMEDARCUOPENGL_ENTITIES_HPP
#define CPPGAMEDARCUOPENGL_ENTITIES_HPP


#include <GLFW/glfw3.h>

#include "../../Core/Utility/Enums/Directions.h"
#include "../../Persistance/Data/Objects/Entity.hpp"
#include "Bullets/BulletTypes.hpp"
#include "../../Core/Utility/Timer.hpp"

class Entities{
public:
    Entity *self;
    Timer *timer;
    BulletType type;
    int nrOfBullets = 1;
    bool isBullet = false;
    float angle = 0.0f;
    bool shoot = false;

    Entities(Entity &e, BulletType bt, Timer &t):
    self(&e), type(bt), timer(&t){};
    virtual void update() = 0;
    void move(Directions dir);
    [[nodiscard]] BulletType getType() const;
    [[nodiscard]] bool hasShoot();
    virtual ~Entities();
};


#endif //CPPGAMEDARCUOPENGL_ENTITIES_HPP
