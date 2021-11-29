#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <map>
#include "Color.h"

using namespace std;

class Color
{
	

public:
	string _name;
	string _hexVal;
	unsigned char _R;
	unsigned char _G;
	unsigned char _B;



	//void SetValue(int value);
	//void SetName(const char* name);

	unsigned char GetR() const;
	unsigned char GetG() const;
	unsigned char GetB() const;
	string GetHexValue() const;
	string GetName() const;

	string strToHex(string str) const;

	Color(string name, string hexVal);
	Color();

};

