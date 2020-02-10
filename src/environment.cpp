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
	int i;
	for(i = 0; i < (int)scene_objects.size(); i++)
	{
		if (scene_objects[i]->is_crossed(ray, P))
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
float Environment::lighting(const Point& P, unsigned index_shape) const
{
	double result = 0;
	int i;
	const Shape& S = *scene_objects[index_shape];
	for(i = 0; i < (int)lights.size(); i++)
	{
		Ray ray = lights[i]->ray_from_point(P);
		Point P2;
		int j = find_first_intersect(ray, P2);
		if (j==-1 || j==index_shape)	// if there is no other shape between the light source and the point P
		{
			ray.unitarize();
			result = result + max(0.0, ray*S.get_normal_vect(P)*lights[i]->get_brightness());	//scalar product
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
		return (*scene_objects[index]).get_color() * lighting(I, index);
	}
	return Color();
}

void Environment::raytracing() const
{
	std::vector<Color> img;
	unsigned w = camera.get_widthpx();
	unsigned h = camera.get_heightpx();
	
	for (unsigned j = 0; j < h; ++j)
	{
		for (unsigned i = 0; i < w; ++i)
		{
			Color c = color_from_ray(ray_from_pixel(i, j));
			img.push_back(c);
		}
	}
	save_image("image.png", camera.get_widthpx(), camera.get_heightpx(), img);
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
	}
	ofs.close();
}
