
#ifndef CPPGAMEDARCUOPENGL_BULLET_H
#define CPPGAMEDARCUOPENGL_BULLET_H


#include "../Entities.hpp"
#include "../../../Persistance/Data/Stats/BulletStats.hpp"
#include "../../Pattern/BulletPattern.hpp"

class Bullet: public Entities{
public:
    BulletStats *stats;
    BulletPattern *pattern;
    bool dead = false;
    Bullet(Entity &e, BulletType bt, Timer &t, BulletPattern &p, BulletStats &stats):
        Entities(e, bt, t), pattern(&p), stats(&stats){};
    Bullet(const Bullet& other)
            : Entities(*other.self, other.type, *other.timer),
              stats(other.stats),
              pattern(other.pattern),
              dead(other.dead) {}
    void update()override;
    bool isDead();
    ~Bullet() override {
        delete stats;
        stats = nullptr;
        delete pattern;
        pattern = nullptr;
    }
};


#endif //CPPGAMEDARCUOPENGL_BULLET_H
