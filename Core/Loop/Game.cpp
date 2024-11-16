//
// Created by francisc on 10/6/24.
//

#include <iostream>
#include "Game.hpp"
#include "../Utility/Utils.hpp"
#include "../../Renderer/Renderer.hpp"
#include "../../Logic/Game/GameLogic.hpp"

Game::Game() {
    gameContext = new GameContext();
    canvas = new Canvas();
    gameLogic = new GameLogic();
}

Game::~Game() {
    if (!gameContext) {
        delete gameContext;
    }
    if (!gameLogic) {
        delete gameLogic;
    }
}

//void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
//    glViewport(0, 0, width, height);
//}


void Game::run() {
    while (!gameContext->windowClosed()) {
        auto frameStart = std::chrono::steady_clock::now();

        gameLogic->processLogic(*canvas, *gameContext->getWindow());

        Renderer::drawCanvas(*canvas, gameContext->getShaderProgram());

        glfwSwapBuffers(gameContext->getWindow());
        glfwPollEvents();

        Utils::capFrameRate(frameStart);
    }
    glfwTerminate();
}
