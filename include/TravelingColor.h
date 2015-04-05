#ifndef TRAVELINGCOLOR_H
#define TRAVELINGCOLOR_H


class TravelingColor
{
    public:
        TravelingColor(Color color, float vel, int pos);
        virtual ~TravelingColor();

        void update();

    protected:
    private:

        Color myColor;
        float velocity;

        // When viewed on the bridge, the position must be rounded to
        // an integer of interpolated to the two bridge panels near it.
        float position;
};

#endif // TRAVELINGCOLOR_H
