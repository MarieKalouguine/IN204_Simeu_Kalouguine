#include <iostream>
#include "objects.hpp"
#include "intersect.hpp"

int main()
{
	std::cout << "Point: ";
	Point P(3,2,5);
	P.print();
	std::cout << "\nSun: ";
	Sun sun(Ray(Point(10,10,10), Point(0,0,0)), 5.4);
	sun.print();
	std::cout << "Ray from point to sun: ";
	Ray r = sun.ray_from_point(P);
	r.print();
}
