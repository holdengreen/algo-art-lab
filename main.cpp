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

constexpr size_t WIDTH = 1920;
constexpr size_t HEIGHT = 1080;
constexpr float ASPECTRATIO = float(HEIGHT) / float(WIDTH);

struct Color {
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

void render();
void write_ppm(uint8_t* data, size_t w, size_t h, string filename);
Color fragment_shader (vec2 pos);

int main ()
{
    //Kernel kern;
    srand(time(NULL));
    render();
    return 0;
}

void render () {
    size_t datalen = WIDTH * HEIGHT * 3;
    uint8_t* data =  new uint8_t[datalen];

    int i=0;
    for (int x=0;x<WIDTH;x++) {
        for (int y=0;y<HEIGHT;y++) {
            vec2 pos;
            pos.x = float(x) / float(WIDTH);
            pos.y = float(y) / float(HEIGHT);
            Color c = fragment_shader(pos); //execute frag shader
            memcpy(data + (i*sizeof(Color)), &c, sizeof(Color));
            i++;
        }
    }

    write_ppm(data, WIDTH, HEIGHT, "output/output.ppm");
}

struct Pos {
    uint32_t x;
    uint32_t y;
};

Color fragment_shader (vec2 pos)
{
    vec3 color (0.1, 0.3, 1.0);
    float dist = pow(pos.x, 2.0) + pow(pos.y, 2.0);
    //dist = (2.0 - dist) / 2.0;
    //color *= dist;
    if (dist<1) {
        color *= dist;
    }else {
        color = vec3(1.0, 1.0, 1.0);
    }

    Color ret;
    ret.r = color.r*255.0;
    ret.g = color.g*255.0;
    ret.b = color.b*255.0;
    //ret.r = 255;
    return ret;
}

void write_ppm(uint8_t *data, size_t w, size_t h, string filename)
{
    ofstream file;
    file.open(filename);
    file << "P6\n";
    file << to_string(w) << ' ' << to_string(h) << endl;
    file << "255\n";
    const char *d= reinterpret_cast<char *>(data);
    file.write(d, w*h*3);
    file.close();
}