#include <iostream>
#include "objects.hpp"
#include "environment.hpp"

int main()
{
	Environment world();
	Ray r(Point(0.5, 0, -1), Point(0.5, 0, 1));
	Sphere S(Point(0,0,0), 1, 0);
	Point* I = S.compute_intersect(r);
	if (I!=0)
	{
		(*I).print();
	}
}
