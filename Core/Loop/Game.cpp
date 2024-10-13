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
#include "../../Logic/Game/GameLogic.hpp"

Game::Game() {
    gc = new GameContext();
}

Game::~Game() {
    delete gc;
}

//void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
//    glViewport(0, 0, width, height);
//}


void Game::run() {
    std::vector<float> triangleVertices = {
            -0.04f, -0.01f, 0.0f,  1.0f, 0.0f, 0.0f, // Vertex 1
            0.0f, 0.1f, 0.0f,  0.0f, 1.0f, 0.0f, // Vertex 2
            0.04f,  -0.01f, 0.0f,  0.0f, 0.0f, 1.0f  // Vertex 3
    };
    auto *c = new Canvas();
    Logic *l = new GameLogic(triangleVertices);

    while (!gc->windowClosed()) {
        auto frameStart = std::chrono::steady_clock::now();

        l->processLogic(*c, *gc->getWindow());

        Renderer::drawCanvas(*c, gc->getShaderProgram());

        glfwSwapBuffers(gc->getWindow());
        glfwPollEvents();

        Utils::capFrameRate(frameStart);
    }
    glfwTerminate();
}
