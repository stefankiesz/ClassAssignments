#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <map>
#include <vector>
#include "Color.h"

#include "Color.h"

using namespace std;

//void Color::SetValue(int value)
//{
//
//}
//
//void Color::SetName(const char* name)
//{
//
//}
//
unsigned char Color::GetR() const
{
	return _R;
}

unsigned char Color::GetG() const
{
	return _G;
}

unsigned char Color::GetB() const
{
	return _B;
}

string Color::GetHexValue() const
{
	vector<string> rgb;
	rgb.push_back(strToHex(to_string(_R)));
	rgb.push_back(strToHex(to_string(_G)));
	rgb.push_back(strToHex(to_string(_B)));

	
	return "0x" + rgb[0] + rgb[1] + rgb[2];
}

string Color::GetName() const
{
	return _name;
}

Color::Color(string name, string hexVal)
{
	_name = name;
	_hexVal = hexVal;
}

Color::Color()
{
	_name = "";
	_hexVal = "";
}

string Color::strToHex(string str) const
{
	string hex = "00";
	int num = stoi(str);

	if (num / 16 == 10)
	{
		hex[0] = 'A';
	}
	if (num / 16 == 11)
	{
		hex[0] = 'B';
	}
	if (num / 16 == 12)
	{
		hex[0] = 'C';
	}
	if (num / 16 == 13)
	{
		hex[0] = 'D';
	}
	if (num / 16 == 14)
	{
		hex[0] = 'E';
	}
	if (num / 16 == 15)
	{
		hex[0] = 'F';
	}

	if (hex[0] == '0')
	{
		hex[0] = '0' + (num / 16);
	}



	if (num % 16 == 10)
	{
		hex[1] = 'A';
	}
	if (num % 16 == 11)
	{
		hex[1] = 'B';
	}
	if (num % 16 == 12)
	{
		hex[1] = 'C';
	}
	if (num % 16 == 13)
	{
		hex[1] = 'D';
	}
	if (num % 16 == 14)
	{
		hex[1] = 'E';
	}
	if (num % 16 == 15)
	{
		hex[1] = 'F';
	}

	if (hex[1] == '0')
	{
		hex[1] = '0' + (num % 16);
	}

	return hex;
}
