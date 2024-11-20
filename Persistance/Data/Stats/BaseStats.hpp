//
// Created by francisc on 11/13/24.
//

#ifndef CPPGAMEDARCUOPENGL_BASESTATS_HPP
#define CPPGAMEDARCUOPENGL_BASESTATS_HPP


class BaseStats{
public:
    unsigned int health;
    unsigned int rockets;
    float speed;

    BaseStats(unsigned int health, unsigned int rockets, float speed):
    health(health), rockets(rockets), speed(speed){};
};


#endif //CPPGAMEDARCUOPENGL_BASESTATS_HPP
