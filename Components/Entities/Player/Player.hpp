//
// Created by francisc on 10/13/24.
//

#ifndef CPPGAMEDARCUOPENGL_PLAYER_HPP
#define CPPGAMEDARCUOPENGL_PLAYER_HPP


#include <GLFW/glfw3.h>
#include "../Entities.hpp"
#include "../../../Renderer/Canvas/Canvas.hpp"
#include "../Bullets/Bullets.hpp"
#include "../../../Components/Pattern/BulletPattern.hpp"

class Player: public Entities{
    enum Player_state{IDLE, MOVING, ATTACKING, BOMBING} state = IDLE;
    int dir = NONE;
    std::vector<Bullets> mag = {};
public:
    Player(Entity *e, Weapon *w): Entities(*e, *w){};
    void setPattern(BulletPattern *p);
    void update()override;
    void processInputs();
    void loadBullets();
    void updateBullets();
    ~Player() = default;
};


#endif //CPPGAMEDARCUOPENGL_PLAYER_HPP
