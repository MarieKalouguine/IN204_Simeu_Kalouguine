#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "math_objects.hpp"
#include "color.hpp"

/**
 * Abstract class shape, containing color and gloss (= reflexivity)
 */
class Shape
{
public:
	Shape(Color<unsigned char> col, float alb): color(col), gloss(alb) {};
	Color<unsigned char> get_color() const
	{
		return color;
	}
	float get_gloss() const
	{
		return gloss;
	}
	virtual bool is_crossed (const Ray&, Point&) const = 0;
	virtual Ray get_normal_vect(const Point&) const = 0;
private:
	Color<unsigned char> color;
	float gloss;
};

/**
 * A sphere is a particular form of shape
 */
class Sphere : public Shape
{
public:
	Sphere(Color<unsigned char> col, float reflex, const Point& O , double r): Shape(col, reflex), center(O), size(r){};
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
