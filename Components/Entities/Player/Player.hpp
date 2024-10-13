//
// Created by francisc on 10/13/24.
//

#ifndef CPPGAMEDARCUOPENGL_PLAYER_HPP
#define CPPGAMEDARCUOPENGL_PLAYER_HPP


#include <GLFW/glfw3.h>
#include "../Entities.hpp"

class Player: public Entities{
public:
    Player(const std::vector<float>& vertices): Entities(vertices){};
    void processInputs(GLFWwindow &window);
};


#endif //CPPGAMEDARCUOPENGL_PLAYER_HPP
