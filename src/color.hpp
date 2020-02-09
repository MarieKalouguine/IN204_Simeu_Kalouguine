#ifndef COLOR_HPP
#define COLOR_HPP

/**
 * Color is stored as a tuple of doubles (red, green, blue)
 */
class Color
{
public:
	Color(const float& R, const float& G, const float& B) : r(R), g(G), b(B) {}
	Color() : r(0), g(0), b(0) {}
	
	float get_r() const
	{
		return r;
	}
	float get_g() const
	{
		return g;
	}
	float get_b() const
	{
		return b;
	}
	Color operator*(float k) const
	{
		return Color(r*k, g*k, b*k);
	}
	
private:
	float r, g, b;
};

#endif
