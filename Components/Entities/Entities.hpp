//
// Created by francisc on 10/10/24.
//

#ifndef CPPGAMEDARCUOPENGL_ENTITIES_HPP
#define CPPGAMEDARCUOPENGL_ENTITIES_HPP


#include "../../Renderer/Canvas/Element/Element.hpp"

class Entities{
    Element *e;
    std::vector<float> vertices;
public:
    Entities(const std::vector<float>& vertices): vertices(vertices){
        e = new Element(vertices);
    };
    Element *getElement(){ return e;};
    std::vector<float> getVertices(){ return vertices;};
    ~Entities();
};


#endif //CPPGAMEDARCUOPENGL_ENTITIES_HPP
