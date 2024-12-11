//
// Created by francisc on 10/15/24.
//

#ifndef CPPGAMEDARCUOPENGL_BULLETPATTERN_HPP
#define CPPGAMEDARCUOPENGL_BULLETPATTERN_HPP

#include <cmath>

class BulletPattern{
protected:
    int nrOfBullets;
    glm::vec3 distanceFromEntity;
public:
    BulletPattern(int nrOfBullets, glm::vec3 distanceFromEntity):
    nrOfBullets(nrOfBullets), distanceFromEntity(distanceFromEntity) {};
    virtual void updatePattern(Weapon &weapon, glm::vec3 entityPos) = 0;
    ~BulletPattern() = default;
};


#endif //CPPGAMEDARCUOPENGL_BULLETPATTERN_HPP
