//
// Created by francisc on 11/13/24.
//

#ifndef CPPGAMEDARCUOPENGL_BASESTATS_HPP
#define CPPGAMEDARCUOPENGL_BASESTATS_HPP


class BaseStats{
public:
    unsigned int health;
    unsigned int rockets;

    BaseStats(unsigned int health, unsigned int rockets):
    health(health), rockets(rockets){};
};


#endif //CPPGAMEDARCUOPENGL_BASESTATS_HPP
