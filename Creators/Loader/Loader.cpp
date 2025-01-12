//
// Created by francisc on 11/24/24.
//

#include "Loader.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <filesystem>

namespace fs = std::filesystem;


Loader& Loader::getInstance()
{
    static Loader instance;
    return instance;
}

void Loader::setWindow(GLFWwindow *w)
{
    window = w;
}
GLFWwindow *Loader::getWindow()
{
    return window;
}

void Loader::loadFromFolder(const std::string& folderPath)
{
    if (!fs::exists(folderPath) || !fs::is_directory(folderPath))
    {
        throw std::invalid_argument("Folderul nu exista sau nu este un director...");
    }

    for(const auto& entry : fs::directory_iterator(folderPath))
    {
        if(entry.path().extension() == ".gfx")
        {
            parseFile(entry.path().string());
        }
    }
}

const std::unordered_map<std::string, std::pair<std::vector<float>, std::vector<unsigned int>>>& Loader::getData() const
{
    return data;
}

static std::chrono::steady_clock::time_point lastUpdateTime = std::chrono::steady_clock::now();
void Loader::updateDeltaTime() {
    auto currentTime = std::chrono::steady_clock::now();
    float dTime = std::chrono::duration<float, std::chrono::seconds::period>(currentTime - lastUpdateTime).count();
    lastUpdateTime = currentTime;
    deltaTime = dTime;
}

float Loader::getDeltaTime() {
    return deltaTime;
}

Canvas *Loader::getCanvas()
{
    if (!canvas)
    {
        canvas = std::make_unique<Canvas>();
    }
    return canvas.get();
}
CollisionMatrix *Loader::getMatrix()
{
    if (!matrix)
    {
        matrix = std::make_unique<CollisionMatrix>(3.554, 2, 16, 16);
    }
    return matrix.get();
}

void Loader::parseFile(const std::string& filePath)
{
    std::ifstream file(filePath);
    if(!file.is_open())
    {
        throw std::runtime_error("Nu se poate deschide fisierul: " + filePath);
    }

    std::string line;
    std::stringstream vertexSection, indexSection;
    bool isIndexSection = false;

    while (std::getline(file, line))
    {
        if(line.find(delimiter) != std::string::npos)
        {
            isIndexSection = true;
            continue;
        }

        if(isIndexSection)
        {
            indexSection << line <<"\n";
        }
        else
        {
            vertexSection << line << "\n";
        }
    }

    file.close();

    auto vertices = parseVertices(vertexSection.str());
    auto indices = parseIndices(indexSection.str());
    std::string fileName = fs::path(filePath).stem().string();
    data[fileName] = {vertices, indices};
}

std::vector<float> Loader::parseVertices(const std::string& section)
{
    std::vector<float> vertices;
    std::stringstream ss(section);
    std::string line;

    while (std::getline(ss, line))
    {
        std::stringstream lineStream(line);
        float value;
        while (lineStream >> value)
        {
            vertices.push_back(value);
        }
    }

    return vertices;
}

std::vector<unsigned int> Loader::parseIndices(const std::string& section)
{
    std::vector<unsigned int> indices;
    std::stringstream ss(section);
    std::string line;

    while(std::getline(ss, line))
    {
        std::stringstream lineStream(line);
        unsigned int value;
        while(lineStream >> value)
        {
            indices.push_back(value);
        }

    }

    return indices;
}