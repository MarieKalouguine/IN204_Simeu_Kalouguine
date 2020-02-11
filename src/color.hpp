#ifndef COLOR_HPP
#define COLOR_HPP

/**
 * Color is stored as a tuple of doubles (red, green, blue)
 */
template <typename T>
class Color
{
public:
	Color(const T& R, const T& G, const T& B) : r(R), g(G), b(B) {}
	Color() : r(0), g(0), b(0) {}
	
	T get_r() const
	{
		return r;
	}
	T get_g() const
	{
		return g;
	}
	T get_b() const
	{
		return b;
	}
	Color operator*(float k) const
	{
		return Color(r*k, g*k, b*k);
	}
	
private:
	T r, g, b;
};

Color<float> convert_to_float(const Color<unsigned char>& c);

Color<unsigned char> color_from_string(const char*s);

#endif
