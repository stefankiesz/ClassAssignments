#pragma once
#include <string>
using namespace std;


class Vehicle
{
	string _make;
	string _model;
	int _year;
	double _price;
	int _miles;

public:
	Vehicle(string make, string model, int year, double price, int miles);
	Vehicle();

	double GetPrice();
	string GetYearMakeModel();

	void Display();
	
};

