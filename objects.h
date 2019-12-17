#ifndef OBJECTS_H
#define OBJECTS_H

#include <iostream>

class Sphere
{
public:
	Sphere(double x, double y, double z, double r): x(x), y(y), z(z), r(r) {};
	void print()
	{
		std::cout << "X: " << x << "\nY: " << y << "\nZ: " << z << "\nRay: " << r << std::endl;
	}
private:
	double x, y, z, r;
	float reflexivity;
};

#endif
