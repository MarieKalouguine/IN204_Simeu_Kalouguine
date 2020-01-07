#include "objects.hpp"

Point Point::translate_by(Ray r)
{
	return *this + r.D - r.O;
}

Ray Lamp::ray_from_point(Point P)
{
	return Ray(P, O);
}

Ray Sun::ray_from_point(Point P)
{
	return Ray(P, P.translate_by(direction));
}
