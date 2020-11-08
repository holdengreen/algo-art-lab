#pragma once

#include <array>

template<typename colortype, int width, int height>
struct Image
{
    Image()

    std::array<std::array<colortype, height>, width> data;
};