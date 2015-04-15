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

void ColorPanel::setTop(int r, int g, int b)
{
    top = Color(r, g, b);
}

void ColorPanel::setBottom(int r, int g, int b)
{
    bottom = Color(r, g, b);
}
