#ifndef INITIALIZATION_HPP
#define INITIALIZATION_HPP

#include "math_objects.hpp"
#include "shape.hpp"
#include "light_source.hpp"
#include "environment.hpp"
#include "tinyxml2.hpp"

using namespace tinyxml2;

Environment initialization(const std::string &filename);

Point initialize_point(XMLElement &point);

Camera initialize_camera(XMLElement &camera);

shared_ptr<Light_source> initialize_lamp(XMLElement &lamp);
shared_ptr<Light_source> initialize_sun(XMLElement &sun);

shared_ptr<Shape> initialize_sphere(XMLElement &sphere);
shared_ptr<Shape> initialize_plane(XMLElement &plane);

#endif
