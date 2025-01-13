//
// Created by francisc on 11/13/24.
//

#ifndef CPPGAMEDARCUOPENGL_BASESTATS_HPP
#define CPPGAMEDARCUOPENGL_BASESTATS_HPP


class BaseStats{
public:
    int health;
    int rockets;
    float speed;
    int damage;
    BaseStats(int health, int rockets, float speed, int damage):
    health(health), rockets(rockets), speed(speed), damage(damage){};
};


#endif //CPPGAMEDARCUOPENGL_BASESTATS_HPP
