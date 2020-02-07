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
	Point* I = (Point*)malloc(sizeof(Point));
	unsigned int index=0;
	r.first_intersect(world, &I, &index);
	if (I!=0)
	{
		std::cout<<"Intersection : ";
		I->print();
		double color = world.lighting(*I, *world.get_scene()[index]);
		std::cout<<"\nEclairage : "<<color<<std::endl;
	}
}
