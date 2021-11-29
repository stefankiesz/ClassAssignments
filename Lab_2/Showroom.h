#pragma once
#include <vector>
#include <string>
#include "Vehicle.h"
using namespace std;

class Showroom
{
	string _name;
	int _numVehicles;

	vector<Vehicle> _showroomVehicles;

public:
	Showroom(string name, int _numVehicles);
	Showroom();

	void AddVehicle(Vehicle newVehicle);
	void ShowInventory();
	double GetInventoryValue();
	int GetSize();
};