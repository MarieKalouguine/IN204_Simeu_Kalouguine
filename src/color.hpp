#ifndef COLOR_HPP
#define COLOR_HPP

/**
 * Color is stored as a tuple of doubles (red, green, blue)
 */
class Color
{
public:
	Color(const unsigned char& R, const unsigned char& G, const unsigned char& B) : r(R), g(G), b(B) {}
	Color() : r(0), g(0), b(0) {}
	
	unsigned char get_r() const
	{
		return r;
	}
	unsigned char get_g() const
	{
		return g;
	}
	unsigned char get_b() const
	{
		return b;
	}
	Color operator*(float k) const
	{
		//float R = (float)r*k, G = (float)g*k, B = (float)b*k;
		//return Color((unsigned char)R, (unsigned char)G, (unsigned char)B);
		return Color(r*k, g*k, b*k);
	}
	
private:
	unsigned char r, g, b;
};

#endif
