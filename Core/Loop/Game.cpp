//
// Created by francisc on 10/6/24.
//

#include <iostream>
#include "Game.hpp"
#include "../Utility/Utils.hpp"
#include "../../Renderer/Renderer.hpp"
#include "../../Logic/Game/GameLogic.hpp"
#include "../../Creators/Loader/Loader.hpp"
#include "../Utility/Enums/GameStates.h"
#include "../../Logic/Menu/MenuLogic.hpp"

Game::Game() {

    std::string folderPath = "Resources/Graphics";
    Loader::getInstance().loadFromFolder(folderPath);
    gameContext = new GameContext();
    Loader::getInstance().setWindow(gameContext->getWindow());
}

Game::~Game() {
    if (!gameContext) {
        delete gameContext;
    }
    if (!logic) {
        delete logic;
    }
}

//void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
//    glViewport(0, 0, width, height);
//}


void Game::run() {
    bool close = false;
    int option = 1;
    Logic *menuLogic = new MenuLogic();
    Logic *gameLogic = new GameLogic();
    logic = menuLogic;
    while (!gameContext->windowClosed() && !close) {
        auto frameStart = std::chrono::steady_clock::now();
        Loader::getInstance().updateDeltaTime();

        switch(logic->processLogic(option)) {
            case MAIN_MENU:
                option = 1;
                break;
            case LEVEL_MENU:
                option = 2;
                break;
            case EXIT:
                close = true;
                break;
            case PLAY_1:
                logic = gameLogic;
                option = 1;
                break;
            case PLAY_2:
                logic = gameLogic;
                option = 2;
                break;
            case PLAY_3:
                logic = gameLogic;
                option = 3;
                break;
            case PLAY_4:
                logic = gameLogic;
                option = 4;
                break;
            case LOSE:
                logic = menuLogic;
                option = 2;
                break;
            case WIN:
                logic = menuLogic;
                option = 3;
                break;
        }

        Renderer::drawCanvas(gameContext->getShaderProgram());

        glfwSwapBuffers(gameContext->getWindow());
        glfwPollEvents();

        Utils::capFrameRate(frameStart);
    }
    glfwTerminate();
}
