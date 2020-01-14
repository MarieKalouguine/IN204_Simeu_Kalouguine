#include "objects.hpp"
#include <iostream>
#include <math.h>

Point* Sphere::compute_intersect(Ray ray) const
{
	ray.unitarize();
	Ray PC(ray.origin, center);	//vector between the origin of the ray and the center of the circle
	double distPH = PC*ray;	//scalar product
	double distCHsq = ray.origin.square_distance_to(center) - distPH*distPH;
	std::cout << distCHsq << std::endl;
	double distIHsq = size*size-distCHsq;	//I is the intersection point
	if (distIHsq >=0)
	{
		double distPI = distPH - sqrt(distIHsq);
		Point* I = (Point*)malloc(sizeof(Point));
		*I = ray.origin.translate_by(ray*distPI);
		return I;
	}
	else
		return NULL;
}
