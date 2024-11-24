//
// Created by francisc on 11/24/24.
//

#ifndef CPPGAMEDARCUOPENGL_TESTLEVEL_HPP
#define CPPGAMEDARCUOPENGL_TESTLEVEL_HPP


#include "../Level.hpp"

class TestLevel: public Level{
public:
    TestLevel();
    explicit TestLevel(const std::vector<Wave*> &waves);
};


#endif //CPPGAMEDARCUOPENGL_TESTLEVEL_HPP
