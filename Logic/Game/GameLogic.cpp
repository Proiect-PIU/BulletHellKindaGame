//
// Created by francisc on 10/10/24.
//

#include "GameLogic.hpp"
#include "../../Components/Pattern/ShootingPatterns/ClassicPattern.hpp"
#include "../../Levels/TestLevels/TestLevel.hpp"
#include "../../Levels/Level_1/Level_1.hpp"
#include "../../Levels/Level_2/Level_2.hpp"
#include "../../Levels/Level_3/Level_3.hpp"
#include "../../Levels/Level_4/Level_4.hpp"
#include "../../Core/Utility/Enums/GameStates.h"

GameLogic::GameLogic() {
    level_1 = new Level_1();
    level_2 = new Level_2();
    level_3 = new Level_3();
    level_4 = new Level_4();
    worker = new Updater();
}

int GameLogic::processLogic(int &option) {
    Level *currentLevel;
    GameStates state;
    switch(option) {
        case 1:
            currentLevel = level_1;
            state = PLAY_1;
            break;
        case 2:
            currentLevel = level_2;
            state = PLAY_2;
            break;
        case 3:
            currentLevel = level_3;
            state = PLAY_3;
            break;
        case 4:
            currentLevel = level_4;
            state = PLAY_4;
            break;
        default:
            currentLevel = testLevel;
            state = TEST;
    }
    if (currentLevel->currentWave == 0 && !loaded_1) {
        currentLevel->wave_1();
        loaded_1 = true;
    } else if (currentLevel->currentWave == 1 && !loaded_2) {
        currentLevel->wave_2();
        loaded_2 = true;
    } else if (currentLevel->currentWave == 2 && !loaded_3) {
        currentLevel->wave_3();
        loaded_3 = true;
    } else if (currentLevel->currentWave == 99) {
        state = LOSE;
    } else if (currentLevel->currentWave == 3){
        loaded_1 = false;
        loaded_2 = false;
        loaded_3 = false;
        return WIN;
    }
    worker->update(*currentLevel);
    return state;
}

GameLogic::~GameLogic() {
    if (!testLevel) {
        delete testLevel;
    }
    testLevel = nullptr;
}
