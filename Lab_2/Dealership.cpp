
#include <iostream>
#include <vector>
#include <string>

#include "Dealership.h"
#include "Showroom.h"
#include "Vehicle.h"

using namespace std;


Dealership::Dealership(string name, int size)
{
	_name = name;
	_size = size;
}


Dealership::Dealership()
{
	_name = "Generic Dealership is empty!";
	_size = 0;
}

void Dealership::AddShowroom(Showroom newShowroom)
{
	if (_size <= _dealershipShowrooms.size()) {
		cout << "Dealership is full, can't add another showroom!" << endl;
	}
	else {
		_dealershipShowrooms.push_back(newShowroom);
	}
}

void Dealership::ShowInventory()
{
	if (_size < 1) {
		cout << "Generic Dealership is empty!" << endl;
	}
	else {
		for (unsigned int i = 0; i < _dealershipShowrooms.size(); i++)
		{
			_dealershipShowrooms[i].ShowInventory();
			cout << endl;
		}
	}

	cout << "Average car price: $" << GetAveragePrice();

}

double Dealership::GetAveragePrice() 
{
	double avg = 0;
	int totalCars = 0;

	for (unsigned int i = 0; i < _dealershipShowrooms.size(); i++)
	{
		avg += _dealershipShowrooms[i].GetInventoryValue();
		totalCars += _dealershipShowrooms[i].GetSize();
	}
	if (totalCars == 0)
	{
		totalCars = 1;
	}
	avg /= totalCars;
	
	return avg;
}
