#pragma once
#include <stdlib.h>
#include <string>

namespace exportdata
{
    void ppm(uint8_t *data, size_t w, size_t h, std::string filename);
};