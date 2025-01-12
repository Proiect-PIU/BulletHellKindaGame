
#ifndef CPPGAMEDARCUOPENGL_MENU_HPP
#define CPPGAMEDARCUOPENGL_MENU_HPP


#include <glm/vec4.hpp>

class Menu {
public:
    enum Options{PLAY, EXIT} option;
    bool selected = false;

    explicit Menu(glm::vec4 color);
    void addButton();
    bool processInputs();
    ~Menu() = default;
};


#endif //CPPGAMEDARCUOPENGL_MENU_HPP
