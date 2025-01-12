
#include "MenuLogic.hpp"
#include "Loader/Loader.hpp"
#include "../../Core/Utility/Enums/GameStates.h"

MenuLogic::MenuLogic() {
    glm::vec4 color = glm::vec4(0.6, 0.3, 0.3, 0.1);
    menu = new Menu(color);
}

int MenuLogic::processLogic(int &option) {
    menu->addButton();
    if(menu->processInputs()){
        switch(menu->option){
            case Menu::PLAY:
                return LEVEL_MENU;
            case Menu::EXIT:
                return EXIT;
        }
    }
}

MenuLogic::~MenuLogic() {
    delete menu;
}
