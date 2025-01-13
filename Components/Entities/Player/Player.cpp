//
// Created by francisc on 10/13/24.
//

#include <iostream>
#include "Player.hpp"
#include "../../../Creators/Loader/Loader.hpp"

void Player::update() {
    processInputs();
    switch (state) {
        case MOVING:
            move((Directions)dir);
            break;
        case ATTACKING:
            shoot = true;
            break;
        case BOMBING:
        case IDLE:
            break;
    }
    state = IDLE;
}

void Player::processInputs() {
    GLFWwindow *window = Loader::getInstance().getWindow();
    dir = NONE;
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        state = MOVING;
        if(self->figure->getPosition().x < -0.95)
        {
            dir = NONE;
        }
        else
        {
            dir = LEFT;
        }
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        state = MOVING;
        if(self->figure->getPosition().x > 0.95)
        {
            dir = NONE;
        }
        else
        {
            dir = RIGHT;
        }
    }
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
        state = MOVING;
        if(self->figure->getPosition().y > 0.95)
        {
            dir = NONE;
        }
        else
        {
            dir = UP;
        }
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        state = MOVING;
        if(self->figure->getPosition().y < -0.95)
        {
            dir = NONE;
        }
        else
        {
            dir = DOWN;
        }
    }
    if (dir == NONE) {
        state = IDLE;
    }
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
        if (!timer->onCooldown()) {
            shoot = true;
        }
    } else {
        shoot = false;
    }
    timer->update();
}

