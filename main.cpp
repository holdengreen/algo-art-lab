#include "kernel/Kernel.hpp"
#include <iostream>
#include <fstream>
#define STB_DEFINE
#include <stb/stb.h>
#include <stb/stb_image_write.h>
#include <glm/glm.hpp>

#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace glm;

int main ()
{
    Kernel kern;
    srand(time(NULL));
    //render();
    return 0;
}

struct Pos {
    uint32_t x;
    uint32_t y;
};