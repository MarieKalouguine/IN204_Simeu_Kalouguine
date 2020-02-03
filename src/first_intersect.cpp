#include <iostream>

#include "intersect.hpp"
#include "objects.hpp"
#include "environment.hpp"

Point* Ray::first_intersect(const Environment& world) const
{
	Point* P_min = compute_intersect(*this, *world.scene_objects[0]);
	double min_dist = origin.square_distance_to(*P_min);
	
	unsigned int i;
	for(i = 1; i < world.scene_objects.size(); i++)
	{
		Point* P = compute_intersect(*this, *world.scene_objects[i]);
		if (P!=0)
		{
			double dist = origin.square_distance_to(*P);
			if (dist<min_dist)
			{
				min_dist=dist;
				P_min = P;
			}
		}
	}
	return P_min;
}
