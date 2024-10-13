//
// Created by francisc on 10/10/24.
//

#ifndef CPPGAMEDARCUOPENGL_ENTITIES_HPP
#define CPPGAMEDARCUOPENGL_ENTITIES_HPP


#include "../../Renderer/Canvas/Element/Element.hpp"

class Entities{
    Element *e;
public:
    Entities(const std::vector<float>& vertices){
        e = new Element(vertices);
    };
    Entities(const std::vector<float>& vertices, const std::vector<unsigned int>& indices){
        e = new Element(vertices, indices);
    };
    Element *getElement(){ return e;};
    ~Entities();
};


#endif //CPPGAMEDARCUOPENGL_ENTITIES_HPP
