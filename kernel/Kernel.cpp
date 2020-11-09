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
    for (int x=0;x<WIDTH;x++) {
        for (int y=0;y<HEIGHT;y++) {
            vec2 pos;
            pos.x = float(x) / float(WIDTH);
            pos.y = float(y) / float(HEIGHT);
            //printf("Location: %p\n", frag);
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