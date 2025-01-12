//
// Created by francisc on 10/10/24.
//

#ifndef CPPGAMEDARCUOPENGL_GAMELOGIC_HPP
#define CPPGAMEDARCUOPENGL_GAMELOGIC_HPP


#include "../Logic.hpp"
#include "../../Levels/Level.hpp"
#include "../../Creators/Updater/Updater.hpp"

class GameLogic: public Logic{
    Level *testLevel;
    Level *level_1;
    Level *level_2;
    Level *level_3;
    Level *level_4;
    Updater *worker;
    bool loaded_1 = false, loaded_2 = false, loaded_3 = false;
public:
    GameLogic();
    int processLogic(int &option) override;
    ~GameLogic() override;
};


#endif //CPPGAMEDARCUOPENGL_GAMELOGIC_HPP
