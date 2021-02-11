#include "Kernel.hpp"
#include "Color.hpp"
#include "exportdata/exportdata.hpp"
#include "../config.hpp"
#include <dlfcn.h>
#include <string>
#include <iostream>
#include <glm/glm.hpp>
#include <cstring>
#include <stdio.h>

using namespace glm;
using namespace std;

Kernel::Kernel()
{
    load_frag_shader();
    render();
}

void Kernel::render()
{
    size_t datalen = WIDTH * HEIGHT * 3;
    uint8_t* data =  new uint8_t[datalen];

    int i=0;
    for (int y=0;y<HEIGHT;y++) {
        for (int x=0;x<WIDTH;x++) {
            vec2 pos;
            float xf = x;
            float yf = y;
            float hx = (WIDTH-1)/2.0;
            float hy = (HEIGHT-1)/2.0;
            pos.x = -((xf - hx) / hx);
            pos.y = ((yf - hy) / hy);
            frag->pos = pos;
            auto vc = (*frag)();
            Color c;
            c.r = vc.r * 255.0;
            c.g = vc.g * 255.0;
            c.b = vc.b * 255.0;
            memcpy(data + (i*sizeof(Color)), &c, sizeof(Color));
            i++;
        }
    }

    exportdata::ppm(data, WIDTH, HEIGHT, "output/output.ppm");
}

void Kernel::load_frag_shader ()
{
    auto handle = dlopen((string("shaders/binaries/frag/") + FRAG_SHADER + ".so").c_str(), RTLD_LAZY);
    if(!handle){
        cout << "Error opening object file!: " << dlerror() << endl;
    }
    FragmentShader* (*create)() = (FragmentShader* (*) ()) dlsym(handle, "create");
    frag = (*create)();
    // dlclose(handle);
}