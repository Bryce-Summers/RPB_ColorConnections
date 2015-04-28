#include "Color.h"
#include "math.h"

using namespace std;

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
  return Color( min(red   + other.red,   255),
		min(green + other.green, 255),
                min(blue  + other.blue,  255));
}

Color Color::sub (Color other)
{
  return Color( max(red   - other.red,   0),
		max(green - other.green, 0),
                max(blue  - other.blue,  0));
}

Color Color::mult(Color other)
{
    return Color(red   * other.red,
                     green * other.green,
                     blue  * other.blue);
}

Color Color::scale(double s)
{
    return Color(red   * s,
		 green * s,
		 blue  * s);
}



std::string Color::colorString(std::string s)
{
  int r_val = red / 51;
  int g_val = green / 51;
  int b_val = blue / 51;

  int color = 36 * r_val + 6 * g_val + b_val  + 16;
  
  return "\e[48;5;" + std::to_string(color) + "m" + s + "\e[0m";
}

bool Color::isGray () {
  return (red == green && green == blue);
}
