//
// Created by francisc on 10/13/24.
//

#include "Player.hpp"
#include "../../../Core/Utility/Utils.hpp"

void Player::processInputs(GLFWwindow &window, Canvas &c) {
    static float pozX = 0.0f, pozY = 0.0f;
    static float rotation = 0.0f;
    static bool spaceOn = false;
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
    if(glfwGetKey(&window, GLFW_KEY_SPACE) == GLFW_PRESS || spaceOn) {
        spaceOn = true;
        static float bulletPozX = this->getElement()->getPosition().x, bulletPozY = this->getElement()->getPosition().y + 0.1f;
        bulletPozX = pozX;
        bulletPozY += 0.04f;
        w->setPosition(glm::vec3(bulletPozX, bulletPozY, 0.0f));
        c.addElement(std::move(std::make_unique<Element>(*w)));
        if(bulletPozY >= 1.0f) {
            spaceOn = false;
            bulletPozX = this->getElement()->getPosition().x, bulletPozY = this->getElement()->getPosition().y + 0.1f;
        }
    }
    //this->getElement()->setRotation(rotation += 0.1f, glm::vec3(0.0f, 0.0f, 1.0f));
    //this->getElement()->setScale(glm::vec3(3.0f, 3.0f, 3.0f));
    if(rotation >= 360)
        rotation = 0.0f;
}
