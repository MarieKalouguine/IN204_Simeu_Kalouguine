#include "light_source.hpp"

Ray Lamp::ray_from_point(const Point& P) const {
	return Ray(P, origin); }
	
Ray Sun::ray_from_point(const Point& P) const {
	return Ray(P, P.translate_by(-direction)); }	//direction is the direction the sun lights, the resulting ray goes in the opposite direction
		
