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
	
	
	void print() const{
		std::cout << "(" << x << ", " << y << ", " << z << ")\n";
	}
	bool operator==(const Point& P) const {
		return (x==P.x)&&(y==P.y)&&(z==P.z);
	}
	Point operator-() const {
		return Point(-x, -y, -z);
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
	double operator*(Point A) const {	//scalar product (a point can be considered as a vector)
		return x*A.x + y*A.y + z*A.z;
	}
	Point operator^(Point A) const {	//cross product (same)
		return Point( y*A.z - z*A.y,  z*A.x - x*A.z, x*A.y - y*A.x);
	}
	
	double abs() const
	{
		return x*x + y*y + z*z;
	}
	
	void unitarize()
	{
		double length = sqrt(abs());
		x = x/length;
		y = y/length;
		z = z/length;
	}
	Point unitarized() const
	{
		Point copy = *this;
		copy.unitarize();
		return copy;
	}
	
	double square_distance_to(const Point& P) const
	{
		return (P-*this).abs();
	}
	
	Point translate_by(const Ray& r) const;	//creates a new point, translated from the initial point by a given vector/ray

	
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
		std::cout << "(" << origin.get_x() << ", " << origin.get_y() << ", " << origin.get_z() << ")";
		std::cout <<" -> ";
		std::cout << "(" << dir.get_x() << ", " << dir.get_y() << ", " << dir.get_z() << ")\n";
	}
	Ray operator-() const
	{
		return Ray(dir, origin);
	}	//Same ray in the opposite direction
	double operator*(Ray r) const	//scalar product
	{
		return (dir-origin)*(r.dir-r.origin);
	}
	Point operator^(Ray r) const	//cross product
	{
		return (dir-origin)^(r.dir-r.origin);
	}
	
	Ray operator*(double k) const
	{
		return Ray(origin, origin+(dir-origin)*k);
	}
	
	Ray operator/(double k) const
	{
		return Ray(origin, origin+(dir-origin)/k);
	}
	
	double length()
	{
		return (dir - origin).abs();
	}
	
	void unitarize()
	{
		dir = origin+(dir-origin)/sqrt(length());
	}
	Ray unitarized() const
	{
		double length = sqrt(origin.square_distance_to(dir));
		return Ray(origin, origin+(dir-origin)/length);
	}
	Ray reflect(const Ray& normal)
	{
		Point O = normal.get_origin();
		Point n = normal.get_dir()-O;
		Point v =dir-origin;
		double cos = (v*n)*2;
		return Ray(O, O+v-(n*cos));
	}
private:
	Point origin, dir;	// origin is where the ray starts, dir is any point on the ray (indicates direction)
};


#endif
