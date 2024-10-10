//
// Created by francisc on 10/6/24.
//

#include <GL/glew.h>
#include <iostream>
#include "Game.hpp"
#include "../../Renderer/Element.hpp"

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

// Resize the viewport when the window is resized
//void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
//    glViewport(0, 0, width, height);
//}


void Game::run() {
    float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.0f, 0.0f
    };
    size_t vertexCount = sizeof(vertices) / sizeof(vertices[0]);
    Element *e = new Element(vertices, vertexCount);
    // Render loop
    while (!glfwWindowShouldClose(gc->getWindow())) {
        processInput(gc->getWindow());

        glClearColor(0.5f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(gc->getShaderProgram());
        glBindVertexArray(e->getVAO());
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(gc->getWindow());
        glfwPollEvents();
    }
    glfwTerminate();
}
