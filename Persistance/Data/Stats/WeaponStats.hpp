//
// Created by francisc on 11/13/24.
//

#ifndef CPPGAMEDARCUOPENGL_WEAPONSTATS_HPP
#define CPPGAMEDARCUOPENGL_WEAPONSTATS_HPP

class WeaponStats{
public:
    float shootReset;
    float shootTime;
    float shootCooldown;
    unsigned int damage;

    WeaponStats(float shootCooldown, unsigned int damage, float shootReset = 0):
        shootCooldown(shootCooldown), damage(damage),
        shootReset(shootReset), shootTime(shootCooldown){};
    WeaponStats(const WeaponStats &w):
        shootCooldown(w.shootCooldown), damage(w.damage),
        shootReset(w.shootReset), shootTime(w.shootCooldown){};
    ~WeaponStats()= default;;
};



#endif //CPPGAMEDARCUOPENGL_WEAPONSTATS_HPP
