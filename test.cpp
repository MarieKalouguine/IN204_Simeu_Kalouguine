#include <iostream>
#include "objects.hpp"

int main()
{
	Sun sun(Ray(Point(10,10,10), Point(0,0,0)), 5.4);
	Point P(3,2,5);
	P.print();
	Ray r = sun.ray_from_point(P);
	r.print();
}
