//
// Created by francisc on 10/15/24.
//

#ifndef CPPGAMEDARCUOPENGL_SHAPE_HPP
#define CPPGAMEDARCUOPENGL_SHAPE_HPP


#include <glm/ext/matrix_float4x4.hpp>
#include <vector>

class Shape{
public:
    glm::vec3 center;
    float radius;
    float north = -2;
    float south = 2;
    float east = -2;
    float west = 2;

    enum ShapeType{POLYGON, CIRCLE} type;
    glm::mat4 transform;
    std::vector<float> vertices;
    Shape(const std::vector<float>& vertices, ShapeType type, glm::mat4 transform = glm::mat4(1.0f))
    : type(type), transform(transform){
        int step = 6;
        if(type == ShapeType::POLYGON)
            for (int i = 0; i < vertices.size(); i += step) {
                glm::vec4 transformedVertex = transform * glm::vec4(vertices[i], vertices[i + 1], vertices[i + 2], 1.0f);
                this->vertices.push_back(transformedVertex.x);
                this->vertices.push_back(transformedVertex.y);
                this->vertices.push_back(transformedVertex.z);
            }
        else {
            glm::vec4 localCenter(glm::vec3(vertices[0], vertices[1], vertices[2]), 1.0f);
            this->center = glm::vec3(this->transform * localCenter);
            this->radius = glm::length(glm::vec3(this->transform[step]));
        }
        for (int i = 0; i < vertices.size(); i += step) {
            if(vertices[i + 1] > north)
                north = vertices[i + 1];
            if(vertices[i + 1] < south)
                south = vertices[i + 1];
            if(vertices[i] > east)
                east = vertices[i];
            if(vertices[i] < west)
                west = vertices[i];
        }
    };
};

#endif //CPPGAMEDARCUOPENGL_SHAPE_HPP
