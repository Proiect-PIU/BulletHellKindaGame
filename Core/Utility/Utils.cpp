//
// Created by francisc on 10/10/24.
//

#include <valarray>
#include <thread>
#include <iostream>
#include <cstdlib>
#include "Utils.hpp"

std::vector<float> Utils::generateCircleVertices(float cx, float cy, float cz, float radius, int numSegments,
                                                 const glm::vec3 &centerColor, const glm::vec3 &edgeColor) {
    std::vector<float> vertices;

    vertices.push_back(cx);
    vertices.push_back(cy);
    vertices.push_back(cz);

    vertices.push_back(centerColor.r);
    vertices.push_back(centerColor.g);
    vertices.push_back(centerColor.b);

    for (int i = 0; i <= numSegments; ++i) {
        float angle = 2.0f * M_PI * i / numSegments;
        float x = cx + radius * cos(angle);
        float y = cy + radius * sin(angle);

        vertices.push_back(x);
        vertices.push_back(y);
        vertices.push_back(cz);

        vertices.push_back(edgeColor.r);
        vertices.push_back(edgeColor.g);
        vertices.push_back(edgeColor.b);
    }

    return vertices;
}

const int FPS = 120;
const std::chrono::milliseconds frameDuration(1000 / FPS);
void Utils::capFrameRate(const std::chrono::steady_clock::time_point &frameStart) {
    auto frameEnd = std::chrono::steady_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(frameEnd - frameStart);
    auto delayTime = frameDuration - elapsedTime;

    if (delayTime.count() > 0) {
        std::this_thread::sleep_for(delayTime);
    }
}

float Utils::randRange(float min, float max) {
    return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}

bool polygonPolygonCollision(const Shape& polyA, const Shape& polyB) {
    float margin = 0.02f;

    float adjustedEastA  = polyA.east  - margin;
    float adjustedWestA  = polyA.west  + margin;
    float adjustedNorthA = polyA.north - margin;
    float adjustedSouthA = polyA.south + margin;

    float adjustedEastB  = polyB.east  - margin;
    float adjustedWestB  = polyB.west  + margin;
    float adjustedNorthB = polyB.north - margin;
    float adjustedSouthB = polyB.south + margin;

    bool separatedHorizontally = adjustedWestA > adjustedEastB || adjustedEastA < adjustedWestB;
    bool separatedVertically   = adjustedSouthA > adjustedNorthB || adjustedNorthA < adjustedSouthB;

    return !(separatedHorizontally || separatedVertically);
}


#define TYPE Shape::ShapeType
bool Utils::shapesCollide(const Shape& shapeA, const Shape& shapeB) {
    if (shapeA.type == TYPE::POLYGON && shapeB.type == TYPE::POLYGON)
        return polygonPolygonCollision(shapeA, shapeB);
    return false;
}
#undef TYPE
