#ifndef COLORPANEL_H
#define COLORPANEL_H

#include "Color.h"

/*
 * Written by Bryce Summers on 4/5/2015.
 *
 * Purpose : This class specifies the information needed for one panel on the Randy Pausch Bridge.
 */

class ColorPanel
{
    public:

        ColorPanel();
        virtual ~ColorPanel();


        void setTop(Color color);
        void setBottom(Color color);

        void setTop(int r, int g, int b);
        void setBottom(int r, int g, int b);

    protected:
    private:

        Color top = Color(0);
        Color bottom = Color(0);
};

#endif // COLORPANEL_H
