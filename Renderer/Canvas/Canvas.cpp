//
// Created by francisc on 10/10/24.
//

#include "Canvas.hpp"

void Canvas::addElement(std::unique_ptr<Element> e) {
    elementList.push_back(std::move(e));
}

Element *Canvas::getElement(int n) {
    if (n >= 0 && n < elementList.size()) {
        return elementList[n].get();
    }
    return nullptr;
}
void Canvas::setBackground(glm::vec4 color) {
    backgroundColor = color;
}
glm::vec4 Canvas::getBackground() {
    return backgroundColor;
}

const std::vector<std::unique_ptr<Element>> &Canvas::getList() const {
    return elementList;
}

void Canvas::blank() {
    elementList.clear();
}
