
#ifndef CPPGAMEDARCUOPENGL_WEAPONS_H
#define CPPGAMEDARCUOPENGL_WEAPONS_H


#include "../../Pattern/BulletPattern.hpp"
#include "BulletTypes.hpp"
#include "../../Pattern/ShootingPatterns/ClassicPattern.hpp"
#include "../../Pattern/ShootingPatterns/SpreadPattern.hpp"

class Weapons {
public:
    Weapons()=default;
    static BulletPattern* getWeapon(BulletType bulletTypes, int nrOfBullets){
        switch(bulletTypes){
            case BASIC:
                return new ClassicPattern(nrOfBullets);
            case SPREAD:
                return new SpreadPattern(nrOfBullets);
            case COCCI_SPREAD:
                return new SpreadPattern(nrOfBullets);
        }
    }
    static Bullet* getBullet(BulletType bulletTypes, SquareState state){
        Bullet* bullet;
        switch(bulletTypes){
            case BASIC:
                bullet = new Bullet(*(new Entity(new Graphics(Loader::getInstance().getData().at("weapon").first,
                                                              Loader::getInstance().getData().at("weapon").second),
                                                 new BaseStats(5, 0, 0, 5), state)), BASIC,
                                    *(new Timer(0.0f, 0)), *(new BulletStats(1.0f, 2.5f, 0.0f)));
                bullet->isBullet = true;
                return bullet;
            case SPREAD:
                 bullet = new Bullet(*(new Entity(new Graphics(Loader::getInstance().getData().at("weapon").first,
                                                                   Loader::getInstance().getData().at("weapon").second),
                                                      new BaseStats(5, 0, 0, 5), state)), SPREAD,
                                         *(new Timer(0.0f, 0)), *(new BulletStats(2.0f, 1.5f, 0.0f)));
                bullet->isBullet = true;
                return bullet;
            case COCCI_SPREAD:
                bullet = new Bullet(*(new Entity(new Graphics(Loader::getInstance().getData().at("weapon_cocci").first,
                                                                   Loader::getInstance().getData().at("weapon_cocci").second),
                                                      new BaseStats(5, 0, 0, 5), state)), BulletType::COCCI_SPREAD,
                                         *(new Timer(0.0f, 0)), *(new BulletStats(2.0f, 1.5f, 0.0f)));
                bullet->isBullet = true;
                return bullet;
        }
    }
};


#endif //CPPGAMEDARCUOPENGL_WEAPONS_H
