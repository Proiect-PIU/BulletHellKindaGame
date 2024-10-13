//
// Created by francisc on 10/13/24.
//

#include "Player.hpp"

void Player::processInputs(GLFWwindow &window) {
    static float pozX = 0.0f, pozY = 0.0f;
    static float rotation = 0.0f;
    if (glfwGetKey(&window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        this->getElement()->setPosition(glm::vec3(pozX -= 0.01f, pozY, 0.0f));
    }
    if (glfwGetKey(&window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        this->getElement()->setPosition(glm::vec3(pozX += 0.01f, pozY, 0.0f));
    }
    if (glfwGetKey(&window, GLFW_KEY_UP) == GLFW_PRESS) {
        this->getElement()->setPosition(glm::vec3(pozX, pozY += 0.01f, 0.0f));
    }
    if (glfwGetKey(&window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        this->getElement()->setPosition(glm::vec3(pozX, pozY -= 0.01f, 0.0f));
    }
    //this->getElement()->setRotation(rotation += 0.1f, glm::vec3(0.0f, 0.0f, 1.0f));
    //this->getElement()->setScale(glm::vec3(3.0f, 3.0f, 3.0f));
    if(rotation >= 360)
        rotation = 0.0f;
}
