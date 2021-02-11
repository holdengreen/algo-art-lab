#pragma once
#include <stddef.h>

constexpr size_t WIDTH = 1920;
constexpr size_t HEIGHT = 1080;

constexpr char* FRAG_SHADER = "Circle";




// begin implementation vars
constexpr float WIDTHF = WIDTH;
constexpr float HEIGHTF = HEIGHT;
constexpr float ASPECTRATIO = HEIGHTF / WIDTHF;
constexpr float HALFWIDTH = WIDTHF / 2.0;
constexpr float HALFHEIGHT = HEIGHTF / 2.0;
//constexpr float EFFECTIVEWIDTH = WIDTH-1;
//constexpr float EFFECTIVEHEIGHT = HEIGHT-1;