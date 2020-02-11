#include <iostream>
#include "../src/tinyxml2.hpp"

using namespace std;
using namespace tinyxml2;

int main()
{
	XMLDocument doc;
	XMLError eResult;
	doc.LoadFile( "scene.xml" );
	XMLNode *world = doc.FirstChildElement("world");
	XMLElement *lights = world->FirstChildElement("lights");
	
	double brightness;
	XMLElement *sun = lights->FirstChildElement("sun");
	while (sun)
	{
		eResult = sun->QueryDoubleAttribute("brightness", &brightness);
		cout<<brightness<<endl;
		sun = sun->NextSiblingElement("sun");
	}
	
	return 0;
}
