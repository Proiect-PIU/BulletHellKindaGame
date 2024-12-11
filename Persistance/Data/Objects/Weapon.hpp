//
// Created by francisc on 11/16/24.
//

#ifndef CPPGAMEDARCUOPENGL_WEAPON_HPP
#define CPPGAMEDARCUOPENGL_WEAPON_HPP


#include "../../../Renderer/Canvas/Element/Element.hpp"
#include "../Stats/WeaponStats.hpp"
#include "../Stats/BulletStats.hpp"

class Weapon{
public:
    Figure *figure;
    BulletStats *bullets;
    WeaponStats *stats;
    Weapon(Graphics *graphics, WeaponStats *stats, BulletStats *bullets): stats(stats), bullets(bullets){
        figure = new Figure(new Element(graphics), new Shape(graphics->getVertices(), Shape::ShapeType::POLYGON));
    };
    Weapon(const Weapon &w){
        figure = new Figure(new Element(w.figure->getElement()->getGraphics()),
                            new Shape(w.figure->getElement()->getGraphics()->getVertices(), Shape::ShapeType::POLYGON));
        bullets = new BulletStats(*w.bullets);
        stats = new WeaponStats(*w.stats);
    };
    [[nodiscard]] Element *getElement() const{ return figure->getElement();};
    [[nodiscard]] Shape *getShape() const{ return figure->getShape();};
    ~Weapon(){
        if (!stats) {
            delete stats;
        }
        if (!figure) {
            delete figure;
        }
        if(!bullets) {
            delete bullets;
        }
        stats = nullptr;
        figure = nullptr;
        bullets = nullptr;
    }
};


#endif //CPPGAMEDARCUOPENGL_WEAPON_HPP
