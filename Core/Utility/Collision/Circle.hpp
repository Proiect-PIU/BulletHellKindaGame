//
// Created by francisc on 11/16/24.
//

#ifndef CPPGAMEDARCUOPENGL_CIRCLE_HPP
#define CPPGAMEDARCUOPENGL_CIRCLE_HPP

#include "Shape.hpp"

class Circle: public Shape{
public:
    Circle(const std::vector<float>& vertices, glm::mat4 transform = glm::mat4(1.0f))
    : Shape(vertices, ShapeType::CIRCLE, transform){
        center = glm::vec3(vertices[0], vertices[1], vertices[2]);

        //primul punct de pe cerc
        float px = vertices[6];
        float py = vertices[7];
        float pz = vertices[8];

        glm::vec3 perimeterPoint(px, py, pz);
        radius = glm::length(perimeterPoint - center);
        this->vertices = vertices;
    }
    void transformShapeToWorld() override {
        Circle transformedCircle = *this;
        transformedCircle.transform = glm::mat4(1.0f);

        glm::vec4 localCenter(this->center, 1.0f);
        glm::vec4 worldCenter = this->transform * localCenter;
        transformedCircle.center = glm::vec3(worldCenter);

        float scaleX = glm::length(glm::vec3(this->transform[0]));
        float scaleY = glm::length(glm::vec3(this->transform[1]));
        float scaleZ = glm::length(glm::vec3(this->transform[2]));
        float averageScale = (scaleX + scaleY + scaleZ) / 3.0f;

        transformedCircle.radius = this->radius * averageScale;
        *this = transformedCircle;
    }
};

#endif //CPPGAMEDARCUOPENGL_CIRCLE_HPP
