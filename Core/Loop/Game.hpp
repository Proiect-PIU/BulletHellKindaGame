//
// Created by francisc on 10/6/24.
//

#ifndef CPPGAMEDARCUOPENGL_GAME_HPP
#define CPPGAMEDARCUOPENGL_GAME_HPP

#include "../Context/GameContext.hpp"

class Game{
    //Logic *l;
    GameContext *gc;
public:
    Game();
    ~Game();
    void run();
};


#endif //CPPGAMEDARCUOPENGL_GAME_HPP
