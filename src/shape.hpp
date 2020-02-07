#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "math_objects.hpp"


/**
 * Color is stored as a tuple of doubles (red, green, blue)
 */
class Color
{
public:
	Color(const float& R, const float& G, const float& B) : r(R), g(G), b(B) {}
	Color() : r(0.5), g(0.5), b(0.5) {}
	
	float get_r() const
	{
		return r;
	}
	float get_g() const
	{
		return g;
	}
	float get_b() const
	{
		return b;
	}
private:
	float r, g, b;
};

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
	virtual bool is_crossed (const Ray&, Point&) const = 0;
	virtual Ray get_normal_vect(const Point&) const;
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
	bool is_crossed (const Ray&, Point&) const;
	Ray get_normal_vect(const Point&) const;
private:
	Point center;
	double size;
};

#endif
