#include "math_objects.hpp"

Point Point::translate_by(const Ray& r) const {
	return *this + r.dir - r.origin;
}

double Point::square_distance_to(const Point& B) const {
	return (x-B.x)*(x-B.x) + (y-B.y)*(y-B.y) + (z-B.z)*(z-B.z);
}
