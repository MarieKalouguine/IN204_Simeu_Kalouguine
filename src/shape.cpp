#include "shape.hpp"

/**
 * Returns if the shape is crossed by the ray.
 * The intersection point is return through the reference I.
 */
bool Sphere::is_crossed (const Ray& ray, Point& I) const
{
	Point ray_origin = ray.get_origin();
	Ray PC(ray_origin, center);	//vector between the origin of the ray and the center of the sphere
	double distPH = PC*ray.unitarized();	//scalar product
	double distCHsq = ray_origin.square_distance_to(center) - distPH*distPH;
	double distIHsq = size*size-distCHsq;	//I is the intersection point
	if (distIHsq >=0)
	{
		double distPI = distPH - sqrt(distIHsq);
		I = ray_origin.translate_by(ray.unitarized()*distPI);
		return true;
	}
	else
		return false;
}

/**
 * Returns the unitary vector that is normal to the surface of the shape, in a given point P.
 */
Ray Sphere::get_normal_vect(const Point& P) const
{
	Ray vect1(center, P);
	vect1.unitarize();
	return vect1;
}
