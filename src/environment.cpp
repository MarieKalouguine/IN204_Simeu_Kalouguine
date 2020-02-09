#include <fstream>

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

Color Environment::color_from_ray(Ray r) const
{
	Point I;
	int index =  find_first_intersect(r, I);
	if (index!=-1)
	{
		return (*scene_objects[index]).get_color()*lighting(I, *scene_objects[index]);
	}
	return Color();
}

void Environment::raytracing() const
{
	std::vector<Color> img;
	unsigned w = camera.get_widthpx();
	unsigned h = camera.get_heightpx();
	
	std::ofstream ofs("image.txt", std::ios::out | std::ios::binary); 
	for (unsigned i = 0; i < w; ++i)
	{
		for (unsigned j = 0; j < h; ++j)
		{
			Color c = color_from_ray(ray_from_pixel(i, j));
			img.push_back(c);
			ofs << std::to_string(c.get_r()) <<" "<< std::to_string(c.get_g()) <<" "<< std::to_string(c.get_b())<<"\n";
		}
	}
	save_image("image.png", camera.get_widthpx(), camera.get_heightpx(), img);
	ofs.close();
}

void save_image(const std::string &filename, unsigned width, unsigned height, const std::vector<Color> &img)
{
	std::ofstream ofs(filename.c_str(), std::ios::out | std::ios::binary);
	ofs << "P6\n"
	<< width << " " << height
	<< "\n255\n";
	for (unsigned i = 0; i < width * height; ++i)
	{
		ofs << img[i].get_r() << img[i].get_g() << img[i].get_b();
		//printf("%d, %d, %d\n", img[i].get_r(), img[i].get_g(), img[i].get_b());
	}
	ofs.close();
}
