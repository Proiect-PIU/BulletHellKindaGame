//
// Created by francisc on 10/9/24.
//

#include <GL/glew.h>
#include <iostream>
#include "Element.hpp"

Element::Element(const std::vector<float>& vertices, const std::vector<unsigned int>& indices)
        : vertices(vertices), vertexCount(vertices.size()),
          indices(indices), indexCount(indices.size()),
          VAO(0), VBO(0), EBO(0), modelMatrix(glm::mat4(1.0f)) {
    loadElement();
}
Element::Element(const Element& other)
        : vertices(other.vertices),
          vertexCount(other.vertexCount),
          indices(other.indices),
          indexCount(other.indexCount),
          VAO(0), VBO(0), EBO(0),
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

void Element::setPosition(const glm::vec3& position) {
    modelMatrix = glm::translate(glm::mat4(1.0f), position);
}

void Element::setRotation(float angle, const glm::vec3& axis) {
    modelMatrix = glm::rotate(glm::mat4(1.0f), angle, axis);
}

void Element::setScale(const glm::vec3& scale) {
    modelMatrix = glm::scale(glm::mat4(1.0f), scale);
}