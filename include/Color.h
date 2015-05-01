#ifndef COLOR_H
#define COLOR_H

#include <string>

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
	Color scale(double s);

	bool operator==(Color other) const
	{
	  return red == other.red &&
	         green == other.green &&
	  	 blue == other.blue;
	}


        int red;
        int green;
        int blue;

	std::string colorString(std::string s);
	bool isGray();

	/*
	std::ostream & operator<<(std::ostream & Str, Color const & v)
	{ 
	  // print something from v to str, e.g: Str << v.getX();
	  return "Color[r = " + std::to_string(red) +
	         "g = " + std::to_string(green) +
		 "b = " + std::to_string(blue) + "]\n";
	};
	*/

    protected:

    private:

};

#endif // COLOR_H
