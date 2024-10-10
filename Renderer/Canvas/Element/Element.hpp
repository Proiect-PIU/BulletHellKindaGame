//
// Created by francisc on 10/9/24.
//

#ifndef CPPGAMEDARCUOPENGL_ELEMENT_HPP
#define CPPGAMEDARCUOPENGL_ELEMENT_HPP


#include <vector>

class Element{
    unsigned int VBO, VAO, EBO;
    std::vector<float> vertices;
    size_t vertexCount;
    std::vector<unsigned int> indices;
    size_t indexCount;
public:
    Element(const std::vector<float>& vertices, const std::vector<unsigned int>& indices = {});
    ~Element();
    void loadElement();
    [[nodiscard]] unsigned int getVAO() const{ return VAO;}
    [[nodiscard]] size_t getVertexCount() const { return vertexCount; }
    [[nodiscard]] size_t getIndexCount() const { return indexCount; }
    [[nodiscard]] bool hasIndices() const { return !indices.empty(); }
};


#endif //CPPGAMEDARCUOPENGL_ELEMENT_HPP
