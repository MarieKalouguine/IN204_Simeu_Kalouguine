#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include <vector>
#include <memory>

#include "shape.hpp"
#include "light_source.hpp"
#include "camera.hpp"
#include "color.hpp"

using namespace std;

class Environment
{
	public :
		Environment(std::vector<shared_ptr<Shape>> obj, std::vector<shared_ptr<Light_source>> light, Camera cam): shapes(obj), lights(light), camera(cam) {}
		Environment(Camera cam): shapes(std::vector<shared_ptr<Shape>>()), lights(std::vector<shared_ptr<Light_source>>()), camera(cam) {}
		Environment(): shapes(std::vector<shared_ptr<Shape>>()), lights(std::vector<shared_ptr<Light_source>>()), camera(Camera()) {}
		
		void add_shape(shared_ptr<Shape> S)
		{
			shapes.push_back(S);
		}
		void add_light(shared_ptr<Light_source> light)
		{
			lights.push_back(light);
		}
		
		std::vector<shared_ptr<Shape>> get_scene() const
		{
			return shapes;
		}
		
		int find_first_intersect(const Ray&, Point&) const;
		float lighting(const Point&, unsigned) const;
		
		Ray ray_from_pixel(unsigned x, unsigned y) const
		{
			return camera.ray_from_pixel(x, y);
		}
		
		Color<float> color_from_ray(Ray r) const;
		void raytracing() const;
		
	private:
		std::vector<shared_ptr<Shape>> shapes;
		std::vector<shared_ptr<Light_source>> lights;
		Camera camera;
};

void save_image(const std::string &filename, unsigned width, unsigned height, const std::vector<Color<float>> &img);

#endif
