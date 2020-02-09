#include "light_source.hpp"

/**
 * Returns a ray that starts at the point P and is in the direction of a given light_source
 */
Ray Lamp::ray_from_point(const Point& P) const {
	return Ray(P, origin); }
	
Ray Sun::ray_from_point(const Point& P) const {
	return Ray(P, P.translate_by(-direction)); }	//direction is the direction the sun lights, the resulting ray goes in the opposite direction
