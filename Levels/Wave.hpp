//
// Created by francisc on 11/24/24.
//

#ifndef CPPGAMEDARCUOPENGL_WAVE_HPP
#define CPPGAMEDARCUOPENGL_WAVE_HPP


#include "../Components/Entities/Entities.hpp"

class Wave{
public:
    std::vector<Entities*> entities;
    float timer;
    enum Condition{KILL_ALL, SURVIVE, UNSET}condition = UNSET;
    Wave(const std::vector<Entities *> &entities, Condition condition, float timer = 0.0f):
    entities(entities), condition(condition), timer(timer){};
    ~Wave(){
        for (auto& enemy : entities) {
            delete enemy;
        }
    };
};


#endif //CPPGAMEDARCUOPENGL_WAVE_HPP
