#ifndef COLOR_H
#define COLOR_H

/*
 Written by Bryce Summers on 4/5/2015

 Purpose : This class represents a singular arrangement of intensity values.
           These can be implemented in terms of vector operations such as addition, subtraction, etc for easy color mixing.

TODO : Specify the semantics for the integer color values.

Red, Green, and Blue are defined between 0 and 255.

*/

class Color
{
    public:
        Color(int red, int green, int blue);
        Color(int val);
        Color();// Default constructor.
        virtual ~Color();

        Color add (Color other);
        Color sub (Color other);
        Color mult(Color other);

	bool operator==(Color other) const
	{
	  return red == other.red &&
	         green == other.green &&
	  	 blue == other.blue;
	}


        int red;
        int green;
        int blue;

    protected:

    private:

};

#endif // COLOR_H
