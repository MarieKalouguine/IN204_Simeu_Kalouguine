#include "environment.hpp"

/**
 * Returns the first intersection of a ray with any shape the is in the world.
 * If existing, the intersection is returned through the Point reference P_min.
 */
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

/**
 * Returns the brightness of a point on a sphere, considering only direct lighting
 */
float Environment::lighting(const Point& P, const Shape& S) const
{
	double result = 0;
	int i;
	for(i = 0; i < (int)lights.size(); i++)
	{
		Ray ray = lights[i]->ray_from_point(P);
		Point P2;
		if (find_first_intersect(ray, P2)==i)	// if there is no other shape between the light source and the point P
		{
			ray.unitarize();
			result = result + max(0.0, ray*S.get_normal_vect(P));	//scalar product
		}
	}
	
	return (float)result;
}

Color Environment::color_from_pixel(unsigned x, unsigned y) const
{
	Ray r = ray_from_pixel(x, y);
	Point I;
	int index =  find_first_intersect(r, I);
	if (index!=-1)
	{
		return (*scene_objects[index]).get_color()*lighting(I, *scene_objects[index]);
	}
	return Color();
}
