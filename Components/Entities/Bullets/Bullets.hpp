//
// Created by francisc on 10/13/24.
//

#ifndef CPPGAMEDARCUOPENGL_BULLETS_HPP
#define CPPGAMEDARCUOPENGL_BULLETS_HPP


#include <glm/vec3.hpp>
#include "../../../Renderer/Canvas/Element/Element.hpp"
#include "../../../Core/Utility/Collision/Shape.hpp"
#include "../../Collisions/Squares/SquareState.hpp"

class Bullets{
public:
    float lifespan;
    float speed;
    float angle;
    glm::vec3 pos;
    Element *element;
    Shape *shape;
    SquareState state;
    Bullets(SquareState state, float lifespan, float speed, Element *e, Shape *s, glm::vec3 pos, float angle):
    state(state), lifespan(lifespan), speed(speed), element(e), shape(s), pos(pos), angle(angle) {};
    ~Bullets(){
        if(!element)
            delete element;
        element = nullptr;
        if(!shape)
            delete shape;
        shape = nullptr;
    }
};


#endif //CPPGAMEDARCUOPENGL_BULLETS_HPP
