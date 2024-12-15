
#include "Bullet.h"

void Bullet::update(){
    float deltaTime = Loader::getInstance().getDeltaTime();
    stats->lifespan -= deltaTime;
    if (deltaTime <= 0.0f) {
        dead = true;
    } else {
        pattern->updatePattern(*this);
    }
}

bool Bullet::isDead(){
    return dead;
}
