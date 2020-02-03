#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include <vector>
#include <memory>
#include "objects.hpp"

using namespace std;

class Environment
{
	public :
		Environment(std::vector<shared_ptr<Sphere>> obj, std::vector<shared_ptr<Light_source>> light, Camera cam): scene_objects(obj), lights(light), camera(cam) {}
		Environment(): scene_objects(std::vector<shared_ptr<Sphere>>()), lights(std::vector<shared_ptr<Light_source>>()), camera(Camera()) {}
		void add_object(Sphere S)
		{
			scene_objects.push_back(make_shared<Sphere>(S));
		}
		void add_light(Sun light)
		{
			lights.push_back(make_shared<Sun>(light));
		}
		std::vector<shared_ptr<Sphere>> get_scene() const
		{
			return scene_objects;
		}
		friend void Ray::first_intersect(const Environment&, Point**, unsigned int*) const;
		double lighting(const Point&, const Sphere&) const;
	private:
		std::vector<shared_ptr<Sphere>> scene_objects;
		std::vector<shared_ptr<Light_source>> lights;
		Camera camera;
};

#endif
