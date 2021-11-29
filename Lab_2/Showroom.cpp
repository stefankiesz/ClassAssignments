#include <iostream>
#include "Showroom.h"
#include "Vehicle.h"


using namespace std;


Showroom::Showroom(string name, int numVehicles)
{
	_name = name;
	_numVehicles = numVehicles;
}

Showroom::Showroom()
{

}

void Showroom::AddVehicle(Vehicle newVehicle)
{
	if (_numVehicles <= _showroomVehicles.size()) {
		cout << "Showroom is full! Cannot add 2016 Nissan Leaf" << endl;
	}
	else {
		_showroomVehicles.push_back(newVehicle);
	}
}

void Showroom::ShowInventory()
{
	if (_numVehicles < 1) {
		cout << "Unnamed Showroom is empty!" << endl;
	}
	else {
		cout << "Vehicles in " << _name << endl;
		for (unsigned int i = 0; i < _showroomVehicles.size(); i++)
		{
			_showroomVehicles[i].Display();
		}
	}
}

double Showroom::GetInventoryValue()
{
	double sum = 0;
	for (unsigned int i = 0; i < _showroomVehicles.size(); i++)
	{
		sum += _showroomVehicles[i].GetPrice();
	}
	return sum;
}

int Showroom::GetSize()
{
	return _showroomVehicles.size();
}