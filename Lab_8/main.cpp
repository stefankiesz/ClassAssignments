#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <map>
#include "Color.h"
using namespace std;

void ReadFile(const char* filename, map<string, Color>& colors);
void PrintColors(const map<string, Color>& colors);
void PrintColor(const Color& color);
void SearchForColor(map<string, Color>& colors);
string strToHex(string str);
vector<int> strToRGB(string str);

int main()
{
	cout << "1-6: Load colors1/2/3/4/5/6.txt" << endl;
	cout << "7. Load all 6 files" << endl;
	int choice;
	cin >> choice;

	map<string, Color> colors;
	if (choice >= 1 && choice <= 6)
	{
		string file = "colors" + to_string(choice) + ".txt";
		ReadFile(file.c_str(), colors);
	}
	else if (choice == 7)
	{
		for (int i = 1; i <= 6; i++)
		{
			string file = "colors" + to_string(i) + ".txt";
			ReadFile(file.c_str(), colors);
		}

	}

	// Secondary menu
	cout << "1. Show all colors" << endl;
	cout << "2. Search for a color" << endl;
	cin >> choice;

	if (choice == 1)
		PrintColors(colors);
	else if (choice == 2)
		SearchForColor(colors);


	return 0;
}

unsigned int counter = 0;
void ReadFile(const char* filename, map<string, Color>& colors)
{
	// TODO: Read the file, create and store some Color objects
	ifstream inFile("C:/Users/Stefan/Downloads/Lab 8 - Number Conversion/colors2.txt");
	string token;
	istringstream stream(token);
	while (getline(inFile, token))
	{
		istringstream stream(token);
		getline(stream, token, ' ');
		Color newColor;
		newColor._name = token;
		getline(stream, token, ' ');
		strToHex(token);
		newColor._hexVal = token;
		newColor._R = (unsigned char)((stoi(token) >> 16) & 255);
		newColor._G = (unsigned char)((stoi(token) >> 8) & 255);
		newColor._B = (unsigned char)(stoi(token) & 255);
		colors[newColor._name] = newColor;
		counter++;
	}
	inFile.close();
}
void PrintColors(const map<string, Color>& colors)
{
	// TODO: iterate through all entries in the map and print each color, one at a time
	// Print out the color count afterward

	map<string, Color>::const_iterator iter = colors.begin();
	for (; iter != colors.end(); ++iter)
	{
		//cout << iter->first << endl;
		//cout << iter->second._hexVal << endl;
		PrintColor(iter->second);

	}
	cout << "Number of colors: " << counter << endl;
}
void PrintColor(const Color& color)
{
	cout << left << setw(20) << color.GetName();
	cout << right << setw(10) << color.GetHexValue();
	cout << "\t\t" << (int)color.GetR() << "," << (int)color.GetG() << "," << (int)color.GetB() << endl;
}
void SearchForColor(map<string, Color>& colors)
{
	// TODO: Get some input, check if that key exists, then print out the color (or an error message)
	string search;
	cin >> search;
	if (colors.find(search) == colors.end())
	{
		cout << search << " not found!" << endl;
	}
	else
	{
		PrintColor(colors[search]);
	}

}

string strToHex(string str)
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
		hex[0] = num / 16;
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

vector<int> strToRGB(string str)
{
	vector<int> rgb;

	int num = stoi(str);
	rgb.push_back(((num << 16) & 255));
	rgb.push_back(((num << 8) & 255));
	rgb.push_back((num & 255));

	return rgb;
}