#include <iostream>

#include "math_objects.hpp"
#include "shape.hpp"
#include "light_source.hpp"
#include "environment.hpp"
#include "initialization.hpp"

int main()
{	
	Environment world = initialization();
	world.raytracing();
}
