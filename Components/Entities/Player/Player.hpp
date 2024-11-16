//
// Created by francisc on 10/13/24.
//

#ifndef CPPGAMEDARCUOPENGL_PLAYER_HPP
#define CPPGAMEDARCUOPENGL_PLAYER_HPP


#include <GLFW/glfw3.h>
#include "../Entities.hpp"
#include "../../../Renderer/Canvas/Canvas.hpp"
#include "../Bullets/Bullets.hpp"
#include "../Bullets/Pattern/Pattern.hpp"
#include "../Bullets/Pattern/ShootingPatterns/ClassicPattern.hpp"

class Player: public Entities{
    enum player_state{IDLE, MOVING, ATTACKING, BOMBING} state = IDLE;
    int dir = NONE;
    std::vector<Bullets> mag = {};
public:
    Player(Entity *e, Weapon *w): Entities(*e, *w){};
    void setPattern(Pattern *p);
    void update(GLFWwindow &window, Canvas &c, float deltaTime);
    void processInputs(GLFWwindow &window, float deltaTime);
    void loadBullets();
    void updatedBullets(Canvas &c, float deltaTime);
    ~Player(){
        if (!weapon) {
            delete weapon;
        }
    };
};


#endif //CPPGAMEDARCUOPENGL_PLAYER_HPP
