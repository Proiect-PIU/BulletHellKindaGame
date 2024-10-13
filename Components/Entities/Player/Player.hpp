//
// Created by francisc on 10/13/24.
//

#ifndef CPPGAMEDARCUOPENGL_PLAYER_HPP
#define CPPGAMEDARCUOPENGL_PLAYER_HPP


#include <GLFW/glfw3.h>
#include "../Entities.hpp"
#include "../../../Renderer/Canvas/Canvas.hpp"

class Player: public Entities{
    Element *w;
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
    void processInputs(GLFWwindow &window, Canvas &c);
    ~Player(){
        delete w;
    };
};


#endif //CPPGAMEDARCUOPENGL_PLAYER_HPP
