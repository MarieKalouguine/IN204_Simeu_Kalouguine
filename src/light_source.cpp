#include "light_source.hpp"
#include "environment.hpp"

/**
 * Returns a ray that starts at the point P and is in the direction of a given light_source
 */
Ray Lamp::ray_from_point(const Point& P) const
{
	return Ray(P, origin);
}
	
Ray Sun::ray_from_point(const Point& P) const
{
	return Ray(P, P-direction); //direction is the direction the sun lights, the resulting ray goes in the opposite direction
}

bool Sun::not_shaded(const Point& P, const Point& obstacle) const
{
	return false;	//any obstacle on the ray from P to the sun will shade P
}

bool Lamp::not_shaded(const Point& P, const Point& obstacle) const
{
	double dist = P.square_distance_to(obstacle);
	double dist2 = P.square_distance_to(origin);
	return (dist>=dist2);	// if the point obstacle is not between the point P and the lamp
}
