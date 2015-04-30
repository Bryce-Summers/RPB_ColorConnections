#include "TravelingColor.h"

TravelingColor::TravelingColor(Color color, float vel, int pos)
{
    this->myColor = color;
    this->velocity= vel;
    this->position= 0.0 + pos; // We need to convert the initial position to a floating point value.
    this->active = true;
}

TravelingColor::TravelingColor()
{
  this->myColor = Color(0,0,0);
  this->velocity= 0.0;
  this->position= 0.0; // We need to convert the initial position to a floating point value.
  this->active = false;
}

TravelingColor::~TravelingColor()
{
    //dtor
}

void TravelingColor::update(float timeStep)
{
  this->oldPosition = this -> position;
  this->position += this->velocity * timeStep;
}

int TravelingColor::getPanel()
{
  return (int)position;
}

int TravelingColor::getOldPanel()
{
  return (int)oldPosition;
}

Color TravelingColor::getColor()
{
  return myColor;
}
