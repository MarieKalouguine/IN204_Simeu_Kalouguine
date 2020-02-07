#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "math_objects.hpp"

/**
 * A  camera is defined by its origin and the position of the plane where the image is projected.
 * We assume that the bottom of the image is always horizontal.
 */
class Camera
{
public:
	Camera(const Point& O, const Point& M, unsigned w, unsigned h): origin(O), image_center(M), width(w), height(h) {};
	Camera(): origin(Point(0,0,1)), image_center(Point(1,1,1)), width(400), height(300) {};
	
	Point get_origin() const
	{
		return origin;
	}
	Point get_image_center() const
	{
		return image_center;
	}
	unsigned get_width() const
	{
		return width;
	}
	unsigned get_height() const
	{
		return height;
	}
	
private:
	Point origin, image_center;	//origin of the camera, and center of the projection plane
	unsigned width, height;	//width and height of the rendered image
};

#endif
