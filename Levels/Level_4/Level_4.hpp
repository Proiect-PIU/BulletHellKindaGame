
#ifndef CPPGAMEDARCUOPENGL_LEVEL_4_HPP
#define CPPGAMEDARCUOPENGL_LEVEL_4_HPP


#include "../Level.hpp"

class Level_4: public Level{
public:
    Level_4();
    explicit Level_4(const std::vector<Wave*> &waves);
    void wave_1() override;
    void wave_2() override;
    void wave_3() override;
};


#endif //CPPGAMEDARCUOPENGL_LEVEL_4_HPP
