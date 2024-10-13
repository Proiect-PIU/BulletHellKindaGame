//
// Created by francisc on 10/13/24.
//

#ifndef CPPGAMEDARCUOPENGL_BULLETS_HPP
#define CPPGAMEDARCUOPENGL_BULLETS_HPP


#include <glm/vec3.hpp>

class Bullets{
public:
    float lifespan;
    float speed;
    float angle;

    int updateInterval;
    int updateCounter;
    glm::vec3 pos;
    Bullets(float lifespan, float speed, glm::vec3 pos, float angle):
    lifespan(lifespan), speed(speed), pos(pos), angle(angle) {};
};


#endif //CPPGAMEDARCUOPENGL_BULLETS_HPP
