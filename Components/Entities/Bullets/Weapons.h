
#ifndef CPPGAMEDARCUOPENGL_WEAPONS_H
#define CPPGAMEDARCUOPENGL_WEAPONS_H


#include "../../Pattern/BulletPattern.hpp"
#include "BulletTypes.hpp"
#include "../../Pattern/ShootingPatterns/ClassicPattern.hpp"
#include "../../Pattern/ShootingPatterns/SpreadPattern.hpp"
#include "../../Pattern/ShootingPatterns/ZigzagPattern.hpp"
#include "../../Pattern/ShootingPatterns/DnaPattern.hpp"
#include "../../Pattern/ShootingPatterns/FirePattern.hpp"
#include "../../Pattern/ShootingPatterns/ChaoticPattern.hpp"

class Weapons {
public:
    Weapons()=default;
    static BulletPattern* getWeapon(BulletType bulletTypes, int nrOfBullets){
        switch(bulletTypes){
            case BASIC:
            case COCCI_BASIC:
                return new ClassicPattern(nrOfBullets);
            case SPREAD:
            case COCCI_STRONG:
            case HEPYLORI_BASIC:
            case HEPYLORI_STRONG:
            case BLOUT:
                return new SpreadPattern(nrOfBullets);
            case ZIGZAG:
            case BAMBIR_BASIC:
            case BAMBIR_STRONG:
                return new ZigzagPattern(nrOfBullets);
            case FIRE:
                return new FirePattern(nrOfBullets);
            case DNA:
                return new DnaPattern(nrOfBullets);
            case CHAOTIC:
                return new ChaoticPattern(nrOfBullets);
        }
    }
    static Bullet* getBullet(BulletType bulletTypes, SquareState state){
        Bullet* bullet;
        switch(bulletTypes){
            case BASIC:
                bullet = new Bullet(*(new Entity(new Graphics(Loader::getInstance().getData().at("weapon").first,
                                                              Loader::getInstance().getData().at("weapon").second),
                                                 new BaseStats(5, 0, 0, 5), state)), BASIC,
                                    *(new Timer(0.0f, 0)), *(new BulletStats(2.0f, 2.5f, 0.0f)));
                bullet->isBullet = true;
                return bullet;
            case COCCI_BASIC:
                bullet = new Bullet(*(new Entity(new Graphics(Loader::getInstance().getData().at("weapon_cocci").first,
                                                              Loader::getInstance().getData().at("weapon_cocci").second),
                                                 new BaseStats(5, 0, 0, 5), state)), BulletType::COCCI_BASIC,
                                    *(new Timer(0.0f, 0)), *(new BulletStats(2.0f, 1.5f, 0.0f)));
                bullet->isBullet = true;
                bullet->stats->spacing = 0.06;
                return bullet;
            case SPREAD:
                 bullet = new Bullet(*(new Entity(new Graphics(Loader::getInstance().getData().at("weapon").first,
                                                                   Loader::getInstance().getData().at("weapon").second),
                                                      new BaseStats(5, 0, 0, 5), state)), SPREAD,
                                         *(new Timer(0.0f, 0)), *(new BulletStats(2.0f, 2.5f, 0.0f)));
                bullet->isBullet = true;
                return bullet;
            case COCCI_STRONG:
                bullet = new Bullet(*(new Entity(new Graphics(Loader::getInstance().getData().at("weapon_cocci").first,
                                                              Loader::getInstance().getData().at("weapon_cocci").second),
                                                 new BaseStats(5, 0, 0, 5), state)), BulletType::COCCI_STRONG,
                                    *(new Timer(0.0f, 0)), *(new BulletStats(5.0f, 0.5f, 0.0f)));
                bullet->isBullet = true;
                return bullet;
            case HEPYLORI_BASIC:
                bullet = new Bullet(*(new Entity(new Graphics(Loader::getInstance().getData().at("weapon_cocci").first,
                                                              Loader::getInstance().getData().at("weapon_cocci").second),
                                                 new BaseStats(5, 0, 0, 5), state)), BulletType::HEPYLORI_BASIC,
                                    *(new Timer(0.0f, 0)), *(new BulletStats(5.0f, 0.5f, 0.0f)));
                bullet->isBullet = true;
                return bullet;
            case HEPYLORI_STRONG:
                bullet = new Bullet(*(new Entity(new Graphics(Loader::getInstance().getData().at("weapon_cocci").first,
                                                              Loader::getInstance().getData().at("weapon_cocci").second),
                                                 new BaseStats(5, 0, 0, 5), state)), BulletType::HEPYLORI_STRONG,
                                    *(new Timer(0.0f, 0)), *(new BulletStats(5.0f, 0.5f, 0.0f)));
                bullet->isBullet = true;
                return bullet;
            case ZIGZAG:
                bullet = new Bullet(*(new Entity(new Graphics(Loader::getInstance().getData().at("weapon").first,
                                                              Loader::getInstance().getData().at("weapon").second),
                                                 new BaseStats(5, 0, 0, 5), state)), ZIGZAG,
                                    *(new Timer(0.0f, 0)), *(new BulletStats(2.0f, 1.5f, 0.0f)));
                bullet->isBullet = true;
                bullet->stats->spacing = 0.08;
                bullet->stats->speed = 1.0;
                return bullet;
            case BAMBIR_BASIC:
                bullet = new Bullet(*(new Entity(new Graphics(Loader::getInstance().getData().at("weapon_bambir").first,
                                                              Loader::getInstance().getData().at("weapon_bambir").second),
                                                 new BaseStats(5, 0, 0, 5), state)), ZIGZAG,
                                    *(new Timer(0.0f, 0)), *(new BulletStats(2.0f, 1.5f, 0.0f)));
                bullet->isBullet = true;
                bullet->stats->spacing = 0.2;
                bullet->stats->speed = 1.0;
                return bullet;
            case BAMBIR_STRONG:
                bullet = new Bullet(*(new Entity(new Graphics(Loader::getInstance().getData().at("weapon_bambir").first,
                                                              Loader::getInstance().getData().at("weapon_bambir").second),
                                                 new BaseStats(5, 0, 0, 5), state)), ZIGZAG,
                                    *(new Timer(0.0f, 0)), *(new BulletStats(2.0f, 1.5f, 0.0f)));
                bullet->isBullet = true;
                bullet->stats->spacing = 0.2;
                bullet->stats->speed = 1.2;
                return bullet;
            case ALOOULA:
                bullet = new Bullet(*(new Entity(new Graphics(Loader::getInstance().getData().at("weapon_bambir").first,
                                                              Loader::getInstance().getData().at("weapon_bambir").second),
                                                 new BaseStats(5, 0, 0, 5), state)), ZIGZAG,
                                    *(new Timer(0.0f, 0)), *(new BulletStats(2.0f, 1.5f, 0.0f)));
                bullet->isBullet = true;
                bullet->stats->spacing = 0.2;
                bullet->stats->speed = 1.5;
                return bullet;
            case BLOUT:
                bullet = new Bullet(*(new Entity(new Graphics(Loader::getInstance().getData().at("weapon_anxiety_inducer").first,
                                                              Loader::getInstance().getData().at("weapon_anxiety_inducer").second),
                                                 new BaseStats(5, 0, 0, 5), state)), ZIGZAG,
                                    *(new Timer(0.0f, 0)), *(new BulletStats(2.0f, 1.5f, 0.0f)));
                bullet->isBullet = true;
                bullet->stats->spacing = 0.2;
                bullet->stats->speed = 1.5;
                return bullet;
            case FIRE:
                bullet = new Bullet(*(new Entity(new Graphics(Loader::getInstance().getData().at("weapon").first,
                                                              Loader::getInstance().getData().at("weapon").second),
                                                 new BaseStats(5, 0, 0, 5), state)), FIRE,
                                    *(new Timer(0.0f, 0)), *(new BulletStats(2.0f, 1.5f, 0.0f)));
                bullet->isBullet = true;
                bullet->stats->spacing = 0.03;
                bullet->stats->speed = 1.2;
                return bullet;
            case DNA:
                bullet = new Bullet(*(new Entity(new Graphics(Loader::getInstance().getData().at("weapon").first,
                                                              Loader::getInstance().getData().at("weapon").second),
                                                 new BaseStats(5, 0, 0, 5), state)), DNA,
                                    *(new Timer(0.0f, 0)), *(new BulletStats(2.0f, 1.5f, 0.0f)));
                bullet->isBullet = true;
                bullet->stats->spacing = 0.01;
                return bullet;
            case CHAOTIC:
                bullet = new Bullet(*(new Entity(new Graphics(Loader::getInstance().getData().at("weapon").first,
                                                              Loader::getInstance().getData().at("weapon").second),
                                                 new BaseStats(5, 0, 0, 5), state)), CHAOTIC,
                                    *(new Timer(0.0f, 0)), *(new BulletStats(2.0f, 1.5f, 0.0f)));
                bullet->isBullet = true;
                bullet->stats->spacing = 0.001;
                bullet->stats->speed = 2.0;
                return bullet;
        }
    }
};


#endif //CPPGAMEDARCUOPENGL_WEAPONS_H
