#ifndef CPPGAMEDARCUOPENGL_HEPYLORI_HPP
#define CPPGAMEDARCUOPENGL_HEPYLORI_HPP

#include "../../../Entities.hpp"
#include "../../../../Pattern/EnemyPattern.hpp"
#include "../../../../Pattern/AiPatterns/PyloriPattern.hpp"

class HePylori: public Entities{
    EnemyPattern *AI;
public:
    HePylori(Entity &e, BulletType bt, Timer &t): Entities(e, bt, t){
        AI = new PyloriPattern();
    };
    void update()override;
    ~HePylori() override {
        if(!AI)
            delete AI;
        AI = nullptr;
    };
};
#endif //CPPGAMEDARCUOPENGL_HEPYLORI_HPP