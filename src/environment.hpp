#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include <vector>
#include <memory>

#include "math_objects.hpp"
#include "shape.hpp"
#include "light_source.hpp"

using namespace std;

class Environment
{
	public :
		Environment(std::vector<shared_ptr<Sphere>> obj, std::vector<shared_ptr<Light_source>> light, Camera cam): scene_objects(obj), lights(light), camera(cam) {}
		Environment(Camera cam): scene_objects(std::vector<shared_ptr<Sphere>>()), lights(std::vector<shared_ptr<Light_source>>()), camera(cam) {}
		Environment(): scene_objects(std::vector<shared_ptr<Sphere>>()), lights(std::vector<shared_ptr<Light_source>>()), camera(Camera()) {}
		
		void add_object(Sphere S)
		{
			scene_objects.push_back(make_shared<Sphere>(S));
		}
		void add_light(shared_ptr<light_source> light)
		{
			lights.push_back(light);
		}
		
		double lighting(const Point&, const Sphere&) const;
	private:
		std::vector<shared_ptr<Sphere>> scene_objects;
		std::vector<shared_ptr<Light_source>> lights;
		Camera camera;
};

#endif
