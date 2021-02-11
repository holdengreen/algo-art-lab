#include <glm/glm.hpp>
#include <vector>

#include "config.hpp"

using namespace std;
using namespace glm;

struct Triangle {
    vec3 v0;
    vec3 v1;
    vec3 v2;
};

struct Mesh {
    vector<Triangle> tris;

    Mesh(initializer_list<Triangle> in) {tris = in;}
};

class ray {
    public:
        ray() {}
        ray(const vec3& origin, const vec3& direction)
            : orig(origin), dir(direction)
        {}

        vec3 origin() const  { return orig; }
        vec3 direction() const { return dir; }

        vec3 at(float t) const {
            return orig + t*dir;
        }

    public:
        vec3 orig;
        vec3 dir;
};

struct Camera {
    vec3 origin;
    vec3 screenloc;
    float screenwidth;
};

Mesh mesh {
    Triangle {
        {-0.5, 0.5, -1.0},
        {0.5, 0.5, -1.0},
        {0.0, -0.5, -1.0}
    }
};

Camera camera {
    .origin {0, 0, -1.0},
    .screenloc {0, 0, 0},
    .screenwidth = 0.2
};

int main()
{
    float pixsize = camera.screenwidth / WIDTHF;
    for (int y=0;y<HEIGHT;y++) {
        for (int x=0;x<WIDTH;x++) {
            vec3 midpix;
            float xf = x * pixsize;
            float yf = y * pixsize;
            xf += pixsize/2.0;
            yf += pixsize/2.0;

            midpix.x = 
            ray outray {
                camera.origin,

            };
        }
    }
    return 0;
}