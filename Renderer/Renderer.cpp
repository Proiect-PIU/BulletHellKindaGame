//
// Created by francisc on 10/10/24.
//

#include <GL/glew.h>
#include "Renderer.hpp"

void Renderer::drawCanvas(Canvas &c, unsigned int shaderProgram) {
    const auto& elementList = c.getList();

    glClearColor(0.5f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(shaderProgram);

    for (const auto& element : elementList) {
        glBindVertexArray(element->getVAO());
        if(element->hasIndices()){
            glDrawElements(GL_TRIANGLES, element->getIndexCount(), GL_UNSIGNED_INT, 0);
        } else {
            glDrawArrays(GL_TRIANGLE_FAN, 0, element->getVertexCount() / 6);
        }
    }
}
