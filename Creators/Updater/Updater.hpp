//
// Created by francisc on 11/24/24.
//

#ifndef CPPGAMEDARCUOPENGL_UPDATER_HPP
#define CPPGAMEDARCUOPENGL_UPDATER_HPP


#include "../../Levels/Level.hpp"

class Updater{
public:
    Updater()= default;
    void update(Level &level, Canvas &canvas, float deltaTime, GLFWwindow &window);
};


#endif //CPPGAMEDARCUOPENGL_UPDATER_HPP
