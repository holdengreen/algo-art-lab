#include "../../kernel/FragmentShader.hpp"
#include <glm/exponential.hpp>
#include <iostream>
using namespace glm;

struct Main : FragmentShader
{
    vec3 operator()() override;
};

vec3 Main::operator()()
{
    vec3 color(0.1, 0.3, 1.0);
    float dist = pow(pos.x, 2.0) + pow(pos.y, 2.0);
    //dist = (2.0 - dist) / 2.0;
    //color *= dist;
    if (dist < 1)
    {
        color *= dist;
    }
    else
    {
        color = vec3(1.0, 1.0, 1.0);
    }

    return color;
}

extern "C" FragmentShader* create(){
    return new Main();
}