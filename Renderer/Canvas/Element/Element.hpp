//
// Created by francisc on 10/9/24.
//

#ifndef CPPGAMEDARCUOPENGL_ELEMENT_HPP
#define CPPGAMEDARCUOPENGL_ELEMENT_HPP


#include <vector>
#include <glm/gtc/matrix_transform.hpp>
#include "../../../Persistance/Data/Geometry/Graphics.hpp"


class Element{
    unsigned int VBO, VAO, EBO;
    Graphics *graphics;
    glm::mat4 modelMatrix;
    glm::vec3 position;
    float rotationAngle;
    glm::vec3 rotationAxis;
    glm::vec3 scale;
public:
    explicit Element(Graphics *graphics);
    Element(const Element& other);
    ~Element();
    void loadElement();
    void setPosition(const glm::vec3& newPos);
    void setRotation(float angle, const glm::vec3& axis);
    void setScale(const glm::vec3& newScale);
    void updateModelMatrix();
    [[nodiscard]] unsigned int getVAO() const{ return VAO;}
    [[nodiscard]] Graphics* getGraphics() const { return graphics; }
    [[nodiscard]] bool hasIndices() const { return !graphics->getIndices().empty(); }
    [[nodiscard]] const glm::mat4& getModelMatrix() const { return modelMatrix; }
    [[nodiscard]] glm::vec3 getPosition() const { return position;};
    [[nodiscard]] glm::vec3 getScale() const { return scale;};
};


#endif //CPPGAMEDARCUOPENGL_ELEMENT_HPP
