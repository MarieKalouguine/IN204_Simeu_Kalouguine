#include "environment.hpp"


int Environment::find_first_intersect(const Ray& ray, Point& P_min) const
{
	int index = -1;
	double min_dist, dist;
	Point P;
	if (scene_objects[0]->is_crossed (ray, P))
	{
		min_dist = ray.get_origin().square_distance_to(P);
		P_min = P;
		index = 0;
	}
	
	int i;
	for(i = 1; i < (int)scene_objects.size(); i++)
	{
		if (scene_objects[i]->is_crossed (ray, P))
		{
			dist = ray.get_origin().square_distance_to(P);
			if (index==-1||(dist<min_dist))
			{
				min_dist=dist;
				P_min = P;
				index = i;
			}
		}
	}
	return index;
}


double Environment::lighting(const Point& P, const Shape& S) const
{
	double result = 0;
	unsigned int i;
	for(i = 0; i < lights.size(); i++)
	{
		Ray vect = lights[i]->ray_from_point(P);
		vect.unitarize();
		result = result + max(0.0, vect*S.get_normal_vect(P));	//scalar product
	}
	
	return result;
}
