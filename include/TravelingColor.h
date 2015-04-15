#ifndef TRAVELINGCOLOR_H
#define TRAVELINGCOLOR_H

#include "Color.h"

/*
 * Written by Bryce Summers on 4/5/2015.
 *
 * Purpose : this class encapsulates the data for singular lights that will travel along the bridge trying to match the velocity of pedestrians that cross.
 */

class TravelingColor
{
    public:
        TravelingColor(Color color, float vel, int pos);
        virtual ~TravelingColor();

        void update(float timeStep);

        int getPanel();
        Color getColor();

    protected:
    private:

        Color myColor;
        float velocity;

        // When viewed on the bridge, the position must be rounded to
        // an integer of interpolated to the two bridge panels near it.
        float position;
};

#endif // TRAVELINGCOLOR_H
