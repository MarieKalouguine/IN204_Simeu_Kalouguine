#include "objects.hpp"

Point Point::translate_by(const Ray& r) const {
	return *this + r.Dir - r.Origin; }

Ray Lamp::ray_from_point(const Point& P) const {
	return Ray(P, Origin); }

Ray Sun::ray_from_point(const Point& P) const {
	return Ray(P, P.translate_by(-direction)); }	//direction is the direction the sun lights, the resulting ray goes in the opposite direction
