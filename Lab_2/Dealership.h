#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "Showroom.h"
#include "Vehicle.h"

using namespace std;


class Dealership
{
	string _name;
	int _size;
	vector<Showroom> _dealershipShowrooms;

public:
	Dealership(string name, int size);
	Dealership();

	void AddShowroom(Showroom newShowroom);
	void ShowInventory();
	double GetAveragePrice();


};

