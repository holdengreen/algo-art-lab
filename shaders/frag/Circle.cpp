#include "../../kernel/FragmentShader.hpp"
#include <glm/exponential.hpp>
#include <iostream>
using namespace glm;
using namespace std;

struct Main : FragmentShader
{
    vec3 operator()() override;

    vec3 circlecolor{0.1, 0.3, 1.0};
    vec3 backgroundcolor{1, 1, 1};
};

vec3 Main::operator()()
{
    float dist = pow(pos.x, 2) + pow(pos.y, 2);

    auto color = circlecolor;
    if (dist > 1)
    {
        color = backgroundcolor;
    }

    return color;
}

extern "C" FragmentShader* create(){
    return new Main();
}