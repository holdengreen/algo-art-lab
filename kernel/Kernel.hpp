#pragma once
#include "../config.hpp"
#include "FragmentShader.hpp"

struct Kernel {
    Kernel();
    void render();
    void load_frag_shader();

    FragmentShader* frag;
};