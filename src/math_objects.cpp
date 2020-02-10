#include "math_objects.hpp"


Point Point::translate_by(const Ray& r) const {
	return *this + r.get_dir() - r.get_origin();
}
