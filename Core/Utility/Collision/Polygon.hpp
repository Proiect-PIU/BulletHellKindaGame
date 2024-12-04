//
// Created by francisc on 11/16/24.
//

#ifndef CPPGAMEDARCUOPENGL_POLYGON_HPP
#define CPPGAMEDARCUOPENGL_POLYGON_HPP

#include "Shape.hpp"

class Polygon: public Shape{
public:
    Polygon(const std::vector<float> &vertices, glm::mat4 transform = glm::mat4(1.0f))
    : Shape(vertices, ShapeType::POLYGON, transform) {};
    void transformShapeToWorld()  {
        Polygon transformedShape = *this;
        transformedShape.transform = glm::mat4(1.0f);
        //x y z r g b: ordinea punctelor
        size_t step = 6;
        std::vector<float> transformedVertices;
        for (size_t i = 0; i + 5 < this->vertices.size(); i += step) {
            glm::vec4 localVertex(this->vertices[i],
                                  this->vertices[i + 1],
                                  this->vertices[i + 2],
                                  1.0f);
            glm::vec4 worldVertex = this->transform * localVertex;

            transformedVertices.push_back(worldVertex.x);
            transformedVertices.push_back(worldVertex.y);
            transformedVertices.push_back(worldVertex.z);

            transformedVertices.push_back(this->vertices[i + 3]);
            transformedVertices.push_back(this->vertices[i + 4]);
            transformedVertices.push_back(this->vertices[i + 5]);
        }
        transformedShape.vertices = transformedVertices;
        *this = transformedShape;
    }
};

#endif //CPPGAMEDARCUOPENGL_POLYGON_HPP
