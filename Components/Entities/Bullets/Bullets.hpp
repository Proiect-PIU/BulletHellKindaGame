//
// Created by francisc on 10/13/24.
//

#ifndef CPPGAMEDARCUOPENGL_BULLETS_HPP
#define CPPGAMEDARCUOPENGL_BULLETS_HPP


#include <glm/vec3.hpp>
#include "../../../Renderer/Canvas/Element/Element.hpp"

class Bullets{
public:
    float lifespan;
    float speed;
    float angle;
    glm::vec3 pos;
    Element *element;
    Bullets(float lifespan, float speed, Element *e, glm::vec3 pos, float angle):
    lifespan(lifespan), speed(speed), element(e), pos(pos), angle(angle) {};
    ~Bullets(){
        if(!element)
            delete element;
        element = nullptr;
    }
};


#endif //CPPGAMEDARCUOPENGL_BULLETS_HPP
