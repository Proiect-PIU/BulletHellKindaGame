//
// Created by francisc on 10/10/24.
//

#include "GameLogic.hpp"
#include "../../Core/Utility/Utils.hpp"
#include "../../Components/Entities/Entities.hpp"


void processInput(GLFWwindow &window, Element *e) {
    static float pozX = 0.0f, pozY = 0.0f;
    static float rotation = 0.0f;
    if (glfwGetKey(&window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        e->setPosition(glm::vec3(pozX -= 0.01f, pozY, 0.0f));
    }
    if (glfwGetKey(&window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        e->setPosition(glm::vec3(pozX += 0.01f, pozY, 0.0f));
    }
    if (glfwGetKey(&window, GLFW_KEY_UP) == GLFW_PRESS) {
        e->setPosition(glm::vec3(pozX, pozY += 0.01f, 0.0f));
    }
    if (glfwGetKey(&window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        e->setPosition(glm::vec3(pozX, pozY -= 0.01f, 0.0f));
    }
    //e->setRotation(rotation += 0.1f, glm::vec3(0.0f, 0.0f, 1.0f));
    //e->setScale(glm::vec3(3.0f, 3.0f, 3.0f));
    if(rotation >= 360)
        rotation = 0.0f;
} 
void GameLogic::processLogic(Canvas &c, GLFWwindow &window) {
    std::vector<float> squareVertices = {
            -0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 1.0f, // Bottom Left (White)
            0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 1.0f, // Bottom Right (Magenta)
            0.5f,  0.5f, 0.0f,   0.0f, 1.0f, 1.0f, // Top Right (Cyan)
            -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f  // Top Left (Yellow)
    };
    std::vector<unsigned int> squareIndices = {
            0, 1, 2,  // First Triangle
            2, 3, 0   // Second Triangle
    };
    auto circleVertices = Utils::generateCircleVertices(
            -0.5f, 0.0f, 0.0f, // Center
            0.3f,              // Radius
            50,                // Segments
            glm::vec3(0.0f, 0.0f, 1.0f), // Center Color (Blue)
            glm::vec3(1.0f, 0.0f, 0.0f) // Edge Color (Blue)
    );

    e->processInputs(window);
//    std::unique_ptr<Element> square = std::make_unique<Element>(squareVertices, squareIndices);
//    std::unique_ptr<Element> circle = std::make_unique<Element>(circleVertices);

    c.addElement(std::move(std::make_unique<Element>(*e->getElement())));
//    c.addElement(std::move(square));
//    c.addElement(std::move(circle));
}

GameLogic::~GameLogic() {

}
