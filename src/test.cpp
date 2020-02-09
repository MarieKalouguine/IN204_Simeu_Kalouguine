#include <iostream>

#include "math_objects.hpp"
#include "shape.hpp"
#include "light_source.hpp"
#include "environment.hpp"
#include "initialization.hpp"

int main()
{	
	Environment world = initialization();
	
	Ray r(Point(-3, -1, 1), Point(0,0,0));
	Point I;
	int index = world.find_first_intersect(r, I);
	if (index!=-1)
	{
		std::cout<<"Intersection : ";
		I.print();
		double bw_color = world.lighting(I, *world.get_scene()[index]);
		std::cout<<"Eclairage : "<<bw_color<< "\n" << std::endl;
		world.ray_from_pixel(220, 0).print();
	}
}
