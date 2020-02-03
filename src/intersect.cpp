#include "objects.hpp"
#include <iostream>
#include <math.h>

Point* compute_intersect(Ray ray, Sphere S)	//returns a pointer to the intersection point, and NULL if there is none
{
	ray.unitarize();
	Ray PC(ray.origin, S.center);	//vector between the origin of the ray and the center of the circle
	double distPH = PC*ray;	//scalar product
	double distCHsq = ray.origin.square_distance_to(S.center) - distPH*distPH;
	double distIHsq = S.size*S.size-distCHsq;	//I is the intersection point
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
