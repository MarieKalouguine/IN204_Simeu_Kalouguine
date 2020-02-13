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
	if (!strcmp(s,"white"))
		return Color<unsigned char>(255,255,255);
	if (!strcmp(s,"black"))
		return Color<unsigned char>(0,0,0);
	if (!strcmp(s,"grey"))
		return Color<unsigned char>(150,150,150);
	if (!strcmp(s,"yellow"))
		return Color<unsigned char>(252, 231, 0);
	if (!strcmp(s,"cyan"))
		return Color<unsigned char>(0, 252, 240);
	if (!strcmp(s,"orange"))
		return Color<unsigned char>(252, 140, 0);
	if (!strcmp(s,"purple"))
		return Color<unsigned char>(181, 0, 252);
	if (!strcmp(s,"pink"))
		return Color<unsigned char>(255, 125, 225);
	if (!strcmp(s,"brown"))
		return Color<unsigned char>(138, 72, 41);
	if (!strcmp(s,"dark green"))
		return Color<unsigned char>(7, 105, 0);
	return Color<unsigned char>();
}
