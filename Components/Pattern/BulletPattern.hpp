//
// Created by francisc on 10/15/24.
//

#ifndef CPPGAMEDARCUOPENGL_BULLETPATTERN_HPP
#define CPPGAMEDARCUOPENGL_BULLETPATTERN_HPP

#include <cmath>
#include "../../Renderer/Canvas/Canvas.hpp"
#include "../Entities/Bullets/Bullets.hpp"

class BulletPattern{
protected:
    int nrOfBullets;
public:
    explicit BulletPattern(int nrOfBullets): nrOfBullets(nrOfBullets) {};
    virtual void updatePattern(float deltaTime, Canvas &canvas, Bullets &bullet) = 0;
    ~BulletPattern() = default;
};


#endif //CPPGAMEDARCUOPENGL_BULLETPATTERN_HPP
