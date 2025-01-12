//
// Created by francisc on 11/24/24.
//

#ifndef CPPGAMEDARCUOPENGL_WAVE_HPP
#define CPPGAMEDARCUOPENGL_WAVE_HPP


#include "../Components/Entities/Entities.hpp"
#include "../Components//Entities/Bullets/Bullet.hpp"

class Wave{
public:
    std::vector<std::pair<Entities*, std::vector<Bullet*>>> entities;
    float timer;
    enum Condition{KILL_ALL, SURVIVE, UNSET}condition = UNSET;
    Wave(const std::vector<std::pair<Entities*, std::vector<Bullet*>>> &entities,
         Condition condition, float timer = 0.0f):
        entities(entities), condition(condition), timer(timer){};
    ~Wave(){
        for (auto& enemy : entities) {
            delete enemy.first;
            for(auto& bullet : enemy.second)
                delete bullet;
        }
    };
};


#endif //CPPGAMEDARCUOPENGL_WAVE_HPP
