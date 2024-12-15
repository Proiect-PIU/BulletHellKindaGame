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
    Updater *worker;
public:
    GameLogic();
    void processLogic() override;
    ~GameLogic() override;
};


#endif //CPPGAMEDARCUOPENGL_GAMELOGIC_HPP
