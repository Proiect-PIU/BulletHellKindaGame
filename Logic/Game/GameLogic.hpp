//
// Created by francisc on 10/10/24.
//

#ifndef CPPGAMEDARCUOPENGL_GAMELOGIC_HPP
#define CPPGAMEDARCUOPENGL_GAMELOGIC_HPP


#include "../Logic.hpp"
#include "../../Components/Entities/Entities.hpp"
#include "../../Components/Entities/Player/Player.hpp"
#include "../../Components/Entities/Enemies/Bacteria/Cocci/Cocci.hpp"
#include "../../Levels/Level.hpp"
#include "../../Creators/Updater/Updater.hpp"
#include "../../Components/Collisions/CollisionMatrix.hpp"

class GameLogic: public Logic{
    Level *testLevel;
    Updater *worker;
    CollisionMatrix *matrix;
public:
    GameLogic();
    void processLogic(Canvas &c, GLFWwindow &window) override;
    ~GameLogic() override;
};


#endif //CPPGAMEDARCUOPENGL_GAMELOGIC_HPP
