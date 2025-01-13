
#include "Bullet.hpp"
#include "../../../Creators/Loader/Loader.hpp"

void Bullet::update(){
    float deltaTime = Loader::getInstance().getDeltaTime();
    stats->lifespan -= deltaTime;
    if (stats->lifespan <= 0.0f || self->stats->health <= 0) {
        dead = true;
    }
}

bool Bullet::isDead(){
    return dead;
}
