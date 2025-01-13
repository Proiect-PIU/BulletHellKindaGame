
#ifndef CPPGAMEDARCUOPENGL_MENULOGIC_HPP
#define CPPGAMEDARCUOPENGL_MENULOGIC_HPP


#include "../Logic.hpp"
#include "../../Core/Menu/Menu.hpp"

class MenuLogic: public Logic {
    Menu *menu;
public:
    MenuLogic();
    int processLogic(int &option) override;
    ~MenuLogic() override;
};


#endif //CPPGAMEDARCUOPENGL_MENULOGIC_HPP
