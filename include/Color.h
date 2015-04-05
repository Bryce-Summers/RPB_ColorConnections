#ifndef COLOR_H
#define COLOR_H

/*
 Written by Bryce Summers on 4/5/2015

 Purpose : This class represents a singular arrangement of intensity values.
           These can be implemented in terms of vector operations such as addition, subtraction, etc for easy color mixing.
*/

class Color
{
    public:
        Color(int red, int green, int blue);
        Color(int sat);
        virtual ~Color();

        public Color add (Color other);
        public Color sub (Color other);
        public Color mult(Color other);

    protected:

    private:

        int red;
        int green;
        int blue;
};

#endif // COLOR_H
