#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "math_objects.hpp"


/**
 * Color is stored as a tuple of doubles (red, green, blue)
 */
class Color
{
public:
	float get_r()
	{
		return r;
	}
	float get_g()
	{
		return g;
	}
	float get_b()
	{
		return b;
	}
private:
	float r, g, b;
}

/**
 * Abstract class shape, containing color and reflexivity
 */
class Shape
{
public:
	Shape(Color col, float reflex): color(col), reflexivity(reflex) {};
	Color get_color() const
	{
		return color;
	}
	float get_reflexivity() const
	{
		return reflexivity;
	}
private:
	Color color;
	float reflexivity;
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
private:
	Point center;
	double size;
};

#endif
