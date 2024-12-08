//
// Created by francisc on 11/24/24.
//

#ifndef CPPGAMEDARCUOPENGL_LOADER_HPP
#define CPPGAMEDARCUOPENGL_LOADER_HPP

#include <unordered_map>
#include <vector>
#include <string>
#include <GLFW/glfw3.h>
#include "../../Renderer/Canvas/Canvas.hpp"
#include "../../Components/Collisions/CollisionMatrix.hpp"

class Loader{
public:
    static Loader& getInstance();

    Loader(const Loader&) = delete;
    Loader& operator=(const Loader&) = delete;

    void loadFromFolder(const std::string& folderPath);
    void setWindow(GLFWwindow *w);

    [[nodiscard]] const std::unordered_map<std::string, std::pair<std::vector<float>, std::vector<unsigned int>>>& getData() const;
    Canvas *getCanvas();
    CollisionMatrix *getMatrix();

    void updateDeltaTime();
    float getDeltaTime();
    GLFWwindow *getWindow();

private:
    Loader() = default;

    std::unordered_map<std::string, std::pair<std::vector<float>, std::vector<unsigned int>>> data;
    std::unique_ptr<Canvas> canvas;
    std::unique_ptr<CollisionMatrix> matrix;

    float deltaTime;
    GLFWwindow *window;

    const char delimiter = '#';

    void parseFile(const std::string& filePath);
    std::vector<float> parseVertices(const std::string& section);
    std::vector<unsigned int> parseIndices(const std::string& section);
};


#endif //CPPGAMEDARCUOPENGL_LOADER_HPP
