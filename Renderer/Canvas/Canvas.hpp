//
// Created by francisc on 10/10/24.
//

#ifndef CPPGAMEDARCUOPENGL_CANVAS_HPP
#define CPPGAMEDARCUOPENGL_CANVAS_HPP


#include <vector>
#include <memory>
#include "Element/Element.hpp"

class Canvas{
    std::vector<std::unique_ptr<Element>> elementList;
    glm::vec4 backgroundColor = glm::vec4(0.5f, 0.0f, 0.0f, 1.0f);
public:
    Canvas() = default;
    void addElement(std::unique_ptr<Element> e);
    Element* getElement(int n);
    void setBackground(glm::vec4 color);
    glm::vec4 getBackground();
    [[nodiscard]] const std::vector<std::unique_ptr<Element>>& getList() const;
    void blank();
};


#endif //CPPGAMEDARCUOPENGL_CANVAS_HPP
