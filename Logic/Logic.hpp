//
// Created by francisc on 10/10/24.
//

#ifndef CPPGAMEDARCUOPENGL_LOGIC_HPP
#define CPPGAMEDARCUOPENGL_LOGIC_HPP


#include <GLFW/glfw3.h>
#include "../Renderer/Canvas/Canvas.hpp"

class Logic{
public:
    virtual void processLogic(Canvas &c, GLFWwindow &window) = 0;
    virtual ~Logic() = default;
};


#endif //CPPGAMEDARCUOPENGL_LOGIC_HPP
