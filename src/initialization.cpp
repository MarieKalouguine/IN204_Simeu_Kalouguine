#include <tinyxml2.h>
#include "environment.hpp"
#include "objects.hpp"

using namespace tinyxml2;

Environment initialization()
{
	Sphere S1(Point(0,0,0), 1, 0);
	Sphere S2(Point(3,1,-1), 1, 0);
	
	Environment world = Environment();
	world.add_object(S1);
	world.add_object(S2);
	
	return world;
}

