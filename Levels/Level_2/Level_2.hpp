
#ifndef CPPGAMEDARCUOPENGL_LEVEL_2_HPP
#define CPPGAMEDARCUOPENGL_LEVEL_2_HPP


#include "../Level.hpp"

class Level_2: public Level{
public:
    Level_2();
    explicit Level_2(const std::vector<Wave*> &waves);
    void wave_1() override;
    void wave_2() override;
    void wave_3() override;
};


#endif //CPPGAMEDARCUOPENGL_LEVEL_2_HPP
