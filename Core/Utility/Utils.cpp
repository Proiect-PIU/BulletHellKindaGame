//
// Created by francisc on 10/10/24.
//

#include <valarray>
#include <thread>
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

const int FPS = 144;
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
    std::vector<glm::vec3> verticesA = extractPositions(polyA.vertices);
    std::vector<glm::vec3> verticesB = extractPositions(polyB.vertices);

    std::vector<glm::vec2> verticesA2D, verticesB2D;
    for (const auto& pos : verticesA) verticesA2D.emplace_back(pos.x, pos.y);
    for (const auto& pos : verticesB) verticesB2D.emplace_back(pos.x, pos.y);
    std::vector<glm::vec2> axes;

    auto addAxes = [](const std::vector<glm::vec2>& vertices, std::vector<glm::vec2>& axes) {
        for (size_t i = 0; i < vertices.size(); ++i) {
            glm::vec2 p1 = vertices[i];
            glm::vec2 p2 = vertices[(i + 1) % vertices.size()];
            glm::vec2 edge = p2 - p1;
            glm::vec2 normal(-edge.y, edge.x); // Perpendicular
            axes.push_back(glm::normalize(normal));
        }
    };
    addAxes(verticesA2D, axes);
    addAxes(verticesB2D, axes);
    for (const auto& axis : axes) {
        float minA = std::numeric_limits<float>::max();
        float maxA = std::numeric_limits<float>::lowest();
        for (const auto& vertex : verticesA2D) {
            float projection = glm::dot(vertex, axis);
            minA = std::min(minA, projection);
            maxA = std::max(maxA, projection);
        }
        float minB = std::numeric_limits<float>::max();
        float maxB = std::numeric_limits<float>::lowest();
        for (const auto& vertex : verticesB2D) {
            float projection = glm::dot(vertex, axis);
            minB = std::min(minB, projection);
            maxB = std::max(maxB, projection);
        }
        if (maxA < minB || maxB < minA) {
            return false;
        }
    }
    return true;
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
    if (shapeA.type == TYPE::POLYGON && shapeB.type == TYPE::POLYGON) {
        return polygonPolygonCollision(shapeA, shapeB);
    } else if (shapeA.type == TYPE::CIRCLE && shapeB.type == TYPE::CIRCLE) {
        return circleCircleCollision(shapeA, shapeB);
    } else if (shapeA.type == TYPE::CIRCLE && shapeB.type == TYPE::POLYGON) {
        return circlePolygonCollision(shapeA, shapeB);
    } else if (shapeA.type == TYPE::POLYGON && shapeB.type == TYPE::CIRCLE) {
        return circlePolygonCollision(shapeB, shapeA);
    }
    return false;
}
#undef TYPE
