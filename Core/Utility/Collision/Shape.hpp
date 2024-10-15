//
// Created by francisc on 10/15/24.
//

#ifndef CPPGAMEDARCUOPENGL_SHAPE_HPP
#define CPPGAMEDARCUOPENGL_SHAPE_HPP


#include <glm/ext/matrix_float4x4.hpp>
#include <vector>

enum class ShapeType {
    POLYGON,
    CIRCLE
};

class Shape{
public:
    ShapeType type;
    glm::mat4 transform;
    std::vector<float> vertices;
    glm::vec3 center;
    float radius;

    // Constructor for polygons
    Shape(const std::vector<float>& vertexData)
            : type(ShapeType::POLYGON), transform(glm::mat4(1.0f)), vertices(vertexData) {}

    // Constructor for circles
    Shape(const std::vector<float>& vertexData, bool isCircle)
            : type(ShapeType::CIRCLE), transform(glm::mat4(1.0f)) {
        // Extract center from the first vertex
        center = glm::vec3(vertexData[0], vertexData[1], vertexData[2]);

        // Extract a perimeter point (second vertex)
        size_t stride = 6; // x, y, z, r, g, b
        float px = vertexData[stride];
        float py = vertexData[stride + 1];
        float pz = vertexData[stride + 2];

        // Calculate radius
        glm::vec3 perimeterPoint(px, py, pz);
        radius = glm::length(perimeterPoint - center);

        // Store the vertices (optional, if needed)
        vertices = vertexData;
    }
};
Shape transformShapeToWorld(const Shape& shape);
bool polygonPolygonCollision(const Shape& polyA, const Shape& polyB);
bool circleCircleCollision(const Shape& circleA, const Shape& circleB);
bool circlePolygonCollision(const Shape& circle, const Shape& polygon);

#endif //CPPGAMEDARCUOPENGL_SHAPE_HPP
