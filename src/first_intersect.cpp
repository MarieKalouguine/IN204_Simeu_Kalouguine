#include <iostream>

#include "intersect.hpp"
#include "objects.hpp"
#include "environment.hpp"

void Ray::first_intersect(const Environment& world, Point** P_min, unsigned int* index) const
{
	double min_dist, dist;
	bool there_is_no_intersection = 1;
	Point* P = compute_intersect(*this, *world.scene_objects[0]);
	if (P!=0)
	{
		min_dist = origin.square_distance_to(*P);
		**P_min = *P;
		there_is_no_intersection = 0;
	}
	
	unsigned int i;
	for(i = 1; i < world.scene_objects.size(); i++)
	{
		P = compute_intersect(*this, *world.scene_objects[i]);
		if (P!=0)
		{
			dist = origin.square_distance_to(*P);
			if (there_is_no_intersection||(dist<min_dist))
			{
				min_dist=dist;
				**P_min = *P;
				*index = i;
				there_is_no_intersection = 0;
			}
		}
	}
}
