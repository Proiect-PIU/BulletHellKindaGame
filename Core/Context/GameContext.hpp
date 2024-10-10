//
// Created by francisc on 10/6/24.
//

#ifndef CPPGAMEDARCUOPENGL_GAMECONTEXT_HPP
#define CPPGAMEDARCUOPENGL_GAMECONTEXT_HPP


#include <GLFW/glfw3.h>

class GameContext{
    GLFWwindow *window;
    unsigned int shaderProgram;
public:
    GameContext();
    ~GameContext();
    int windowClosed();
    GLFWwindow *getWindow(){ return window;};
    [[nodiscard]] unsigned int getShaderProgram() const{ return shaderProgram; };
};


#endif //CPPGAMEDARCUOPENGL_GAMECONTEXT_HPP
