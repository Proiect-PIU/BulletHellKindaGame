//
// Created by francisc on 11/13/24.
//

#ifndef CPPGAMEDARCUOPENGL_COCCI_HPP
#define CPPGAMEDARCUOPENGL_COCCI_HPP


#include "../../../Entities.hpp"
#include "../../../../Pattern/AiPatterns/CocciPattern.hpp"

class Cocci: public Entities{
    EnemyPattern *AI;
public:
    Cocci(Entity &e, BulletType bt, Timer &t): Entities(e, bt, t){
        AI = new CocciPattern();
    };
    void update()override;
    ~Cocci() override {
        if(!AI)
            delete AI;
        AI = nullptr;
    };
};


#endif //CPPGAMEDARCUOPENGL_COCCI_HPP
