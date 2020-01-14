#include "objects.hpp"
#include "intersect.hpp"

Point Sphere::compute_intersect(Ray ray) const
{
	ray.unitarize();
	return Point(1,1,2);
}
