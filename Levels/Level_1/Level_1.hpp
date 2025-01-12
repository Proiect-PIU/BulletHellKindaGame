
#ifndef CPPGAMEDARCUOPENGL_LEVEL_1_HPP
#define CPPGAMEDARCUOPENGL_LEVEL_1_HPP
#include "../Level.hpp"

class Level_1: public Level {
public:
    Level_1();
    explicit Level_1(const std::vector<Wave*> &waves);
};


#endif //CPPGAMEDARCUOPENGL_LEVEL_1_HPP
