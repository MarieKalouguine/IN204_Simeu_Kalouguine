#include <iostream>

#include "initialization.hpp"

using namespace tinyxml2;

/**
 * Initializes an environment by parsing an XML document
 */
Environment initialization(const std::string &filename)
{
	XMLDocument doc;
	doc.LoadFile(filename.c_str());
	XMLNode *e = doc.FirstChildElement("world");
	
	//find camera
	XMLElement *camera = e->FirstChildElement("camera");
	Camera cam = initialize_camera(*camera);
	Environment world = Environment(cam);	//initialize empty environment
	
	//find lights
	XMLElement *lights = e->FirstChildElement("lights");
	//find suns
	XMLElement *sun = lights->FirstChildElement("sun");
	while (sun)
	{
		world.add_light(initialize_sun(*sun));
		sun = sun->NextSiblingElement("sun");
	}
	//find lamps
	XMLElement *lamp = lights->FirstChildElement("lamp");
	while (lamp)
	{
		world.add_light(initialize_lamp(*lamp));
		lamp = lamp->NextSiblingElement("lamp");
	}
	
	//find shapes
	XMLElement *shapes = e->FirstChildElement("shapes");
	//find spheres
	XMLElement *sphere = shapes->FirstChildElement("sphere");
	while (sphere)
	{
		world.add_shape(initialize_sphere(*sphere));
		sphere = sphere->NextSiblingElement("sphere");
	}
	//find planes
	XMLElement *plane = shapes->FirstChildElement("plane");
	while (plane)
	{
		world.add_shape(initialize_plane(*plane));
		plane = plane->NextSiblingElement("plane");
	}
	
	return world;
}

Point initialize_point(XMLElement &point)
{
	double x, y, z;
	point.QueryDoubleAttribute("x", &x);
	point.QueryDoubleAttribute("y", &y);
	point.QueryDoubleAttribute("z", &z);
	
	return Point(x, y, z);
}

Camera initialize_camera(XMLElement &camera)
{
	//read origin
	XMLElement *origin = camera.FirstChildElement("origin");
	Point O = initialize_point(*origin);
	//read target
	XMLElement *target = camera.FirstChildElement("target");
	Point T = initialize_point(*target);
	
	unsigned pxwidth, pxheight;
	camera.QueryUnsignedAttribute("pxwidth", &pxwidth);
	camera.QueryUnsignedAttribute("pxheight", &pxheight);
	double width;
	camera.QueryDoubleAttribute("width", &width);
	
	return Camera(O, T, width, pxwidth, pxheight);
}


shared_ptr<Light_source> initialize_lamp(XMLElement &lamp)
{
	double b;
	lamp.QueryDoubleAttribute("brightness", &b);
	XMLElement *point = lamp.FirstChildElement("point");
	Point O = initialize_point(*point);
	return shared_ptr<Light_source>(new Lamp(O, b));
}

shared_ptr<Light_source> initialize_sun(XMLElement &sun)
{
	double b;
	sun.QueryDoubleAttribute("brightness", &b);
	XMLElement *point = sun.FirstChildElement("point");
	Point O = initialize_point(*point);
	return shared_ptr<Light_source>(new Sun(O, b));
}

shared_ptr<Shape> initialize_sphere(XMLElement &sphere)
{
	char* color;
	sphere.QueryStringAttribute("color", (const char**)&color);
	Color<unsigned char> col = color_from_string(color);
	float gloss;
	sphere.QueryFloatAttribute("gloss", &gloss);
	bool chessed=false;
	Color<unsigned char> chesscolor = color_from_string("white")-col;
	char* color2=0;
	sphere.QueryStringAttribute("chess", (const char**)&color2);
	if (color2!=0)
	{
		chessed=true;
		if (strcmp(color2,"default"))	//if the chess color is personalized
			chesscolor = color_from_string(color2);
	}
	double size;
	sphere.QueryDoubleAttribute("size", &size);
	XMLElement *point = sphere.FirstChildElement("point");
	Point O = initialize_point(*point);
	
	return shared_ptr<Shape>(new Sphere(col, gloss, chessed, chesscolor, O , size));
}

shared_ptr<Shape> initialize_plane(XMLElement &plane)
{
	char* color;
	plane.QueryStringAttribute("color", (const char**)&color);
	Color<unsigned char> col = color_from_string(color);
	float gloss;
	plane.QueryFloatAttribute("gloss", &gloss);
	bool chessed=false;
	Color<unsigned char> chesscolor = color_from_string("white")-col;
	char* color2=0;
	plane.QueryStringAttribute("chess", (const char**)&color2);
	if (color2!=0)
	{
		chessed=true;
		if (strcmp(color2,"default"))	//if the chess color is personalized
			chesscolor = color_from_string(color2);
	}
	XMLElement *point = plane.FirstChildElement("origin");
	Point O = initialize_point(*point);
	point = plane.FirstChildElement("normal");
	Point n = initialize_point(*point);
	n.unitarize();
	
	return shared_ptr<Shape>(new Plane(col, gloss, chessed, chesscolor, O, n));
}
