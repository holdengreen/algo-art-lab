#include "exportdata.hpp"
#include <fstream>

using namespace std;

void exportdata::ppm(uint8_t *data, size_t w, size_t h, string filename)
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
