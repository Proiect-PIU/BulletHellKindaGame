//
// Created by francisc on 10/10/24.
//

#include <GL/glew.h>
#include "Renderer.hpp"
#include <glm/gtc/type_ptr.hpp>

void Renderer::drawCanvas(Canvas &c, unsigned int shaderProgram) {
    const auto& elementList = c.getList();

    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);

    unsigned int modelLoc = glGetUniformLocation(shaderProgram, "model");
    unsigned int viewLoc = glGetUniformLocation(shaderProgram, "view");
    unsigned int projLoc = glGetUniformLocation(shaderProgram, "projection");

    glUseProgram(shaderProgram);
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

    for (const auto& element : elementList) {
        glClearColor(0.5f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glBindVertexArray(element->getVAO());
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(element->getModelMatrix()));
        if(element->hasIndices()){
            glDrawElements(GL_TRIANGLES, element->getIndexCount(), GL_UNSIGNED_INT, 0);
        } else {
            glDrawArrays(GL_TRIANGLE_FAN, 0, element->getVertexCount() / 6);
        }
    }
}
