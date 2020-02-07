#include "camera.hpp"

Ray Camera::ray_from_pixel(unsigned x, unsigned y) const
{
	return Ray(Point(), Point(1,1,1));	//a changer
}
