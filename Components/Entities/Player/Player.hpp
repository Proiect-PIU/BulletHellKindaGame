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
    int dir;
    std::vector<Bullets> mag;
    Element *w;
    float shootCooldown = 0.0f;
    const float shootCooldownMax = 0.3f;
    Pattern *bulletPattern = new ClassicPattern(3);
public:
    Player(const std::vector<float>& vertices, const std::vector<float>& weapon): Entities(vertices){
        w = new Element(weapon);
    };
    Player(const std::vector<float>& vertices, const std::vector<unsigned int>& indices, const std::vector<float>& weapon): Entities(vertices, indices){
        w = new Element(weapon);
    };
    Player(const std::vector<float>& vertices, const std::vector<float>& weapon, const std::vector<unsigned int>& weaponIndices): Entities(vertices){
        w = new Element(weapon, weaponIndices);
    };
    Player(const std::vector<float>& vertices, const std::vector<unsigned int>& indices, const std::vector<float>& weapon,
           const std::vector<unsigned int>& weaponIndices): Entities(vertices, indices){
        w = new Element(weapon, weaponIndices);
    };
    void setPattern(Pattern *p);
    void update(GLFWwindow &window, Canvas &c, float deltaTime);
    void processInputs(GLFWwindow &window, float deltaTime);
    void loadBullets();
    void updatedBullets(Canvas &c, float deltaTime);
    ~Player(){
        delete w;
    };
};


#endif //CPPGAMEDARCUOPENGL_PLAYER_HPP
