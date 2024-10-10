//
// Created by francisc on 10/10/24.
//

#ifndef CPPGAMEDARCUOPENGL_RENDERER_HPP
#define CPPGAMEDARCUOPENGL_RENDERER_HPP


#include "Canvas/Canvas.hpp"

class Renderer{
public:
    Renderer(){};
    static void drawCanvas(Canvas &c, unsigned int shaderProgram);
};


#endif //CPPGAMEDARCUOPENGL_RENDERER_HPP
