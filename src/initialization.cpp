#include <tinyxml2.h>
#include "environment.hpp"
#include "objects.hpp"

using namespace tinyxml2;

Environment initialization()
{
	Sphere S1(Point(30,30,30), 1, 0);
	Sphere S2(Point(3,1,-1), 1, 0);
	
	Ray d(Point(-2, -4, -7), Point(0,0,0));
	Sun sun(d, 1);
	
	Environment world = Environment();
	world.add_object(S1);
	world.add_object(S2);
	world.add_light(sun);
	
	return world;
}

