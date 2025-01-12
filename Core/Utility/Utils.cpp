//
// Created by francisc on 10/10/24.
//

#include <valarray>
#include <thread>
#include <iostream>
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

std::vector<glm::vec3> extractPositions(const std::vector<float>& vertices) {
    std::vector<glm::vec3> positions;
    size_t stride = 6;
    for (size_t i = 0; i + 5 < vertices.size(); i += stride) {
        float x = vertices[i];
        float y = vertices[i + 1];
        float z = vertices[i + 2];
        positions.emplace_back(x, y, z);
    }
    return positions;
}

bool pointInPolygon(const glm::vec2& point, const std::vector<glm::vec2>& vertices) {
    bool inside = false;
    size_t count = vertices.size();
    for (size_t i = 0, j = count - 1; i < count; j = i++) {
        if (((vertices[i].y > point.y) != (vertices[j].y > point.y)) &&
            (point.x < (vertices[j].x - vertices[i].x) * (point.y - vertices[i].y) /
                       (vertices[j].y - vertices[i].y) + vertices[i].x)) {
            inside = !inside;
        }
    }
    return inside;
}

bool polygonPolygonCollision(const Shape& polyA, const Shape& polyB) {
    float margin = 0.01f;
    float adjustedEastA = polyA.east - margin;
    float adjustedWestA = polyA.west + margin;
    float adjustedNorthA = polyA.north - margin;
    float adjustedSouthA = polyA.south + margin;

    float adjustedEastB = polyB.east - margin;
    float adjustedWestB = polyB.west + margin;
    float adjustedNorthB = polyB.north - margin;
    float adjustedSouthB = polyB.south + margin;

    if (adjustedEastA > adjustedWestB && adjustedEastA < adjustedEastB &&
        adjustedNorthA > adjustedSouthB && adjustedNorthA < adjustedNorthB)
        return true;
    if (adjustedWestA > adjustedWestB && adjustedWestA < adjustedEastB &&
        adjustedNorthA > adjustedSouthB && adjustedNorthA < adjustedNorthB)
        return true;
    if (adjustedEastA > adjustedWestB && adjustedEastA < adjustedEastB &&
        adjustedSouthA > adjustedSouthB && adjustedSouthA < adjustedNorthB)
        return true;
    if (adjustedWestA > adjustedWestB && adjustedWestA < adjustedEastB &&
        adjustedSouthA > adjustedSouthB && adjustedSouthA < adjustedNorthB)
        return true;

    return false;
}

bool circleCircleCollision(const Shape& circleA, const Shape& circleB) {
    glm::vec2 centerA(circleA.center.x, circleA.center.y);
    glm::vec2 centerB(circleB.center.x, circleB.center.y);
    float distance = glm::length(centerA - centerB);
    return distance <= (circleA.radius + circleB.radius);
}

bool circlePolygonCollision(const Shape& circle, const Shape& polygon) {
    std::vector<glm::vec3> polygonVertices = extractPositions(polygon.vertices);
    std::vector<glm::vec2> polygonVertices2D;
    for (const auto& pos : polygonVertices) polygonVertices2D.emplace_back(pos.x, pos.y);

    glm::vec2 circleCenter(circle.center.x, circle.center.y);
    float radius = circle.radius;

    if (pointInPolygon(circleCenter, polygonVertices2D)) {
        return true;
    }
    for (size_t i = 0; i < polygonVertices2D.size(); ++i) {
        glm::vec2 p1 = polygonVertices2D[i];
        glm::vec2 p2 = polygonVertices2D[(i + 1) % polygonVertices2D.size()];
        glm::vec2 edge = p2 - p1;
        glm::vec2 toCenter = circleCenter - p1;
        float t = glm::dot(toCenter, edge) / glm::dot(edge, edge);
        t = glm::clamp(t, 0.0f, 1.0f);
        glm::vec2 closestPoint = p1 + t * edge;
        float distance = glm::length(circleCenter - closestPoint);
        if (distance <= radius) {
            return true;
        }
    }
    return false;
}

#define TYPE Shape::ShapeType
bool Utils::shapesCollide(const Shape& shapeA, const Shape& shapeB) {
    if (shapeA.type == TYPE::POLYGON && shapeB.type == TYPE::POLYGON)
        return polygonPolygonCollision(shapeA, shapeB);
//    } else if (shapeA.type == TYPE::CIRCLE && shapeB.type == TYPE::CIRCLE) {
//        return circleCircleCollision(shapeA, shapeB);
//    } else if (shapeA.type == TYPE::CIRCLE && shapeB.type == TYPE::POLYGON) {
//        return circlePolygonCollision(shapeA, shapeB);
//    } else if (shapeA.type == TYPE::POLYGON && shapeB.type == TYPE::CIRCLE) {
//        return circlePolygonCollision(shapeB, shapeA);
//    }
    return false;
}
#undef TYPE
