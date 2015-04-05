#include "Color.h"

// Constructors.
Color::Color(int red_in, int green_in, int blue_in)
{
    red   = red_in;
    green = green_in;
    blue  = blue_in;
}

Color::Color(int sat)
{
    red   = sat;
    green = sat;
    blue  = sat;
}

// Deconstructor.
Color::~Color()
{
    //dtor
}
