#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <map>
#include <random>
#include <ctime>
using namespace std;

mt19937 random_mt;

int Random(int min, int max)
{
	uniform_int_distribution<int> dist(min, max);
	return dist(random_mt);
}

struct state
{
	string _name;
	int _income;
	int _population;
	int _medIncome;
	int _houses;

	state();

};

state::state()
{

}



int main()
{
	cout << "1. Random Numbers\n";
	cout << "2. State Info\n";

	int option;
	cin >> option;

	if (option == 1)
	{
		int randomSeed;
		cout << "Random seed value: ";
		cin >> randomSeed;
		random_mt.seed(randomSeed);


		cout << "Number of times to roll the die: ";
		// user input
		int rolls;
		cin >> rolls;

		cout << "Number of sides on this die: ";
		// user input
		int sides;
		cin >> sides;

		  // Roll Dice
		map<int, int> rollin;
		for (int i = 1; i <= sides; i++)
		{
			rollin.emplace(i, 0);
		}
		for (int i = 0; i < rolls; i++)
		{
			int roll;
			roll = Random(1, sides);
			rollin[roll]++;
		}
		for (int i = 1; i <= sides; i++)
		{
			int rolls = rollin[i];
			cout << i << ": " << rolls << endl;
		}

	}
	else if (option == 2)
	{


		// Load the states
		ifstream inFile("states.csv");
		string token;
		getline(inFile, token);
		istringstream stream(token);
		map<string, state> states;
		while (getline(inFile, token))
		{
			istringstream stream(token);
			getline(stream, token, ',');
			state newState;
			newState._name = token;
			getline(stream, token, ',');
			newState._income = stoi(token);
			getline(stream, token, ',');
			newState._population = stoi(token);
			getline(stream, token, ',');
			newState._medIncome = stoi(token);
			getline(stream, token, ',');
			newState._houses = stoi(token);
			states[newState._name] = newState;
		}
		inFile.close();


		// Get input for option 1 (show all states) or 2 (do a search for a particular state)
		cout << "1. Print all states" << endl;
		cout << "2. Search for a state" << endl;

		cin >> option;
		if (option == 1)
		{
			map<string, state>::iterator iter = states.begin();
			for (; iter != states.end(); ++iter)
			{
				cout << iter->first << endl;
				cout << "Population: " << iter->second._population << endl;
				cout << "Per Capita Income: " << iter->second._income << endl;
				cout << "Median Household Income: " << iter->second._medIncome << endl;
				cout << "Number of Households: " << iter->second._houses << endl;

			}
		}
		if (option == 2)
		{
			string search;
			cin >> search;
			if (states.find(search) == states.end())
			{
				cout << "No match found for " << search << endl;
			}
			else
			{
				cout << states[search]._name << endl;
				cout << "Population: " << states[search]._population << endl;
				cout << "Per Capita Income: " << states[search]._income << endl;
				cout << "Median Household Income: " << states[search]._medIncome << endl;
				cout << "Number of Households: " << states[search]._houses << endl;
			}
			
		}
	}

	return 0;
}
