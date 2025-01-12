
#include "Timer.hpp"
#include "../../Creators/Loader/Loader.hpp"

 Timer::Timer(float cooldown, float reset):
        cooldown(cooldown), reset(reset), time(cooldown){};
//    Timer(const Timer &w):
//        shootCooldown(w.shootCooldown), shootReset(w.shootReset), shootTime(w.shootCooldown){};
void Timer::update(){
    float deltaTime = Loader::getInstance().getDeltaTime();
    if (time > reset) {
        time -= deltaTime;
    }
}
bool Timer::onCooldown(){
    if (time <= reset) {
        time = cooldown;
        return false;
    }
    return true;
}