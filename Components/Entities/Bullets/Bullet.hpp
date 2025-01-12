
#ifndef CPPGAMEDARCUOPENGL_BULLET_HPP
#define CPPGAMEDARCUOPENGL_BULLET_HPP


#include "../Entities.hpp"
#include "../../../Persistance/Data/Stats/BulletStats.hpp"

class Bullet: public Entities{
public:
    BulletStats *stats;
    bool dead = false;
    Bullet(Entity &e, BulletType bt, Timer &t, BulletStats &stats):
        Entities(e, bt, t), stats(&stats){};
    Bullet(const Bullet& other)
            : Entities(*other.self, other.type, *other.timer),
              stats(other.stats),
              dead(other.dead) {}
    void update()override;
    bool isDead();
    ~Bullet() override {
        delete stats;
        stats = nullptr;
    }
};


#endif //CPPGAMEDARCUOPENGL_BULLET_HPP
