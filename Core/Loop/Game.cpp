//
// Created by francisc on 10/6/24.
//

#include <iostream>
#include "Game.hpp"
#include "../Utility/Utils.hpp"
#include "../../Renderer/Renderer.hpp"
#include "../../Logic/Game/GameLogic.hpp"


Game::Game() {

    std::string folderPath = "Resources/Graphics";
    Loader::getInstance().loadFromFolder(folderPath);
    gameContext = new GameContext();
    gameLogic = new GameLogic();
    Loader::getInstance().setWindow(gameContext->getWindow());
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
        Loader::getInstance().updateDeltaTime();

        gameLogic->processLogic();

        Renderer::drawCanvas(gameContext->getShaderProgram());

        glfwSwapBuffers(gameContext->getWindow());
        glfwPollEvents();

        Utils::capFrameRate(frameStart);
    }
    glfwTerminate();
}
