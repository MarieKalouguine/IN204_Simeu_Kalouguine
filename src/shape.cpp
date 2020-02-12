#include <math.h>

#include "shape.hpp"

/**
 * Returns if the shape is crossed by the ray.
 * The intersection point is return through the reference I.
 */
bool Sphere::is_crossed (const Ray& ray, Point& I) const
{
	Point ray_origin = ray.get_origin();
	Ray PC(ray_origin, center);	//vector between the origin of the ray and the center of the sphere
	double distPH = PC*ray.unitarized();	//scalar product
	double distCHsq = ray_origin.square_distance_to(center) - distPH*distPH;
	double distIHsq = size*size-distCHsq;	//I is the intersection point
	if (distIHsq >=0)
	{
		double distPI = distPH - sqrt(distIHsq);
		I = ray_origin.translate_by(ray.unitarized()*distPI);
		return true;
	}
	else
		return false;
}

bool Plane::is_crossed (const Ray& ray, Point& I) const
{
	double d = -origin*normal;	//D is the affine coefficent in the plane equation (ax+by+cz+d=0)
	Point O = ray.get_origin();
	Point Rd = (ray.get_dir()-O);
	Rd.unitarize();
	double a1 = Rd*normal;
	if (a1>=0)	// if the ray is going from the plane
		return false;
	double a2 = O*normal;
	double t = (a2+d)/a1;
	I = O - (Rd*t);
	return true;
}

/**
 * Returns the unitary vector that is normal to the surface of the shape, in a given point P.
 */
Ray Sphere::get_normal_vect(const Point& P) const
{
	Ray vect1(center, P);
	vect1.unitarize();
	return vect1;
}

Ray Plane::get_normal_vect(const Point& P) const
{
	Ray vect1(P, P+normal);
	return vect1;
}



/**
 * Returns the color of a point on the shape
 */
Color<unsigned char> Sphere::get_color(const Point& I) const
{
	if (!chessed)	
		return color;
	else
	{
		Point P = I-center;
		P.unitarize();
		double v_sinus = P*Point(0,0,1);
		int lat = (int) (abs(asin(v_sinus))*2);
		if (v_sinus<0)
			lat = lat+1;
		Point v = (P - Point(0,0,1)*v_sinus);
		v.unitarize();
		int lon = (int) (acos(v*Point(1,0,0))*2);
		if ((lon+lat)%2==1)
		{
			return chesscolor;
		}
		return color;
	}
}

Color<unsigned char> Plane::get_color(const Point& I) const
{
	if (!chessed)	
		return color;
	else
	{
		Point v1;
		if (normal==Point(1,0,0))
			v1 = normal^Point(0,1,0);
		else
			v1 = normal^Point(1,0,0);
		v1.unitarize();
		Point v2 = normal^v1;
		//v1 and v2 are two orthogonal unitary vectors of the plane
		double i = v1*(I-origin);
		double j = v2*(I-origin);
		int lon = (int) abs(i);
		int lat = (int) abs(j);
		if (i<0)
			lon = lon+1;
		if (j<0)
			lat = lat+1;
		if ((lon+lat)%2==1)
		{
			return chesscolor;
		}
		return color;
	}
}
