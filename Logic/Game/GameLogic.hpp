//
// Created by francisc on 10/10/24.
//

#ifndef CPPGAMEDARCUOPENGL_GAMELOGIC_HPP
#define CPPGAMEDARCUOPENGL_GAMELOGIC_HPP


#include "../Logic.hpp"
#include "../../Components/Entities/Entities.hpp"

class GameLogic: Logic{
    Entities *e;
public:
    GameLogic(const std::vector<float>& vertices) {e = new Entities(vertices);};
    void processLogic(Canvas &c, GLFWwindow &window) override;
    ~GameLogic() override;
};


#endif //CPPGAMEDARCUOPENGL_GAMELOGIC_HPP
