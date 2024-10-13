//
// Created by francisc on 10/10/24.
//

#include "GameLogic.hpp"
#include "../../Core/Utility/Utils.hpp"
#include "../../Components/Entities/Entities.hpp"

GameLogic::GameLogic() {
    std::vector<float> triangleVertices = {
            -0.04f, -0.01f, 0.0f,  1.0f, 0.0f, 0.0f, // Vertex 1
            0.0f, 0.1f, 0.0f,  0.0f, 1.0f, 0.0f, // Vertex 2
            0.04f,  -0.01f, 0.0f,  0.0f, 0.0f, 1.0f  // Vertex 3
    };
    std::vector<float> weaponVertices = {
            -0.01f, -0.05f, 0.0f,   1.0f, 1.0f, 1.0f, // Bottom Left (White)
            0.01f, -0.05f, 0.0f,   1.0f, 0.0f, 1.0f, // Bottom Right (Magenta)
            0.01f,  0.05f, 0.0f,   0.0f, 1.0f, 1.0f, // Top Right (Cyan)
            -0.01f,  0.05f, 0.0f,   1.0f, 1.0f, 0.0f  // Top Left (Yellow)
    };
    std::vector<unsigned int> weaponIndices = {
            0, 1, 2,  // First Triangle
            2, 3, 0   // Second Triangle
    };
    e = new Player(triangleVertices, weaponVertices, weaponIndices);
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

    e->processInputs(window, c);
//    std::unique_ptr<Element> square = std::make_unique<Element>(squareVertices, squareIndices);
//    std::unique_ptr<Element> circle = std::make_unique<Element>(circleVertices);

    c.addElement(std::move(std::make_unique<Element>(*e->getElement())));
//    c.addElement(std::move(square));
//    c.addElement(std::move(circle));
}

GameLogic::~GameLogic() {

}
