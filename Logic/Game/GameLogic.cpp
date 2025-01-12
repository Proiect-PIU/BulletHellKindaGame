//
// Created by francisc on 10/10/24.
//

#include "GameLogic.hpp"
#include "../../Components/Pattern/ShootingPatterns/ClassicPattern.hpp"
#include "../../Levels/TestLevels/TestLevel.hpp"
#include "../../Levels/Level_1/Level_1.hpp"

GameLogic::GameLogic() {
    testLevel = new TestLevel();
    level_1 = new Level_1();
    worker = new Updater();
}

void GameLogic::processLogic() {
    auto currentLevel = level_1;
    worker->update(*currentLevel);
}

GameLogic::~GameLogic() {
    if (!testLevel) {
        delete testLevel;
    }
    testLevel = nullptr;
}
