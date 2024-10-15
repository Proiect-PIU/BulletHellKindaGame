//
// Created by francisc on 10/10/24.
//

#ifndef CPPGAMEDARCUOPENGL_UTILS_HPP
#define CPPGAMEDARCUOPENGL_UTILS_HPP


#include <vector>
#include <glm/glm.hpp>
#include <chrono>
#include "Collision/Shape.hpp"

enum Directions: int {UP = 0b1000, DOWN = 0b0100, LEFT = 0b0010, RIGHT = 0b0001, NONE = 0};

class Utils{
public:
    Utils()= default;
    static std::vector<float> generateCircleVertices(
            float cx, float cy, float cz,
            float radius, int numSegments,
            const glm::vec3& centerColor,
            const glm::vec3& edgeColor
    );
    static void capFrameRate(const std::chrono::steady_clock::time_point& frameStart);
    bool shapesCollide(const Shape& shapeA, const Shape& shapeB);
};


#endif //CPPGAMEDARCUOPENGL_UTILS_HPP
