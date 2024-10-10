//
// Created by francisc on 10/6/24.
//

#include <GL/glew.h>
#include <iostream>
#include "Game.hpp"
#include "../../Renderer/Canvas/Element/Element.hpp"

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
    std::vector<float> triangleVertices = {
            -0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f, // Vertex 1
            0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f, // Vertex 2
            0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f  // Vertex 3
    };
    std::vector<float> squareVertices = {
            // Positions          // Colors
            -0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 1.0f, // Bottom Left (White)
            0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 1.0f, // Bottom Right (Magenta)
            0.5f,  0.5f, 0.0f,   0.0f, 1.0f, 1.0f, // Top Right (Cyan)
            -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f  // Top Left (Yellow)
    };

    std::vector<unsigned int> squareIndices = {
            0, 1, 2,  // First Triangle
            2, 3, 0   // Second Triangle
    };
    auto* triangle = new Element(triangleVertices);
    auto* square = new Element(squareVertices, squareIndices);
    while (!gc->windowClosed()) {
        processInput(gc->getWindow());

        glClearColor(0.5f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(gc->getShaderProgram());

        glBindVertexArray(triangle->getVAO());
        glDrawArrays(GL_TRIANGLES, 0, triangle->getVertexCount() / 6);

        glBindVertexArray(square->getVAO());
        glDrawElements(GL_TRIANGLES, square->getIndexCount(), GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(gc->getWindow());
        glfwPollEvents();
    }
    glfwTerminate();
}
