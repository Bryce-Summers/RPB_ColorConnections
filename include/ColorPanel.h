#ifndef COLORPANEL_H
#define COLORPANEL_H

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
    protected:
    private:

        Color top;
        Color bottom;
};

#endif // COLORPANEL_H
