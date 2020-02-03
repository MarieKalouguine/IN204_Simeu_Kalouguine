#include "objects.hpp"
#include "environment.hpp"

double Environment::lighting(const Point& P, const Sphere& S) const
{
	Ray vect1(S.get_center(), P);
	vect1.unitarize();
	
	double result = 0;
	unsigned int i;
	for(i = 0; i < lights.size(); i++)
	{
		Ray vect2 = lights[i]->ray_from_point(P);
		vect2.unitarize();
		result = result + max(0.0, vect1*vect2);	//scalar product
	}
	
	return result;
}
