//
// Created by francisc on 10/15/24.
//

#ifndef CPPGAMEDARCUOPENGL_BULLETPATTERN_HPP
#define CPPGAMEDARCUOPENGL_BULLETPATTERN_HPP

#include <cmath>
#include "../Entities/Bullets/Bullet.h"

class Bullet;

class BulletPattern{
protected:
    int nrOfBullets;
public:
    BulletPattern(int nrOfBullets):
    nrOfBullets(nrOfBullets) {};
    virtual void updatePattern(Bullet &weapon) = 0;
    ~BulletPattern() = default;
};


#endif //CPPGAMEDARCUOPENGL_BULLETPATTERN_HPP
