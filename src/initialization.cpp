#include "math_objects.hpp"
#include "shape.hpp"
#include "light_source.hpp"
#include "environment.hpp"
#include "tinyxml2.h"

using namespace tinyxml2;

/**
 * Currently initializes an environment with some objects.
 * TODO: Initialize from an XML document (inspiration from test_xml.cpp)
 */
Environment initialization()
{
	auto S1 = shared_ptr<Shape>(new Sphere(Color(), 0, Point(30,30,30), 1));
	auto S2 = shared_ptr<Shape>(new Sphere(Color(), 0, Point(3,1,-1), 1));
	
	Point d(2, 4, 7);
	auto sun = shared_ptr<Light_source>(new Sun(d, 1));
	
	Environment world = Environment();
	world.add_object(S1);
	world.add_object(S2);
	world.add_light(sun);
	
	return world;
}

