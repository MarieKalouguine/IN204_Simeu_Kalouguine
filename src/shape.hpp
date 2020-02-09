#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "math_objects.hpp"
#include "color.hpp"

/**
 * Abstract class shape, containing color and albedo (= reflexivity)
 */
class Shape
{
public:
	Shape(Color col, float alb): color(col), albedo(alb) {};
	Color get_color() const
	{
		return color;
	}
	float get_albedo() const
	{
		return albedo;
	}
	virtual bool is_crossed (const Ray&, Point&) const = 0;
	virtual Ray get_normal_vect(const Point&) const = 0;
private:
	Color color;
	float albedo;
};

/**
 * A sphere is a particular form of shape
 */
class Sphere : public Shape
{
public:
	Sphere(Color col, float reflex, const Point& O , double r): Shape(col, reflex), center(O), size(r){};
	Point get_center() const
	{
		return center;
	}
	double get_size() const
	{
		return size;
	}
	bool is_crossed (const Ray&, Point&) const;
	Ray get_normal_vect(const Point&) const;
private:
	Point center;
	double size;
};

#endif
