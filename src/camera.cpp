#include <math.h>
#include <stdio.h>

#include "camera.hpp"

Ray Camera::ray_from_pixel(unsigned x, unsigned y) const
{
	double lat = ((double)y - heightpx/2)*height/heightpx;
	double lon = ((double)x - widthpx/2)*width/widthpx;
	Point P = target - origin;
	
	double P_x=P.get_x(), P_y=P.get_y();
	double disth = sqrt( P_x*P_x + P_y*P_y );
	Point P1 = P+Point(-lon/disth*P_y, lon/disth*P_x, 0);
	
	double P1_x=P1.get_x(), P1_y=P1.get_y(), P1_z=P1.get_z();
	double dist = sqrt( P1_x*P1_x + P1_y*P1_y + P1_z*P1_z );
	Point P2 = P1+Point(-lat/dist*P1_x, -lat/dist*P1_y, lat/dist*P1_z);
	
	return Ray(origin, origin+P2);
}
