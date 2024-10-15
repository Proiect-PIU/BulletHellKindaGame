//
// Created by francisc on 10/13/24.
//

#include <iostream>
#include "Player.hpp"
#include "../../../Core/Utility/Utils.hpp"

void Player::setPattern(Pattern *p) {
    pat = p;
}

void Player::loadBullets() {
    float lifespan = 1.0f;
    float speed = 5.0f;
    glm::vec3 pos = e->getPosition();
    pos.y += 0.05f;
    mag.push_back(*(new Bullets(lifespan, speed, pos, 0.0f)));
}

void Player::updatedBullets(Canvas &c, float deltaTime) {
    for(auto bullet = mag.begin(); bullet != mag.end();) {

        bullet->lifespan -= deltaTime;
        if(bullet->lifespan <= 0.0f) {
            bullet = mag.erase(bullet);
        } else {
            pat->updatePattern(deltaTime, c, *bullet, w);
        }
        if(!mag.empty()) {
            *bullet++;
        }
    }
}

void Player::processInputs(GLFWwindow &window, Canvas &c, float deltaTime) {
    int dir = NONE;
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
        if (shootCooldown <= 0.0f) {
            state = ATTACKING;
            shootCooldown = shootCooldownMax;
        }
    }
    if (shootCooldown > 0.0f) {
        shootCooldown -= deltaTime;
        if (shootCooldown < 0.0f) {
            shootCooldown = 0.0f;
        }
    }

    switch (state) {
        case MOVING:
            move((Directions)dir, deltaTime);
            break;
        case ATTACKING:
            loadBullets();
            break;
    }

    state = IDLE;
    updatedBullets(c, deltaTime);
}
