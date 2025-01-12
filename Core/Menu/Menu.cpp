
#include "Menu.hpp"
#include "Loader/Loader.hpp"

Menu::Menu(glm::vec4 color) {
    Canvas* canvas = Loader::getInstance().getCanvas();
    canvas->setBackground(color);
}

bool Menu::processInputs() {
    GLFWwindow *window = Loader::getInstance().getWindow();
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
        option = (option == EXIT)? PLAY: EXIT;
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        option = (option == EXIT)? PLAY: EXIT;
    }
    if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS) {
        selected = true;
    }
    return selected;
}

void Menu::addButton() {
    Canvas* canvas = Loader::getInstance().getCanvas();
    const auto& data = Loader::getInstance().getData();
    auto *button = new Graphics(data.at("").first, data.at("").second);
    std::unique_ptr<Element> element = std::make_unique<Element>(button);

    canvas->addElement(std::move(element));
}
