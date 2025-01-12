
#ifndef CPPGAMEDARCUOPENGL_LEVEL_3_HPP
#define CPPGAMEDARCUOPENGL_LEVEL_3_HPP


#include "../Level.hpp"

class Level_3: public Level{
public:
    Level_3();
    explicit Level_3(const std::vector<Wave*> &waves);
    void wave_1() override;
    void wave_2() override;
    void wave_3() override;
};


#endif //CPPGAMEDARCUOPENGL_LEVEL_3_HPP
