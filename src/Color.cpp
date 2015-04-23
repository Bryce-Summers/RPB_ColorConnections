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

// Default Constructor
Color::Color()
{
    red = 0;
    green = 0;
    blue = 0;
}


// Deconstructor.
Color::~Color()
{
    //dtor
}

Color Color::add (Color other)
{
    return Color(red + other.red,
                     green + other.green,
                     blue + other.blue);
}

Color Color::sub (Color other)
{
    return Color(red   - other.red,
                     green - other.green,
                     blue  - other.blue);
}

Color Color::mult(Color other)
{
    return Color(red   * other.red,
                     green * other.green,
                     blue  * other.blue);
}
