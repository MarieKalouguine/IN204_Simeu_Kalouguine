#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include <vector>
#include "objects.hpp"

class Environment
{
	public :
		Environment(std::vector<Sphere> obj, std::vector<Light_source> light, Camera cam): scene_objects(obj), lights(light), camera(cam) {}
		Environment(): scene_objects(std::vector<Sphere>()), lights(std::vector<Light_source>()), camera(Camera()) {}
	private:
		std::vector<Sphere> scene_objects;
		std::vector<Light_source> lights;
		Camera camera;
};

#endif
