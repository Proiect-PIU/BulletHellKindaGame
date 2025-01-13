
#ifndef CPPGAMEDARCUOPENGL_BAMBIR_HPP
#define CPPGAMEDARCUOPENGL_BAMBIR_HPP


#include "../../../../Pattern/EnemyPattern.hpp"
#include "../../../Entities.hpp"
#include "../../../../Pattern/AiPatterns/BambirPattern.hpp"

class Bambir: public Entities{
    EnemyPattern *AI;
public:
    Bambir(Entity &e, BulletType bt, Timer &t): Entities(e, bt, t){
        AI = new BambirPattern();
    };
    void update()override;
    ~Bambir() override {
        if(!AI)
            delete AI;
        AI = nullptr;
    };
};


#endif //CPPGAMEDARCUOPENGL_BAMBIR_HPP
