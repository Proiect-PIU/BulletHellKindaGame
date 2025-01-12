
#ifndef CPPGAMEDARCUOPENGL_MENU_HPP
#define CPPGAMEDARCUOPENGL_MENU_HPP


#include <glm/vec4.hpp>

class Menu {
public:
    static int option;
    int nrOptions;
    bool selected = false;

    explicit Menu(glm::vec4 color);
    void addMenuButtons();
    void addLevelButtons();
    void addBackground();
    bool processInputs();
    ~Menu() = default;
};

#endif //CPPGAMEDARCUOPENGL_MENU_HPP
