#pragma once
#include "Color.hpp"
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

struct FragmentShader { //this is supposed to be an abstract class
    glm::vec2 pos;

    virtual glm::vec3 operator()()=0;
};