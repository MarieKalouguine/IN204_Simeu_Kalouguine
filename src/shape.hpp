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
	Shape(Color<unsigned char> col, float glos, bool chess, Color<unsigned char> chesscol): color(col), chessed(chess), chesscolor(chesscol), gloss(glos) {};
	float get_gloss() const
	{
		return gloss;
	}
	virtual Color<unsigned char> get_color(const Point& I) const=0;
	virtual bool is_crossed (const Ray&, Point&) const = 0;
	virtual Ray get_normal_vect(const Point&) const = 0;
protected:
	Color<unsigned char> color;
	bool chessed;	//true if the shape has a white chess pattern on it
	Color<unsigned char> chesscolor;	//color of the chess pattern (default if there is none)
private:
	float gloss;
};

/**
 * A sphere is a particular form of shape
 */
class Sphere : public Shape
{
public:
	Sphere(Color<unsigned char> col, float gloss, bool chess, Color<unsigned char> chesscol, const Point& O , double r): Shape(col, gloss, chess, chesscol), center(O), size(r){};
	Point get_center() const
	{
		return center;
	}
	double get_size() const
	{
		return size;
	}
	Color<unsigned char> get_color(const Point& I) const;
	bool is_crossed (const Ray&, Point&) const;
	Ray get_normal_vect(const Point&) const;	//normal and unitary vector
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
	Plane(Color<unsigned char> col, float gloss, bool chess, Color<unsigned char> chesscol, const Point& O , const Point& n): Shape(col, gloss, chess, chesscol), origin(O), normal(n) {};
	Point get_origin() const
	{
		return origin;
	}
	Point get_normal() const
	{
		return normal;
	}
	Color<unsigned char> get_color(const Point& I) const;
	bool is_crossed (const Ray&, Point&) const;
	Ray get_normal_vect(const Point&) const;
private:
	Point origin;	//any point on the plane
	Point normal;	//is unitary
};

#endif
