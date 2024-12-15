//
// Created by francisc on 11/24/24.
//

#ifndef CPPGAMEDARCUOPENGL_UPDATER_HPP
#define CPPGAMEDARCUOPENGL_UPDATER_HPP

#include "../../Components/Entities/Entities.hpp"
#include "../../Levels/Level.hpp"
#include "../../Components/Collisions/CollisionMatrix.hpp"

class Updater{
public:
    Updater()= default;
    void update(Level &level);
};


#endif //CPPGAMEDARCUOPENGL_UPDATER_HPP
