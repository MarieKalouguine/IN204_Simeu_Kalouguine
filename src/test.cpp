#include <iostream>

#include "math_objects.hpp"
#include "shape.hpp"
#include "light_source.hpp"
#include "environment.hpp"
#include "initialization.hpp"

int main()
{	
	Environment world = initialization();
	unsigned x=250, y=17;
	Color color = world.color_from_pixel(x, y);
	std::cout<< "Couleur du pixel [" <<x<<","<<y<<"] : (" << color.get_r() << " ," << color.get_g() << " ," << color.get_b() <<")" << std::endl;
}
