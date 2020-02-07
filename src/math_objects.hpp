#ifndef MATH_OBJECTS_HPP
#define MATH_OBJECTS_HPP

#include <iostream>
#include <math.h>

class Ray;

/**
 * A point as a purely mathematical object, defined by three coordinates
 */
class Point
{
public:
	Point(double x, double y, double z): x(x), y(y), z(z) {};
	Point(): x(0), y(0), z(0) {};
	
	double get_x() const
	{
		return x;
	}
	double get_y() const
	{
		return y;
	}
	double get_z() const
	{
		return z;
	}
	
	double square_distance_to(const Point&) const;
	void print() const {
		std::cout << "(" << x << ", " << y << ", " << z << ")";
	}
	Point operator+(const Point& P) const {
		return Point(x+P.x, y+P.y, z+P.z);
	}
	Point operator-(const Point& P) const {
		return Point(x-P.x, y-P.y, z-P.z);
	}
	Point operator*(double k) const {
		return Point(x*k, y*k, z*k);
	}
	Point operator/(double k) const {
		return Point(x/k, y/k, z/k);
	}
	double operator*(Point A) const {	//scalar product
		return x*A.x + y*A.y + z*A.z;
	}
	Point translate_by(const Ray&) const;	//creates a new point, translated from the initial point by a given vector/ray
private:
	double x, y, z;
};

/**
 * A ray can be defined by its origin and its direction.
 * Here, the direction is defined by another point on the ray. Note that there is more than one way to define one same ray.
 * When needed, it can be used as a vector.
 */
class Ray
{
public:
	Ray(const Point& O , const Point& D): origin(O), dir(D) {};
	
	Point get_origin() const
	{
		return origin;
	}
	Point get_dir() const
	{
		return dir;
	}
	
	void print() const
	{
		origin.print();
		std::cout <<" -> ";
		dir.print();
		std::cout << '\n';
	}
	Ray operator-() const
	{
		return Ray(dir, origin);
	}	//Same ray in the opposite direction
	double operator*(Ray r) const	//scalar product
	{
		return (dir-origin)*(r.dir-r.origin);
	}
	Ray operator*(double k) const
	{
		return Ray(origin, origin+(dir-origin)*k);
	}
	Ray operator/(double k) const
	{
		return Ray(origin, origin+(dir-origin)/k);
	}
	double length() {
		return origin.square_distance_to(dir);
	}
	
	void unitarize()
	{
		double length = sqrt(origin.square_distance_to(dir));
		dir = origin+(dir-origin)/length;
	}
	Ray unitarized() const
	{
		double length = sqrt(origin.square_distance_to(dir));
		return Ray(origin, origin+(dir-origin)/length);
	}
private:
	Point origin, dir;	// origin is where the ray starts, dir is any point on the ray (indicates direction)
};


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
