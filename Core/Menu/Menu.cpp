
#include "Menu.hpp"
#include "Loader/Loader.hpp"
#include "../Utility/Utils.hpp"

Menu::Menu(glm::vec4 color) {
    Canvas* canvas = Loader::getInstance().getCanvas();
    canvas->setBackground(color);
}

bool Menu::processInputs() {
    GLFWwindow* window = Loader::getInstance().getWindow();
    static bool keyUpReleased = true;
    static bool keyDownReleased = true;
    static bool keyEnterReleased = true;

    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS && keyUpReleased) {
        keyUpReleased = false;
        option++;
        if (option >= nrOptions) {
            option = 0;
        }
    }
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_RELEASE) {
        keyUpReleased = true;
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS && keyDownReleased) {
        keyDownReleased = false;
        option--;
        if (option < 0) {
            option = nrOptions - 1;
        }
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_RELEASE) {
        keyDownReleased = true;
    }
    if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS && keyEnterReleased) {
        keyEnterReleased = false;
        selected = true;
    }
    if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_RELEASE) {
        keyEnterReleased = true;
    }

    std::cout << option << '\n';
    return selected;
}

void Menu::addMenuButtons() {
    Canvas* canvas = Loader::getInstance().getCanvas();
    const auto& data = Loader::getInstance().getData();
    Graphics *button_1, *button_2;
    if(option == 1) {
        button_1 = new Graphics(data.at("play_select").first, data.at("play_select").second);
        button_2 = new Graphics(data.at("exit").first, data.at("exit").second);
    } else {
        button_1 = new Graphics(data.at("play").first, data.at("play").second);
        button_2 = new Graphics(data.at("exit_select").first, data.at("exit_select").second);
    }

    std::unique_ptr<Element> element_1 = std::make_unique<Element>(button_1);
    std::unique_ptr<Element> element_2 = std::make_unique<Element>(button_2);
    glm::vec3 scale(4.0, 4.0, 0.0);
    element_1->setScale(scale);
    element_2->setScale(scale);
    element_2->setPosition(glm::vec3(0.0, -0.4, 0.0));

    canvas->addElement(std::move(element_1));
    canvas->addElement(std::move(element_2));
}

void Menu::addLevelButtons() {
    static float pulsingRadius = 0.08;
    static bool dir = false;
    float radius[] = {0.08, 0.08, 0.08, 0.08};
    Canvas* canvas = Loader::getInstance().getCanvas();

    radius[0] = (option == 3) ? pulsingRadius : radius[0];
    auto *button1 = new Graphics(Utils::generateCircleVertices(
            0.0, 0.7, 0.0, radius[0], 12,
            glm::vec3(0.9, 0.9, 0.9), glm::vec3(0.9, 0.9, 0.9))
    );
    radius[1] = (option == 2) ? pulsingRadius : radius[1];
    auto *button2 = new Graphics(Utils::generateCircleVertices(
            0.0, -0.1, 0.0, radius[1], 12,
            glm::vec3(0.9, 0.9, 0.9), glm::vec3(0.9, 0.9, 0.9))
    );
    radius[2] = (option == 1) ? pulsingRadius : radius[2];
    auto *button3 = new Graphics(Utils::generateCircleVertices(
            0.0, -0.4, 0.0, radius[2], 12,
            glm::vec3(0.9, 0.9, 0.9), glm::vec3(0.9, 0.9, 0.9))
    );
    radius[3] = (option == 0) ? pulsingRadius : radius[3];
    auto *button4 = new Graphics(Utils::generateCircleVertices(
            0.0, -0.88, 0.0, radius[3], 12,
            glm::vec3(0.9, 0.9, 0.9), glm::vec3(0.9, 0.9, 0.9))
    );
    if(dir) {
        pulsingRadius += 0.001;
        if (pulsingRadius >= 0.08) {
            dir = false;
        }
    } else {
        pulsingRadius -= 0.001;
        if (pulsingRadius <= 0.05) {
            dir = true;
        }
    }

    std::unique_ptr<Element> element1 = std::make_unique<Element>(button1);
    std::unique_ptr<Element> element2 = std::make_unique<Element>(button2);
    std::unique_ptr<Element> element3 = std::make_unique<Element>(button3);
    std::unique_ptr<Element> element4 = std::make_unique<Element>(button4);

    canvas->addElement(std::move(element1));
    canvas->addElement(std::move(element2));
    canvas->addElement(std::move(element3));
    canvas->addElement(std::move(element4));
}

void Menu::addBackground() {
    Canvas* canvas = Loader::getInstance().getCanvas();
    const auto& data = Loader::getInstance().getData();
    auto *button = new Graphics(data.at("body_map").first,
                                data.at("body_map").second);
    std::unique_ptr<Element> element = std::make_unique<Element>(button);
    float scale = 9.0;
    element->setScale(glm::vec3(scale, scale, 0.0f));

    canvas->addElement(std::move(element));
}
