//
// Created by francisc on 10/10/24.
//

#include <iostream>
#include "../../Creators/Loader/Loader.hpp"
#include "Entities.hpp"


Entities::~Entities() {
    if (!self){
       delete self;
    }
}
BulletType Entities::getType() const {
    return type;
}
bool Entities::hasShoot() {
    bool copy = shoot;
    shoot = false;
    return copy;
}

void Entities::move(Directions dir) {
    float deltaTime = Loader::getInstance().getDeltaTime();
    float dx = 0, dy = 0;

    if (dir & UP) dy += 1;
    if (dir & DOWN) dy -= 1;
    if (dir & LEFT) dx -= 1;
    if (dir & RIGHT) dx += 1;

    if (dx != 0 && dy != 0) {
        dx /= (float)sqrt(2);
        dy /= (float)sqrt(2);
    }
    float speed = self->stats->speed;
    float x = self->figure->getPosition().x + dx * deltaTime * speed;
    float y = self->figure->getPosition().y + dy * 1.6f * deltaTime * speed;
    glm::vec3 newPos = glm::vec3(x, y, 0.0f);
    self->figure->setPosition(newPos);
}
