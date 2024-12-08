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
    unsigned int damage;
    BulletPattern *pattern;

    WeaponStats(BulletPattern *pattern, float shootCooldown, unsigned int damage, float shootReset = 0):
    pattern(pattern), shootCooldown(shootCooldown), damage(damage),
    shootReset(shootReset), shootTime(shootCooldown){};
    ~WeaponStats(){
        delete pattern;
    };
};



#endif //CPPGAMEDARCUOPENGL_WEAPONSTATS_HPP
