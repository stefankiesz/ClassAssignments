#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

#define PI 3.14159f
#include "Shapes.h"

using namespace std;


void Shape2D::ShowArea() const
{
	cout << "The area of the " << GetName2D() << "  is : " << endl;
	cout << Area() << endl;
}


Square::Square()
{
	_s = 0;
}

Square::Square(float s)
{
	_s = s;
}

void Square::Scale(float scaleFactor)
{
	_s *= scaleFactor;
}

void Square::Display() const
{
	this->ShowArea();
	cout << "Length of a side: " << _s;
}

float Square::Area() const
{
	return _s * _s;
}

string Square::GetName2D() const
{
	return "Square";
}



Triangle::Triangle()
{
	_b = 0;
	_h = 0;
}

Triangle::Triangle(float b, float h)
{
	_b = b;
	_h = h;
}

void Triangle::Scale(float scaleFactor)
{
	_b *= scaleFactor;
	_h *= scaleFactor;
}

void Triangle::Display() const
{
	this->ShowArea();
	cout << "Base: " << _b << endl;
	cout << "Height: " << _h << endl;
}

float Triangle::Area() const
{
	return _b * _h / 2;
}

string Triangle::GetName2D() const
{
	return "Triangle";
}


Circle::Circle()
{
	_r = 0;
}

Circle::Circle(float r)
{
	_r = r;
}

void Circle::Scale(float scaleFactor)
{
	_r *= scaleFactor;
}

void Circle::Display() const
{
	this->ShowArea();
	cout << "Radius: " << _r;
}

float Circle::Area() const
{
	return PI * _r * _r;
}

string Circle::GetName2D() const
{
	return "Circle";
}

float Circle::GetRad() const
{
	return _r;
}


void Shape3D::ShowVolume() const
{
	cout << "The volume of the " << GetName3D() << " is : " << Volume() << endl;
}

TriangularPyramid::TriangularPyramid() : Triangle()
{
	_h = 0;
}

TriangularPyramid::TriangularPyramid(float h, float l, float bh) : Triangle(l, bh)
{
	_h = h;
}

float TriangularPyramid::Volume() const
{
	return _h * Triangle::Area() / 3;
}

void TriangularPyramid::Display() const
{
	this->ShowVolume();
	cout << "The height is: " << _h << endl;
	Triangle::Display();
}

string TriangularPyramid::GetName3D() const
{
	return "Triangular Pyramid";
}


Cylinder::Cylinder() : Circle()
{
	_h = 0;
}

Cylinder::Cylinder(float h, float r) : Circle(r)
{
	_h = h;
}

float Cylinder::Volume() const
{
	return _h * Circle::Area();
}

void Cylinder::Display() const
{
	this->ShowVolume();
	cout << "The height is: " << _h << endl;
	Circle::Display();
}

string Cylinder::GetName3D() const
{
	return "Cylinder";
}


Sphere::Sphere() : Circle()
{
}

Sphere::Sphere(float r) : Circle(r)
{
}

float Sphere::Volume() const
{
	return 4 * Circle::Area() * Circle::GetRad() / 3;
}

void Sphere::Display() const
{
	this->ShowVolume();
	Circle::Display();
}

string Sphere::GetName3D() const
{
	return "Sphere";
}

bool Shape2D::operator>(const Shape2D& rhs) const
{
	return (Area() > rhs.Area());
}

bool Shape2D::operator<(const Shape2D& rhs) const
{
	return (Area() < rhs.Area());
}

bool Shape2D::operator==(const Shape2D& rhs) const
{
	return (Area() == rhs.Area());
}

bool Shape3D::operator>(const Shape3D& rhs) const
{
	return (Volume() > rhs.Volume());
}

bool Shape3D::operator<(const Shape3D& rhs) const
{
	return (Volume() < rhs.Volume());
}

bool Shape3D::operator==(const Shape3D& rhs) const
{
	return (Volume() == rhs.Volume());
}

void TriangularPyramid::Scale(float scaleFactor)
{
	_h *= scaleFactor;
	Triangle::Scale(scaleFactor);
}

void Cylinder::Scale(float scaleFactor)
{
	_h *= scaleFactor;
	Circle::Scale(scaleFactor);
}

void Sphere::Scale(float scaleFactor)
{
	Circle::Scale(scaleFactor);
}