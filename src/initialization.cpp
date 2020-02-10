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
	auto S1 = shared_ptr<Shape>(new Sphere(Color(255,0,0), 0, Point(9,11,-2), 1.5));	//red sphere
	auto S2 = shared_ptr<Shape>(new Sphere(Color(0,255,0), 0, Point(10,10,2), 1.5));	//green sphere
	
	Point d(0, -1, -5);
	auto sun = shared_ptr<Light_source>(new Sun(d, 1));
	
	Point o(12, 8, 5);
	auto lamp = shared_ptr<Light_source>(new Lamp(o, 1));
	
	Camera cam(Point(0,0,0), Point(4,4,0), 6, 400, 300);
	
	Environment world = Environment(cam);
	world.add_object(S1);
	world.add_object(S2);
	//world.add_light(lamp);
	world.add_light(sun);
	world.add_light(sun);
	
	return world;
}

