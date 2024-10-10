//
// Created by francisc on 10/6/24.
//

#include <GL/glew.h>
#include <iostream>
#include <glm/vec3.hpp>
#include "Game.hpp"
#include "../../Renderer/Canvas/Element/Element.hpp"
#include "../Utility/Utils.hpp"
#include "../../Renderer/Canvas/Canvas.hpp"
#include "../../Renderer/Renderer.hpp"

Game::Game() {
    gc = new GameContext();
}

Game::~Game() {
    delete gc;
}

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

//void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
//    glViewport(0, 0, width, height);
//}


void Game::run() {
    auto *c = new Canvas();
    std::vector<float> triangleVertices = {
            -0.9f, -0.9f, 0.0f,  1.0f, 0.0f, 0.0f, // Vertex 1
            0.0f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f, // Vertex 2
            0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f  // Vertex 3
    };
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
    std::unique_ptr<Element> triangle = std::make_unique<Element>(triangleVertices);
    std::unique_ptr<Element> square = std::make_unique<Element>(squareVertices, squareIndices);
    std::unique_ptr<Element> circle = std::make_unique<Element>(circleVertices);
    c->addElement(std::move(triangle));
    c->addElement(std::move(square));
    c->addElement(std::move(circle));

    while (!gc->windowClosed()) {
        processInput(gc->getWindow());
        Renderer::drawCanvas(*c, gc->getShaderProgram());
        glfwSwapBuffers(gc->getWindow());
        glfwPollEvents();
    }
    glfwTerminate();
}
