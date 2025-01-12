//
// Created by francisc on 11/13/24.
//

#ifndef CPPGAMEDARCUOPENGL_TIMER_HPP
#define CPPGAMEDARCUOPENGL_TIMER_HPP

class Timer{
public:
    float reset;
    float time;
    float cooldown;

    explicit Timer(float cooldown, float reset = 0);
//    Timer(const Timer &w):
//        shootCooldown(w.shootCooldown), shootReset(w.shootReset), shootTime(w.shootCooldown){};
    void update();
    bool onCooldown();
    ~Timer()= default;
};



#endif //CPPGAMEDARCUOPENGL_TIMER_HPP
