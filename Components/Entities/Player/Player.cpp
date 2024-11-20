//
// Created by francisc on 10/13/24.
//

#include <iostream>
#include "Player.hpp"
#include "../../../Core/Utility/Utils.hpp"
#define pattern weapon->stats->pattern
#define time weapon->stats->shootTime
#define cooldown weapon->stats->shootCooldown
#define reset weapon->stats->shootReset
void Player::setPattern(BulletPattern *p) {
    if (!pattern) {
        delete pattern;
    }
    pattern = p;
}

void Player::update(GLFWwindow &window, Canvas &c, float deltaTime) {
    processInputs(window, deltaTime);
    switch (state) {
        case MOVING:
            move((Directions)dir, deltaTime);
            break;
        case ATTACKING:
            loadBullets();
            break;
        case BOMBING:
        case IDLE:
            break;
    }
    state = IDLE;
    updatedBullets(c, deltaTime);
}

void Player::loadBullets() {
    float lifespan = 1.0f;
    float speed = 5.0f;
    glm::vec3 pos = self->element->getPosition();
    pos.y += 0.05f;
    mag.push_back(*(new Bullets(lifespan, speed, weapon->element, pos, 0.0f)));
}

void Player::updatedBullets(Canvas &c, float deltaTime) {
    for(auto bullet = mag.begin(); bullet != mag.end();) {
        bullet->lifespan -= deltaTime;
        if(bullet->lifespan <= 0.0f) {
            bullet = mag.erase(bullet);
        } else {
            pattern->updatePattern(deltaTime, c, *bullet);
        }
        if(!mag.empty()) {
            *bullet++;
        }
    }
}

void Player::processInputs(GLFWwindow &window, float deltaTime) {
    dir = NONE;
    if (glfwGetKey(&window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        state = MOVING;
        dir |= LEFT;
    }
    if (glfwGetKey(&window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        state = MOVING;
        dir |= RIGHT;
    }
    if (glfwGetKey(&window, GLFW_KEY_UP) == GLFW_PRESS) {
        state = MOVING;
        dir |= UP;
    }
    if (glfwGetKey(&window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        state = MOVING;
        dir |= DOWN;
    }
    if(dir == NONE) {
        state = IDLE;
    }
    if (glfwGetKey(&window, GLFW_KEY_SPACE) == GLFW_PRESS) {
        if (time <= reset) {
            state = ATTACKING;
            time = cooldown;
        }
    }
    if (time > reset) {
        time -= deltaTime;
    }
}
#undef pattern
#undef time
#undef cooldown
#undef reset