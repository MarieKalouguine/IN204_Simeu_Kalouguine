#include "objects.hpp"
#include <iostream>

Point Sphere::compute_intersect(Ray ray) const
{
	ray.unitarize();
	Ray PC(ray.origin, center);	//vector between the origin of the ray and the center of the circle
	double distPH = PC*ray;	//scalar product
	double distCHsq = ray.origin.square_distance_to(center) - distPH*distPH;
	std::cout << distCHsq << std::endl;
	if (distCHsq <= size*size)
	{
		printf("There is an intersection\n");
	}
	else
	{
		printf("No intersection\n");
	}
	return Point(1,1,2);
}
