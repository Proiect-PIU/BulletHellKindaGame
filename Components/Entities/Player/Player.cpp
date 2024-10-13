//
// Created by francisc on 10/13/24.
//

#include <iostream>
#include "Player.hpp"
#include "../../../Core/Utility/Utils.hpp"

void Player::loadBullets() {
    float lifespan = 1.0f;
    float speed = 5.0f;
    mag.push_back(*(new Bullets(lifespan, speed, e->getPosition(), 0.0f)));
}

void Player::updatedBullets(Canvas &c, float deltaTime) {
    for(auto bullet = mag.begin(); bullet != mag.end();) {

        bullet->lifespan -= deltaTime;
        if(bullet->lifespan <= 0.0f) {
            bullet = mag.erase(bullet);
        } else {
            bullet->updateCounter = 0;
            bullet->pos = glm::vec3(bullet->pos.x, bullet->pos.y + bullet->speed * deltaTime, 0.0f);
            std::unique_ptr<Element> e;
            if(w->hasIndices()) {
                e = std::make_unique<Element>(w->getVertices(), w->getIndices());
            } else {
                e = std::make_unique<Element>(w->getVertices());
            }
            e->setPosition(bullet->pos);
            c.addElement(std::move(e));
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
    if (glfwGetKey(&window, GLFW_KEY_SPACE) == GLFW_PRESS) {
        if (shootCooldown <= 0.0f) { // Check if cooldown has expired
            state = ATTACKING;
            loadBullets();          // Fire a bullet
            shootCooldown = shootCooldownMax; // Reset cooldown
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
            break;
    }

    state = IDLE;
    updatedBullets(c, deltaTime);
//    //this->getElement()->setRotation(rotation += 0.1f, glm::vec3(0.0f, 0.0f, 1.0f));
//    //this->getElement()->setScale(glm::vec3(3.0f, 3.0f, 3.0f));
//    if(rotation >= 360)
//        rotation = 0.0f;
}
