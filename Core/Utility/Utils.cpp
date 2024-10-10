//
// Created by francisc on 10/10/24.
//

#include <valarray>
#include "Utils.hpp"


class vec3;

std::vector<float>
Utils::generateCircleVertices(float cx, float cy, float cz, float radius, int numSegments, const glm::vec3 &centerColor,
                              const glm::vec3 &edgeColor) {
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
