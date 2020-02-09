#include <iostream>
#include "../src/tinyxml2.h"

using namespace std;
using namespace tinyxml2;

int main()
{
    XMLDocument doc;
    XMLError eResult;
	doc.LoadFile( "scene.xml" );
	XMLNode *world = doc.FirstChildElement("world");
	XMLElement *camera = world->FirstChildElement("camera");
	int pxwidth;
	eResult = camera->QueryIntAttribute("pxwidth", &pxwidth);

	XMLElement *lights = world->FirstChildElement("lights");
	cout<<lights<<endl;
    return 0;
}
