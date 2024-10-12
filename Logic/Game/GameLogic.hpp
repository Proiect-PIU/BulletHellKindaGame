//
// Created by francisc on 10/10/24.
//

#ifndef CPPGAMEDARCUOPENGL_GAMELOGIC_HPP
#define CPPGAMEDARCUOPENGL_GAMELOGIC_HPP


#include "../Logic.hpp"

class GameLogic: Logic{
public:
    GameLogic();
    void processLogic(Canvas &c, GLFWwindow &window) override;
    ~GameLogic() override;
};


#endif //CPPGAMEDARCUOPENGL_GAMELOGIC_HPP
