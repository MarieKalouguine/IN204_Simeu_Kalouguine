#include "objects.hpp"
Point Point::translate_by(const Ray& r) const {
	return *this + r.dir - r.origin;
}

double Point::distance_to(const Point& B) const {
	return (x-B.x)*(x-B.x) + (y-B.y)*(y-B.y) + (z-B.z)*(z-B.z);
}


Ray Lamp::ray_from_point(const Point& P) const {
	return Ray(P, origin); }

Ray Sun::ray_from_point(const Point& P) const {
	return Ray(P, P.translate_by(-direction)); }	//direction is the direction the sun lights, the resulting ray goes in the opposite direction
