//
// Created by francisc on 11/13/24.
//

#ifndef CPPGAMEDARCUOPENGL_GRAPHICS_HPP
#define CPPGAMEDARCUOPENGL_GRAPHICS_HPP

#include <vector>

class Graphics{
    std::vector<float> vertices;
    std::vector<unsigned int> indices;
public:
    explicit Graphics(const std::vector<float>& vertices, const std::vector<unsigned int>& indices = {}):
    vertices(vertices), indices(indices) {};
    std::vector<float>getVertices(){ return vertices; };
    std::vector<unsigned int>getIndices(){ return indices; };
    [[nodiscard]] float getWidth() const {
        if (vertices.empty()) return 0.0f;
        float minX = vertices[0];
        float maxX = vertices[0];
        for (size_t i = 0; i < vertices.size(); i += 6) {
            float x = vertices[i];
            if (x < minX) minX = x;
            if (x > maxX) maxX = x;
        }
        return maxX - minX;
    }
    [[nodiscard]] float getHeight() const {
        if (vertices.empty()) return 0.0f;
        float minY = vertices[1];
        float maxY = vertices[1];
        for (size_t i = 1; i < vertices.size(); i += 6) {
            float y = vertices[i];
            if (y < minY) minY = y;
            if (y > maxY) maxY = y;
        }
        return maxY - minY;
    }
};


#endif //CPPGAMEDARCUOPENGL_GRAPHICS_HPP
