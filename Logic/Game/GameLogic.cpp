//
// Created by francisc on 10/10/24.
//

#include "GameLogic.hpp"
#include "../../Components/Pattern/ShootingPatterns/ClassicPattern.hpp"
#include "../../Levels/TestLevels/TestLevel.hpp"

GameLogic::GameLogic() {
    testLevel = new TestLevel();
    worker = new Updater();
    matrix = new CollisionMatrix(1, 1, 16, 16);
}

static std::chrono::steady_clock::time_point lastUpdateTime = std::chrono::steady_clock::now();
float getDeltaTime() {
    auto currentTime = std::chrono::steady_clock::now();
    float deltaTime = std::chrono::duration<float, std::chrono::seconds::period>(currentTime - lastUpdateTime).count();
    lastUpdateTime = currentTime;
    return deltaTime;
}

void GameLogic::processLogic(Canvas &canvas, GLFWwindow &window) {
    float delta = getDeltaTime();
    worker->update(*testLevel, canvas, *matrix, delta, window);
    matrix->CheckForCollision();
}

GameLogic::~GameLogic() {
    if (!testLevel) {
        delete testLevel;
    }
    testLevel = nullptr;
}
