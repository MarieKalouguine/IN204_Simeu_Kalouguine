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
	Camera(const Point& O, const Point& M, double w, double h, unsigned wpx, unsigned hpx): origin(O), target(M), width(w), height(h), widthpx(wpx), heightpx(hpx) {};
	Camera(const Point& O, const Point& M, double w, unsigned wpx, unsigned hpx): origin(O), target(M), width(w), height(hpx*w/wpx), widthpx(wpx), heightpx(hpx) {};
	Camera(): origin(Point(1,1,1)), target(Point(2,2,2)), width(1), height(0.75) , widthpx(400), heightpx(300) {};
	
	Point get_origin() const
	{
		return origin;
	}
	Point get_target() const
	{
		return target;
	}
	double get_width() const
	{
		return width;
	}
	double get_height() const
	{
		return height;
	}
	unsigned get_widthpx() const
	{
		return widthpx;
	}
	unsigned get_heightpx() const
	{
		return heightpx;
	}
	
	Ray ray_from_pixel(unsigned x, unsigned y) const;
	
private:
	Point origin, target;	//origin of the camera, and center of the projection plane
	double width, height;	//width and height of the rendered image
	unsigned widthpx, heightpx;	//width and height of the rendered image
};

#endif
