//
// Created by francisc on 10/9/24.
//

#include <GL/glew.h>
#include <iostream>
#include "Element.hpp"

Element::Element(const std::vector<float>& vertices, const std::vector<unsigned int>& indices)
        : vertices(vertices), vertexCount(vertices.size()),
          indices(indices), indexCount(indices.size()),
          VAO(0), VBO(0), EBO(0), position(0.0f, 0.0f, 0.0f),
          rotationAngle(0.0f),
          rotationAxis(0.0f, 0.0f, 1.0f),
          scale(1.0f, 1.0f, 1.0f),
          modelMatrix(glm::mat4(1.0f)) {
    loadElement();
}
Element::Element(const Element& other)
        : vertices(other.vertices),
          vertexCount(other.vertexCount),
          indices(other.indices),
          indexCount(other.indexCount),
          VAO(0), VBO(0), EBO(0),
          position(other.position),
          rotationAngle(other.rotationAngle),
          rotationAxis(other.rotationAxis),
          scale(other.scale),
          modelMatrix(other.modelMatrix) {
    loadElement();
}

void Element::loadElement() {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    if (hasIndices()) {
        glGenBuffers(1, &EBO);
    }

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    if (hasIndices()) {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);
    }

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)nullptr);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}

Element::~Element() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    if (hasIndices()) {
        glDeleteBuffers(1, &EBO);
    }
}
void Element::updateModelMatrix() {
    modelMatrix = glm::mat4(1.0f);
    modelMatrix = glm::translate(modelMatrix, position);
    modelMatrix = glm::rotate(modelMatrix, rotationAngle, rotationAxis);
    modelMatrix = glm::scale(modelMatrix, scale);
}

void Element::setPosition(const glm::vec3& newPos) {
    position = newPos;
    updateModelMatrix();
}

void Element::setRotation(float angle, const glm::vec3& axis) {
    rotationAngle = angle;
    rotationAxis = axis;
    updateModelMatrix();
}

void Element::setScale(const glm::vec3& newScale) {
    scale = newScale;
    updateModelMatrix();
}