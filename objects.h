#ifndef OBJECTS_H
#define OBJECTS_H

#include <iostream>

class Point
{
public:
	Point(double x, double y, double z): x(x), y(y), z(z) {};
	void print()
	{
		std::cout << "X: " << x << "\nY: " << y << "\nZ: " << z << std::endl;
	}
private:
	double x, y, z;
};

class Ray
{
public:
	Ray(Point O , Point D): O(O), D(D) {};
private:
	Point O, D;	// O is the origin of the ray, D is any other point, indicates direction
};

class Sphere
{
public:
	Sphere(Point O , double r, float reflex): O(O), ray(r), reflexivity(reflex) {};
	void print()
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
	virtual Ray ray_to_point(Point P);
};

class Lamp : Light_source
{
public:
	Lamp(Point O, float i): O(O), intensivity(i) {};
private:
	Point O;	//position of the lamp
	float intensivity;
};

class Sun : Light_source
{
public:
	Sun(Ray d, float i): direction(d), intensivity(i) {};
private:
	Ray direction;	//all the rays from the sun are parallel to this ray
	float intensivity;
};

#endif
