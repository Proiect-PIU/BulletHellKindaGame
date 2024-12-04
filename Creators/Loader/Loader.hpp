//
// Created by francisc on 11/24/24.
//

#ifndef CPPGAMEDARCUOPENGL_LOADER_HPP
#define CPPGAMEDARCUOPENGL_LOADER_HPP

#include <unordered_map>
#include <vector>
#include <string>

class Loader{
public:
    static Loader& getInstance();

    Loader(const Loader&) = delete;
    Loader& operator=(const Loader&) = delete;

    void loadFromFolder(const std::string& folderPath);

    const std::unordered_map<std::string, std::pair<std::vector<std::vector<float>>, std::vector<std::vector<int>>>>& getData() const;

private:
    Loader();

    std::unordered_map<std::string, std::pair<std::vector<std::vector<float>>, std::vector<std::vector<int>>>> data;

    const char delimiter = '#';

    void parseFile(const std::string& filePath);
    std::vector<std::vector<float>> parseVertices(const std::string& section);
    std::vector<std::vector<int>> parseIndices(const std::string& section);
};


#endif //CPPGAMEDARCUOPENGL_LOADER_HPP
