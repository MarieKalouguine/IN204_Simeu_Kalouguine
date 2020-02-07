#include "math_objects.hpp"

Point Point::translate_by(const Ray& r) const {
	return *this + r.get_dir() - r.get_origin();
}

double Point::square_distance_to(const Point& B) const {
	return (x-B.get_x())*(x-B.get_x()) + (y-B.get_y())*(y-B.get_y()) + (z-B.get_z())*(z-B.get_z());
}
