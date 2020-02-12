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
	Shape(Color<unsigned char> col, float glos): color(col), gloss(glos) {};
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
	Sphere(Color<unsigned char> col, float gloss, const Point& O , double r): Shape(col, gloss), center(O), size(r){};
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

/**
 * A plane is a particular form of shape
 */
class Plane : public Shape
{
public:
	Plane(Color<unsigned char> col, float gloss, const Point& O , const Point& n): Shape(col, gloss), origin(O), normal(n) {};
	Point get_origin() const
	{
		return origin;
	}
	Point get_normal() const
	{
		return normal;
	}
	bool is_crossed (const Ray&, Point&) const;
	Ray get_normal_vect(const Point&) const;
private:
	Point origin;	//any point on the plane
	Point normal;
};

#endif
