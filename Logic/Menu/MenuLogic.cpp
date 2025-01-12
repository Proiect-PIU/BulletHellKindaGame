
#include "MenuLogic.hpp"
#include "Loader/Loader.hpp"
#include "../../Core/Utility/Enums/GameStates.h"

MenuLogic::MenuLogic() {
    glm::vec4 color = glm::vec4(0.6, 0.3, 0.3, 0.1);
    menu = new Menu(color);
}

int MenuLogic::processLogic(int &option) {
    menu->selected = false;
    switch(option) {
        case 1:
            menu->nrOptions = 2;
            menu->addMenuButtons();
            if(menu->processInputs()) {
                switch(menu->option) {
                    case 0:
                        return LEVEL_MENU;
                    case 1:
                        return EXIT;
                }
            }
            return MAIN_MENU;
        case 2:
            menu->nrOptions = 4;
            menu->addBackground();
            menu->addLevelButtons();
            if(menu->processInputs()) {
                switch(menu->option) {
                    case 0:
                        return PLAY_1;
                    case 1:
                        return PLAY_2;
                    case 2:
                        return PLAY_3;
                    case 3:
                        return PLAY_4;
                }
            }
            return LEVEL_MENU;
        default:
            return EXIT;
    }
}

MenuLogic::~MenuLogic() {
    delete menu;
}
