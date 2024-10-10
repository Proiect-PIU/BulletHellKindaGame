//
// Created by francisc on 10/9/24.
//

#ifndef CPPGAMEDARCUOPENGL_ELEMENT_HPP
#define CPPGAMEDARCUOPENGL_ELEMENT_HPP


class Element{
    unsigned int VBO, VAO;
    float *vertices;
    size_t size;
public:
    Element(float *vertices,  size_t size);
    ~Element();
    void loadElement();
    [[nodiscard]] unsigned int getVAO() const{ return VAO;}
};


#endif //CPPGAMEDARCUOPENGL_ELEMENT_HPP
