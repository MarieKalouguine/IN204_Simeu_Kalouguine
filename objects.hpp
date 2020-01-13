#ifndef OBJECTS_HPP
#define OBJECTS_HPP

#include <iostream>
class Ray;

class Point
{
public:
	Point(double x, double y, double z): x(x), y(y), z(z) {};
	void print() const {
		std::cout << "(" << x << ", " << y << ", " << z << ")"; }
	Point operator+(const Point& P) const {
		return Point(x+P.x, y+P.y, z+P.z); }
	Point operator-(const Point& P) const {
		return Point(x-P.x, y-P.y, z-P.z); }
	Point translate_by(const Ray&) const;
private:
	double x, y, z;
};

class Ray	// it is more of a vector, since it's defined by two points
{
public:
	Ray(const Point& O , const Point& D): Origin(O), Dir(D) {};
	friend Point Point::translate_by(const Ray&) const;
	void print() const
	{
		Origin.print();
		std::cout <<" -> ";
		Dir.print();
		std::cout << '\n';
	}
	Ray operator-() const {
		return Ray(Dir, Origin); }
private:
	Point Origin, Dir;	// Origin is where the ray starts, Dir is any point on the ray (indicates direction)
};


class Sphere
{
public:
	Sphere(const Point& O , double r, float reflex): Origin(O), ray(r), reflexivity(reflex) {};
	void print() const
	{
		Origin.print();
		std::cout << "Ray: " << ray << "\nReflexivity: " << reflexivity << std::endl;
	}
private:
	Point Origin;
	double ray;
	float reflexivity;
};

class Camera
{
public:
	Camera(const Point& O , const Point& M, unsigned w, unsigned h): Origin(O), Image_center(M), width(w), height(h) {};
private:
	Point Origin, Image_center;	//origin of the camera, and center of the projection plane
	unsigned width, height;	//width and height of the rendered image
};

class Light_source
{
public:
	Light_source(double i): intensivity(i) {};
	virtual Ray ray_from_point(const Point&) const = 0;
protected:
	double intensivity;
};

class Lamp : public Light_source
{
public:
	Lamp(const Point& O, double i): Light_source(i), Origin(O) {};
	Ray ray_from_point(const Point&) const;
private:
	Point Origin;	//position of the lamp
};

class Sun : public Light_source
{
public:
	Sun(const Ray& d, double i): Light_source(i), direction(d) {};
	Ray ray_from_point(const Point&) const;
	void print() const {
		direction.print(); }
private:
	Ray direction;	//all the rays from the sun are parallel to this ray
};

#endif
