#include "ColorPanel.h"

ColorPanel::ColorPanel()
{
    //ctor
}

ColorPanel::~ColorPanel()
{
    //dtor
}

void ColorPanel::setTop(Color color)
{
    top = color;
}

void ColorPanel::setBottom(Color color)
{
    bottom = color;
}


// Used for arbitrary implentations that do not care about top and bottom.
void ColorPanel::setColor(Color color)
{
  top = color;
  bottom = color;
}

void ColorPanel::setColor(int r, int g, int b)
{
  setTop(r, g, b);
  setBottom(r, g, b);
}


void ColorPanel::setTop(int r, int g, int b)
{
    top = Color(r, g, b);
}

void ColorPanel::setBottom(int r, int g, int b)
{
    bottom = Color(r, g, b);
}

Color ColorPanel::getColor()
{
  return top;
}
