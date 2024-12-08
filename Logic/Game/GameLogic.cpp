//
// Created by francisc on 10/10/24.
//

#include "GameLogic.hpp"
#include "../../Components/Pattern/ShootingPatterns/ClassicPattern.hpp"
#include "../../Levels/TestLevels/TestLevel.hpp"
#include "../../Creators/Loader/Loader.hpp"

GameLogic::GameLogic() {
    testLevel = new TestLevel();
    worker = new Updater();
}

void GameLogic::processLogic() {
    auto currentLevel = testLevel;
    worker->update(*currentLevel);
}

GameLogic::~GameLogic() {
    if (!testLevel) {
        delete testLevel;
    }
    testLevel = nullptr;
}
