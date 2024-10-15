//
// Created by francisc on 10/15/24.
//

#ifndef CPPGAMEDARCUOPENGL_PATTERN_HPP
#define CPPGAMEDARCUOPENGL_PATTERN_HPP


#include "../../../../Renderer/Canvas/Canvas.hpp"
#include "../Bullets.hpp"
#include <cmath>

class Pattern{
protected:
    int nrOfBullets;
public:
    Pattern(int nrOfBullets): nrOfBullets(nrOfBullets) {};
    virtual void updatePattern(float deltaTime, Canvas &canvas, Bullets &bullet, Element *w) = 0;
    ~Pattern() = default;
};


#endif //CPPGAMEDARCUOPENGL_PATTERN_HPP
