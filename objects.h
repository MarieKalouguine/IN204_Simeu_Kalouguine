#ifndef OBJECTS_H
#define OBJECTS_H

#include <iostream>

class Coordinate
{
public:
	Coordinate(double x, double y, double z): x(x), y(y), z(z) {};
	void print()
	{
		std::cout << "X: " << x << "\nY: " << y << "\nZ: " << z << std::endl;
	}
private:
	double x, y, z;
};

class Sphere
{
public:
	Sphere(Coordinate w , double r, float reflex): w(w), r(r), reflexivity(reflex) {};
	void print()
	{
		w.print();
		std::cout << "Ray: " << r << "\nReflexivity: " << reflexivity << std::endl;
	}
private:
	Coordinate w;
	double r;
	float reflexivity;
};

#endif
