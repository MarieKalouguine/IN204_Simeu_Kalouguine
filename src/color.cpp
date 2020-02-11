#include <cstring>

#include "color.hpp"

Color<float> convert_to_float(const Color<unsigned char>& c)
{
	return Color<float>( c.get_r(), c.get_g(), c.get_b() );
}

Color<unsigned char> color_from_string(const char* s)
{
	if (!strcmp(s,"red"))
		return Color<unsigned char>(255,0,0);
	if (!strcmp(s,"green"))
		return Color<unsigned char>(0,255,0);
	if (!strcmp(s,"blue"))
		return Color<unsigned char>(0,0,255);
	return Color<unsigned char>();
}
