//
// Created by francisc on 11/13/24.
//

#ifndef CPPGAMEDARCUOPENGL_WEAPONSTATS_HPP
#define CPPGAMEDARCUOPENGL_WEAPONSTATS_HPP

#include "../../../Components/Pattern/BulletPattern.hpp"

class WeaponStats{
public:
    float shootReset;
    float shootTime;
    float shootCooldown;
    BulletPattern *pattern;

    WeaponStats(BulletPattern *pattern, float shootCooldown, float shootReset = 0):
    pattern(pattern), shootCooldown(shootCooldown),
    shootReset(shootReset), shootTime(shootCooldown){};
    ~WeaponStats(){
        delete pattern;
    };
};



#endif //CPPGAMEDARCUOPENGL_WEAPONSTATS_HPP
