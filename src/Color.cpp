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

string Color::colorString(string s)
{
  double r = (double)red / 255.0;
  double g = (double)green / 255.0;
  double b = (double)blue / 255.0;
  int color = round(36 * (r * 5) + 6 * (g * 5) + (b * 5) + 16);
  return "\e[48;5;" << color << "m" << s << "\e[0m" << "\n";
}
