//
// Created by francisc on 10/13/24.
//

#ifndef CPPGAMEDARCUOPENGL_PLAYER_HPP
#define CPPGAMEDARCUOPENGL_PLAYER_HPP


#include <GLFW/glfw3.h>
#include "../Entities.hpp"
#include "../../../Renderer/Canvas/Canvas.hpp"
#include "../../../Components/Pattern/BulletPattern.hpp"
#include "../Bullets/BulletTypes.hpp"

class Player: public Entities{
    enum Player_state{IDLE, MOVING, ATTACKING, BOMBING} state = IDLE;
    int dir = NONE;

public:
    Player(Entity &e, BulletType bt, Timer &t): Entities(e, bt, t){};
    void update()override;
    void processInputs();
    ~Player() override = default;
};


#endif //CPPGAMEDARCUOPENGL_PLAYER_HPP
