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

    enum ShapeType{POLYGON, CIRCLE} type;
    glm::mat4 transform;
    std::vector<float> vertices;
    Shape(const std::vector<float>& vertices, ShapeType type, glm::mat4 transform = glm::mat4(1.0f))
    : vertices(vertices), type(type), transform(transform){};
};

#endif //CPPGAMEDARCUOPENGL_SHAPE_HPP
