#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include <vector>
#include <memory>

#include "shape.hpp"
#include "light_source.hpp"
#include "camera.hpp"

using namespace std;

class Environment
{
	public :
		Environment(std::vector<shared_ptr<Shape>> obj, std::vector<shared_ptr<Light_source>> light, Camera cam): scene_objects(obj), lights(light), camera(cam) {}
		Environment(Camera cam): scene_objects(std::vector<shared_ptr<Shape>>()), lights(std::vector<shared_ptr<Light_source>>()), camera(cam) {}
		Environment(): scene_objects(std::vector<shared_ptr<Shape>>()), lights(std::vector<shared_ptr<Light_source>>()), camera(Camera()) {}
		
		void add_object(shared_ptr<Shape> S)
		{
			scene_objects.push_back(S);
		}
		void add_light(shared_ptr<Light_source> light)
		{
			lights.push_back(light);
		}
		
		std::vector<shared_ptr<Shape>> get_scene() const
		{
			return scene_objects;
		}
		
		int find_first_intersect(const Ray&, Point&) const;
		double lighting(const Point&, const Shape&) const;
		Ray ray_from_pixel(unsigned x, unsigned y) const
		{
			return camera.ray_from_pixel(x, y);
		}
	private:
		std::vector<shared_ptr<Shape>> scene_objects;
		std::vector<shared_ptr<Light_source>> lights;
		Camera camera;
};

#endif
