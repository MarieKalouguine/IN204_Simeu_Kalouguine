#include "objects.hpp"

Point Point::translate_by(Ray r)
{
	return *this + r.Dir - r.Origin;
}

Ray Lamp::ray_from_point(Point P)
{
	return Ray(P, Origin);
}

Ray Sun::ray_from_point(Point P)
{
	return Ray(P, P.translate_by(-direction));
}
