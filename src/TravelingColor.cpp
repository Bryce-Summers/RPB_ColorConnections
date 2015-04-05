#include "TravelingColor.h"

TravelingColor::TravelingColor(Color color, float vel, int pos)
{
    this.myColor = color;
    this.vel     = vel;
    this.pos     = 0.0 + pos; // We need to convert the initial position to a floating point value.
}

TravelingColor::~TravelingColor()
{
    //dtor
}

void travellingColor::update()
{
    this.pos += this.vel;
}
