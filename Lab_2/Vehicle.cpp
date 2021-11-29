#include <iostream>
#include "Vehicle.h"
using namespace std;


Vehicle::Vehicle(string make, string model, int year, double price, int miles)
{
	_make = make;
	_model = model;
	_year = year;
	_price = price;
	_miles = miles;
}

Vehicle::Vehicle()
{
	_make = "COP3503";
	_model = "Rust Bucket";
	_year = 1900;
	_price = 0;
	_miles = 0;
}

double Vehicle::GetPrice()
{
	return _price;
}

string Vehicle::GetYearMakeModel()
{
	return to_string(_year) + " " + _make + " " + _model;
	
}

void Vehicle::Display() {

	cout << _year << " ";
	cout << _make << " ";
	cout << _model << " ";
	cout << "$" << _price << " ";
	cout << _miles << endl;

}