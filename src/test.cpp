#include <iostream>
#include "objects.hpp"
#include "environment.hpp"
#include "initialization.hpp"

int main()
{	
	Environment world = initialization();
	
	Ray r(Point(0.5, 0, -1), Point(0.5, 0, 1));
	Point* I = r.first_intersect(world);
	if (I!=0)
	{
		I->print();
	}
}
