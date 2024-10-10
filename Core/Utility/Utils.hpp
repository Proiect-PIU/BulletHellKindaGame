//
// Created by francisc on 10/10/24.
//

#ifndef CPPGAMEDARCUOPENGL_UTILS_HPP
#define CPPGAMEDARCUOPENGL_UTILS_HPP


#include <vector>
#include <glm/glm.hpp>

class Utils{
public:
    Utils()= default;
    static std::vector<float> generateCircleVertices(
            float cx, float cy, float cz,
            float radius, int numSegments,
            const glm::vec3& centerColor,
            const glm::vec3& edgeColor
    );
};


#endif //CPPGAMEDARCUOPENGL_UTILS_HPP
