cmake_minimum_required(VERSION 3.28)
project(CppGameDarCuOpenGL)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)

find_package(glfw3 REQUIRED)

find_package(GLEW REQUIRED)

add_executable(CppGameDarCuOpenGL Core/main.cpp
        Core/Loop/Game.cpp
        Core/Loop/Game.hpp
        Core/Context/GameContext.cpp
        Core/Context/GameContext.hpp
        Renderer/Canvas/Element/Element.cpp
        Renderer/Canvas/Element/Element.hpp
        Renderer/Canvas/Canvas.cpp
        Renderer/Canvas/Canvas.hpp
        Renderer/Renderer.cpp
        Renderer/Renderer.hpp)

target_link_libraries(CppGameDarCuOpenGL
        OpenGL::GL
        glfw
        GLEW::GLEW
)