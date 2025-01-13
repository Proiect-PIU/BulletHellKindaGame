//
// Created by francisc on 10/6/24.
//

#ifndef CPPGAMEDARCUOPENGL_GAME_HPP
#define CPPGAMEDARCUOPENGL_GAME_HPP

#include "../Context/GameContext.hpp"
#include "../../Logic/Logic.hpp"

class Game{
    Logic *logic;
    GameContext *gameContext;
public:
    Game();
    ~Game();
    void run();
};


#endif //CPPGAMEDARCUOPENGL_GAME_HPP
