//
// Created by francisc on 11/13/24.
//

#ifndef CPPGAMEDARCUOPENGL_TIMER_HPP
#define CPPGAMEDARCUOPENGL_TIMER_HPP

#include "../../Creators/Loader/Loader.hpp"

class Timer{
public:
    float reset;
    float time;
    float cooldown;

    explicit Timer(float cooldown, float reset = 0):
        cooldown(cooldown), reset(reset), time(cooldown){};
//    Timer(const Timer &w):
//        shootCooldown(w.shootCooldown), shootReset(w.shootReset), shootTime(w.shootCooldown){};
    void update(){
        float deltaTime = Loader::getInstance().getDeltaTime();
        if (time > reset) {
            time -= deltaTime;
        }
    }
    bool onCooldown(){
        if (time <= reset) {
            time = cooldown;
            return false;
        }
        return true;
    }
    ~Timer()= default;
};



#endif //CPPGAMEDARCUOPENGL_TIMER_HPP
