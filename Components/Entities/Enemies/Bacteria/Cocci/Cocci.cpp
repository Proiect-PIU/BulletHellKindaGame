//
// Created by francisc on 11/13/24.
//

#include <iostream>
#include "Cocci.hpp"

void Cocci::update(Canvas &c, float deltaTime) {
    AI->updatePattern(deltaTime, c, *this);
}
