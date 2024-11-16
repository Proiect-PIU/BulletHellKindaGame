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
};


#endif //CPPGAMEDARCUOPENGL_GRAPHICS_HPP
