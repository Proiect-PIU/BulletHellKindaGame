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
    Cocci(Entity *e, Weapon *w, BulletPattern *pattern): Entities(*e, *w, *pattern){
        AI = new CocciPattern();
    };
    void update()override;
    ~Cocci(){
        if(!AI)
            delete AI;
        AI = nullptr;
    };
};


#endif //CPPGAMEDARCUOPENGL_COCCI_HPP
