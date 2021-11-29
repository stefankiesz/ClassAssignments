#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

class Shape
{
public:
	virtual void Scale(float scaleFactor) = 0;
	virtual void Display() const = 0;

	virtual ~Shape()
	{

	}
};

class Shape2D : virtual public Shape
{
public:
	virtual float Area() const = 0;
	void ShowArea() const;
	virtual string GetName2D() const = 0;

	virtual ~Shape2D()
	{

	}

	bool operator>(const Shape2D& rhs) const;
	bool operator<(const Shape2D& rhs) const;
	bool operator==(const Shape2D& rhs) const;
};

class Square : public Shape2D
{
	float _s;
public:
	Square();
	Square(float s);

	void Scale(float scaleFactor) override;
	void Display() const override;
	float Area() const override;
	string GetName2D() const override;
};

class Triangle : public Shape2D
{
	float _b;
	float _h;
public:
	Triangle();
	Triangle(float b, float h);

	void Scale(float scaleFactor) override;
	void Display() const override;
	float Area() const override;
	string GetName2D() const override;
};

class Circle : public Shape2D
{
	float _r;
public:
	Circle();
	Circle(float r);

	float GetRad() const;

	void Scale(float scaleFactor) override;
	void Display() const override;
	float Area() const override;
	string GetName2D() const override;
};

class Shape3D : virtual public Shape
{
public:
	virtual float Volume() const = 0;
	void ShowVolume() const;
	virtual string GetName3D() const = 0;
	bool operator>(const Shape3D& rhs) const;
	bool operator<(const Shape3D& rhs) const;
	bool operator==(const Shape3D& rhs) const;
};

class TriangularPyramid : virtual public Shape3D, private Triangle
{
	float _h;
public:
	TriangularPyramid();
	TriangularPyramid(float h, float l, float bh);
 
	void Display() const override;
	void Scale(float scaleFactor) override;

	float Volume() const override;
	string GetName3D() const override;
};

class Cylinder : virtual public Shape3D, private Circle
{
	float _h;
public:
	Cylinder();
	Cylinder(float h, float r);

	void Display() const override;
	void Scale(float scaleFactor) override;

	float Volume() const override;
	string GetName3D() const override;
};

class Sphere : virtual public Shape3D, private Circle
{
public:
	Sphere();
	Sphere(float r);

	void Display() const override;
	void Scale(float scaleFactor) override;

	float Volume() const override;
	string GetName3D() const override;
};
