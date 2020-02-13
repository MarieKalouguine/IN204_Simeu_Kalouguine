#include <fstream>
#include <algorithm>
#include <math.h>

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
	for(i = 0; i < (int)shapes.size(); i++)
	{
		if (shapes[i]->is_crossed(ray, P))
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
	const Shape& S = *shapes[index_shape];
	Ray n = S.get_normal_vect(P);
	for(i = 0; i < (int)lights.size(); i++)
	{
		Ray ray = lights[i]->ray_from_point(P);
		if (ray*n>=0)	// if the light source is not inside the shape
		{
			Point P2;
			int j = find_first_intersect(ray, P2);
			if (j==-1 || j==(int)index_shape || lights[i]->not_shaded(P, P2))	// if there is no other shape between the point P and the light source
			{
				ray.unitarize();
				result = result + (ray*n)*(lights[i]->get_brightness());	//scalar product
			}
		}
	}
	
	return (float)result;
}

Color<float> Environment::color_from_ray(const Ray& r) const
{
	Point I;
	int index =  find_first_intersect(r, I);
	if (index!=-1)
	{
		return convert_to_float(shapes[index]->get_color(I)) * lighting(I, index);
	}
	return Color<float>();
}

Color<float> Environment::recursive_color_from_ray(const Ray& r, float coeff, unsigned counter) const
{
	//if we are looking in the direction of a light source, we should be able to see it :
	float light_img = 0;
	unsigned i;
	for(i = 0; i < lights.size(); i++)
	{
		Ray light = lights[i]->ray_from_point(r.get_origin()).unitarized();
		Ray sight = r.unitarized();
		float cos = light*sight;
		if (cos>0)
		{
			float sin_sq = 1 - cos*cos;
			light_img = light_img + lights[i]->get_brightness() * exp(-sin_sq*100);
		}
	}
	
	Point I;
	int index =  find_first_intersect(r, I);
	if (index!=-1)
	{
		float gloss = shapes[index]->get_gloss();
		Color<float> color = convert_to_float(shapes[index]->get_color(I)) * lighting(I, index) + Color<float>(255,255,255)*light_img;
		if (gloss==0 || coeff<0.01 || counter>3)
			return color;
		
		Ray n = shapes[index]->get_normal_vect(I);
		Ray newRay = r.reflect(n);
		Color<float> reflexion = recursive_color_from_ray(newRay, gloss*coeff, counter+1);
		return (reflexion*gloss) + (color*(1-gloss));
	}
	return Color<float>(255,255,255)*light_img;
}

void Environment::raytracing() const
{
	std::vector<Color<float>> img;
	unsigned w = camera.get_pxwidth();
	unsigned h = camera.get_pxheight();
	
	for (unsigned j = 0; j < h; ++j)
	{
		for (unsigned i = 0; i < w; ++i)
		{
			// i is horizontal, j is vertical
			Color<float> c = color_from_ray(ray_from_pixel(i, j));
			img.push_back(c);
		}
	}
	save_image("image.ppm", camera.get_pxwidth(), camera.get_pxheight(), img);
}

void Environment::recursive_raytracing() const
{
	std::vector<Color<float>> img;
	unsigned w = camera.get_pxwidth();
	unsigned h = camera.get_pxheight();
	
	for (unsigned j = 0; j < h; ++j)
	{
		for (unsigned i = 0; i < w; ++i)
		{
			// i is horizontal, j is vertical
			Color<float> c = recursive_color_from_ray(ray_from_pixel(i, j), 1, 0);
			img.push_back(c);
		}
	}
	save_image("image.ppm", camera.get_pxwidth(), camera.get_pxheight(), img);
}

void save_image(const std::string &filename, unsigned width, unsigned height, const std::vector<Color<float>> &img)
{
	std::ofstream ofs(filename.c_str(), std::ios::out | std::ios::binary);
	ofs << "P6\n"
	<< width << " " << height
	<< "\n255\n";
	float max_bright=255;
	for (unsigned i = 0; i < width * height; ++i)
	{
		max_bright = std::max(max_bright, std::max(img[i].get_r(), std::max(img[i].get_g(), img[i].get_b())));
	}
	for (unsigned i = 0; i < width * height; ++i)
	{
		Color<float> c = img[i]*(255/max_bright);
		ofs << (unsigned char)c.get_r() << (unsigned char)c.get_g() << (unsigned char)c.get_b();
	}
	ofs.close();
}
