//
// Created by francisc on 10/9/24.
//

#ifndef CPPGAMEDARCUOPENGL_ELEMENT_HPP
#define CPPGAMEDARCUOPENGL_ELEMENT_HPP


#include <vector>
#include <glm/gtc/matrix_transform.hpp>


class Element{
    unsigned int VBO, VAO, EBO;
    std::vector<float> vertices;
    size_t vertexCount;
    std::vector<unsigned int> indices;
    size_t indexCount;
    glm::mat4 modelMatrix;
    glm::vec3 position;
    float rotationAngle;
    glm::vec3 rotationAxis;
    glm::vec3 scale;
public:
    Element(const std::vector<float>& vertices, const std::vector<unsigned int>& indices = {});
    Element(const Element& other);
    ~Element();
    void loadElement();
    void setPosition(const glm::vec3& newPos);
    void setRotation(float angle, const glm::vec3& axis);
    void setScale(const glm::vec3& newScale);
    void updateModelMatrix();
    [[nodiscard]] unsigned int getVAO() const{ return VAO;}
    [[nodiscard]] size_t getVertexCount() const { return vertexCount; }
    [[nodiscard]] size_t getIndexCount() const { return indexCount; }
    [[nodiscard]] std::vector<float> getVertices() const { return vertices; }
    [[nodiscard]] std::vector<unsigned int> getIndices() const { return indices; }
    [[nodiscard]] bool hasIndices() const { return !indices.empty(); }
    [[nodiscard]] const glm::mat4& getModelMatrix() const { return modelMatrix; }
    [[nodiscard]] glm::vec3 getPosition() const { return position;};
};


#endif //CPPGAMEDARCUOPENGL_ELEMENT_HPP
