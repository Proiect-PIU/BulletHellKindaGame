//
// Created by francisc on 10/10/24.
//

#include <iostream>
#include "Entities.hpp"

Entities::~Entities() {
    if (!self){
       delete self;
    }
    if (!weapon) {
        delete weapon;
    }
}

void Entities::move(Directions dir, float deltaTime) {
    float dx = 0, dy = 0;

    if (dir & UP) dy += 1;
    if (dir & DOWN) dy -= 1;
    if (dir & LEFT) dx -= 1;
    if (dir & RIGHT) dx += 1;

    if (dx != 0 && dy != 0) {
        dx /= sqrt(2);
        dy /= sqrt(2);
    }
#define entity self->element->getPosition()
    glm::vec3 newPos = glm::vec3(entity.x + dx * 1.2f * deltaTime, entity.y + dy * 1.4f * deltaTime, 0.0f);
    self->element->setPosition(newPos);
#undef entity
}
