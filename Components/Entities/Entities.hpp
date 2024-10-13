//
// Created by francisc on 10/10/24.
//

#ifndef CPPGAMEDARCUOPENGL_ENTITIES_HPP
#define CPPGAMEDARCUOPENGL_ENTITIES_HPP


#include <GLFW/glfw3.h>
#include "../../Renderer/Canvas/Element/Element.hpp"
#include "../../Core/Utility/Utils.hpp"

class Entities{
protected:
    Element *e;
public:
    Entities(const std::vector<float>& vertices){
        e = new Element(vertices);
    };
    Entities(const std::vector<float>& vertices, const std::vector<unsigned int>& indices){
        e = new Element(vertices, indices);
    };
    Element *getElement(){ return e;};
    void move(Directions dir, float deltaTime);
    ~Entities();
};


#endif //CPPGAMEDARCUOPENGL_ENTITIES_HPP
