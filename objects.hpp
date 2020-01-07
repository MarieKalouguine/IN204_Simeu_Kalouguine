#ifndef OBJECTS_HPP
#define OBJECTS_HPP

#include <iostream>
class Ray;
class Point;
class Camera;
class Light_source;
class Lamp;
class Sun;

class Point
{
public:
	Point(double x, double y, double z): x(x), y(y), z(z) {};
	void print() const
	{
		std::cout << "(" << x << ", " << y << ", " << z << ")";
	}
	
	Point operator+(Point P)
	{
		return Point(x+P.x, y+P.y, z+P.z);
	}
	Point operator-(Point P)
	{
		return Point(x-P.x, y-P.y, z-P.z);
	}
	Point translate_by(Ray);
private:
	double x, y, z;
};

class Ray	// it is more of a vector, since it's defined by two points
{
public:
	Ray(Point O , Point D): O(O), D(D) {};
	friend Point Point::translate_by(Ray);
	void print() const
	{
		O.print();
		std::cout <<" -> ";
		D.print();
	}
private:
	Point O, D;	// O is the origin of the ray, D is any other point, indicates direction
};


class Sphere
{
public:
	Sphere(Point O , double r, float reflex): O(O), ray(r), reflexivity(reflex) {};
	void print() const
	{
		O.print();
		std::cout << "Ray: " << ray << "\nReflexivity: " << reflexivity << std::endl;
	}
private:
	Point O;
	double ray;
	float reflexivity;
};

class Camera
{
public:
	Camera(Point O , Point M, unsigned w, unsigned h): O(O), M(M), width(w), height(h) {};
private:
	Point O, M;	//origin of the camera, and center of the projection plane
	unsigned width, height;	//width and height of the rendered image
};

class Light_source
{
public:
	Light_source(double i): intensivity(i) {};
	virtual Ray ray_from_point(Point);
protected:
	double intensivity;
};

class Lamp : public Light_source
{
public:
	Lamp(Point O, double i): Light_source(i), O(O) {};
	Ray ray_from_point(Point);
private:
	Point O;	//position of the lamp
};

class Sun : public Light_source
{
public:
	Sun(Ray d, double i): Light_source(i), direction(d) {};
	Ray ray_from_point(Point);
private:
	Ray direction;	//all the rays from the sun are parallel to this ray (but in the opposite direction)
};

#endif
