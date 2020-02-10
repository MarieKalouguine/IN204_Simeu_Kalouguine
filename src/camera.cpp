#include <math.h>
#include <stdio.h>

#include "camera.hpp"

Ray Camera::ray_from_pixel(unsigned x, unsigned y) const
{
	double lat = ((double)pxheight/2 - y)*height/pxheight;	// Coordinates of the intersection point in the
	double lon = ((double)x - pxwidth/2)*width/pxwidth;		//	coordinate system of the camera
	
	Point p = target - origin;
	p.unitarize();	//unitary vector normal to the camera image
	Point n1 = Point(p.get_y(), -p.get_x(), 0);
	n1.unitarize();	// unitary vector normal to p (which means in the plane of the camera image), and parallel to the plane (x, y)
	Point n2 = n1^p;	// unitary vector normal to p and n1
	Point result = target + n1*lon + n2*lat;
	return Ray(origin, result);
}
