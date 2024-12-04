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

Loader::Loader()=default;

Loader& Loader::getInstance()
{
    static Loader instance;
    return instance;
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

const std::unordered_map<std::string, std::pair<std::vector<std::vector<float>>, std::vector<std::vector<int>>>>& const std::unordered_map<std::string, std::pair<std::vector<std::vector<float>>, std::vector<std::vector<int>>>>& Loader::getData() const
{
    return data;
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

std::vector<std::vector<float>> Loader::parseVertices(const std::string& section)
{
    std::vector<std::vector<float>> vertices;
    std::stringstream ss(section);
    std::string line;

    while (std::getline(ss, line))
    {
        std::stringstream lineStream(line);
        std::vector<float> vertex;
        float value;
        while (lineStream >> value)
        {
            vertex.push_back(value);
        }
        if(!vertex.empty())
        {
            vertices.push_back(vertex);
        }
    }

    return vertices;
}

std::vector<std::vector<int>> Loader::parseIndices(const std::string& section)
{
    std::vector<std::vector<int>> indices;
    std::stringstream ss(section);
    std::string line;

    while(std::getline(ss, line))
    {
        std::stringstream lineStream(line);
        std::vector<int> index;
        int value;
        while(lineStream >> value)
        {
            index.push_back(value);
        }
        if(!index.empty())
        {
            indices.push_back(index);
        }

        return indices;
    }
}