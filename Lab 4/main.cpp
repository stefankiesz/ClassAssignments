#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<string> setNums;
vector<string> themes;
vector<string> names;
vector<int> minis;
vector<int> parts;
vector<double> prices;

void printSet(unsigned int index);

int main()
{

	cout << std::fixed << setprecision(2);
	cout << "Which file(s) to open?\n";
	cout << "1. lego1.csv" << endl;
	cout << "2. lego2.csv" << endl;
	cout << "3. lego3.csv" << endl;
	cout << "4. All 3 files" << endl;
	int option;
	cin >> option;

	

	/*======= Load data from file(s) =======*/
	if (option == 4)
	{

		ifstream inFile("C:/Users/Stefan/Desktop/lego1.csv");
		string line;
		string token;
		getline(inFile, line);
		istringstream stream(line);
		while (getline(inFile, line))
		{
			istringstream stream(line);

			getline(stream, token, ',');
			setNums.push_back(token);
			getline(stream, token, ',');
			themes.push_back(token);
			getline(stream, token, ',');
			names.push_back(token);
			getline(stream, token, ',');
			minis.push_back(stoi(token));
			getline(stream, token, ',');
			parts.push_back(stoi(token));
			getline(stream, token);
			prices.push_back(stod(token));

		}
		ifstream inFile2("C:/Users/Stefan/Desktop/lego2.csv");
		getline(inFile2, line);
		//istringstream stream(line);

		while (getline(inFile2, line))
		{
			istringstream stream(line);

			getline(stream, token, ',');
			setNums.push_back(token);
			getline(stream, token, ',');
			themes.push_back(token);
			getline(stream, token, ',');
			names.push_back(token);
			getline(stream, token, ',');
			minis.push_back(stoi(token));
			getline(stream, token, ',');
			parts.push_back(stoi(token));
			getline(stream, token);
			prices.push_back(stod(token));
		}

		ifstream inFile3("C:/Users/Stefan/Desktop/lego3.csv");
		getline(inFile3, line);
		//istringstream stream(line);

		while (getline(inFile3, line))
		{
			istringstream stream(line);

			getline(stream, token, ',');
			setNums.push_back(token);
			getline(stream, token, ',');
			themes.push_back(token);
			getline(stream, token, ',');
			names.push_back(token);
			getline(stream, token, ',');
			minis.push_back(stoi(token));
			getline(stream, token, ',');
			parts.push_back(stoi(token));
			getline(stream, token);
			prices.push_back(stod(token));

		}

	}
	else {

		if (option == 1)
		{

			ifstream inFile("C:/Users/Stefan/Desktop/lego1.csv");
			string line;
			string token;
			getline(inFile, line);
			istringstream stream(line);
			while (getline(inFile, line))
			{
				istringstream stream(line);

				getline(stream, token, ',');
				setNums.push_back(token);
				getline(stream, token, ',');
				themes.push_back(token);
				getline(stream, token, ',');
				names.push_back(token);
				getline(stream, token, ',');
				minis.push_back(stoi(token));
				getline(stream, token, ',');
				parts.push_back(stoi(token));
				getline(stream, token);
				prices.push_back(stod(token));

			}
		}
		else if (option == 2)
		{

			ifstream inFile("C:/Users/Stefan/Desktop/lego2.csv");
			string line;
			string token;
			getline(inFile, line);
			istringstream stream(line);
			while (getline(inFile, line))
			{
				istringstream stream(line);

				getline(stream, token, ',');
				setNums.push_back(token);
				getline(stream, token, ',');
				themes.push_back(token);
				getline(stream, token, ',');
				names.push_back(token);
				getline(stream, token, ',');
				minis.push_back(stoi(token));
				getline(stream, token, ',');
				parts.push_back(stoi(token));
				getline(stream, token);
				prices.push_back(stod(token));

			}
		}
		else if (option == 3)
		{

			ifstream inFile("C:/Users/Stefan/Desktop/lego3.csv");
			string line;
			string token;
			getline(inFile, line);
			istringstream stream(line);
			while (getline(inFile, line))
			{
				istringstream stream(line);

				getline(stream, token, ',');
				setNums.push_back(token);
				getline(stream, token, ',');
				themes.push_back(token);
				getline(stream, token, ',');
				names.push_back(token);
				getline(stream, token, ',');
				minis.push_back(stoi(token));
				getline(stream, token, ',');
				parts.push_back(stoi(token));
				getline(stream, token);
				prices.push_back(stod(token));

			}
		}
	}

		

	cout << "1. Most Expensive set" << endl;
	cout << "2. Largest piece count" << endl;
	cout << "3. Search for set name containing..." << endl;
	cout << "4. Search themes..." << endl;
	cout << "5. Part count information" << endl;
	cout << "6. Price information" << endl;
	cout << "7. Minifigure information" << endl;
	cout << "8. If you bought one of everything..." << endl;
	cout << "0. Exit" << endl;

	int choice;
	cin >> choice;
	cin.get();  // Clear newline character for any later input

	/*======= Print out how many sets were loaded =======*/
	cout << "Total number of sets: " << setNums.size() << endl;
	cout << endl;

	/*======= Based on the choice, execute the appropriate task and show the results =======*/
	unsigned int maxAt;

	if (choice == 1)
	{
		maxAt = 0;
		for (unsigned int i = 0; i < prices.size(); i++)
		{
			if (prices[i] > prices[maxAt])
			{ 
				maxAt = i;
			}
		}
		cout << "The most expensive set is:" << endl;
		printSet(maxAt);

	}

	if (choice == 2)
	{
		maxAt = 0;
		for (unsigned int i = 0; i < prices.size(); i++)
		{
			if (parts[i] > parts[maxAt])
			{
				maxAt = i;
			}
		}
		cout << "The set with the highest parts count:" << endl;
		printSet(maxAt);

	}

	if (choice == 3)
	{
		bool found = false;
		string search;
		getline(cin, search);
		for (unsigned int i = 0; i < prices.size(); i++)
		{
			if (names[i].find(search) != string::npos)
			{
				found = true;
				break;
			}
		}
		if (found)
		{
			cout << "Sets matching \"" << search << "\":" << endl;
			for (unsigned int i = 0; i < prices.size(); i++)
			{
				if (names[i].find(search) != string::npos)
				{
					cout << setNums[i] << " " << names[i] << " $" << prices[i] << endl;
				}
			}

		}
		else
		{
			cout << "No sets found matching that search term";
		}
	}

	if (choice == 4)
	{
		string search;
		getline(cin, search);
		bool found = false;
		for (unsigned int i = 0; i < prices.size(); i++)
		{
			if (themes[i].find(search) != string::npos)
			{
				found = true;
				break;
			}
		}
		if (found)
		{
			cout << "Sets matching \"" << search << "\":" << endl;
			for (unsigned int i = 0; i < prices.size(); i++)
			{
				if (themes[i].find(search) != string::npos)
				{
					cout << setNums[i] << " " << names[i] << " $" << prices[i] << endl;
				}
			}

		}
		else
		{
			cout << "No sets found matching that search term";
		}
		
	}

	if (choice == 5)
	{
		int totParts = 0;
		for (unsigned int i = 0; i < parts.size(); i++)
		{
			totParts += parts[i];
		}
		cout << "Average part count for " << parts.size() << " sets: " << totParts / parts.size() << endl;
	}

	if (choice == 6)
	{
		unsigned int minCost = 0;
		unsigned int maxCost = 0;
		double totCost = 0;
		for (unsigned int i = 0; i < prices.size(); i++)
		{
			if (prices[i] < prices[minCost])
			{
				minCost = i;
			}
			if (prices[i] > prices[maxCost])
			{
				maxCost = i;
			}
			totCost += prices[i];
		}
		cout << "Average price for " << prices.size() << " sets: $" << totCost / prices.size() << endl;
		cout << "Least expensive set:" << endl;
		printSet(minCost);
		cout << "Most expensive set:" << endl;
		printSet(maxCost);
		
	}

	if (choice == 7)
	{
		unsigned int maxFigs = 0;
		unsigned int totFigs = 0;
		for (unsigned int i = 0; i < prices.size(); i++)
		{
			if (minis[i] > minis[maxFigs])
			{
				maxFigs = i;
			}
			totFigs += minis[i];
		}
		cout << "Average number of minifigures: " << totFigs / prices.size() << endl;
		cout << "Set with the most minifigures:" << endl;
		printSet(maxFigs);
	}

	if (choice == 8)
	{
		cout << "If you bought one of everything..." << endl;
		double totCost = 0;
		unsigned int totParts = 0;
		unsigned int totFigs = 0;
		for (unsigned int i = 0; i < prices.size(); i++)
		{
			totCost += prices[i];
			totParts += parts[i];
			totFigs += minis[i];
		}
		cout << "It would cost: $" << totCost << endl;
		cout << "You would have " << totParts << " pieces in your collection" << endl;
		cout << "You would have an army of " << totFigs << " minifigures!" << endl;
	}
	cout << endl;

	return 0;
}

void printSet(unsigned int index)
{
	cout << "Name: " << names[index] << endl;
	cout << "Number: " << setNums[index] << endl;
	cout << "Theme: " << themes[index] << endl;
	cout << "Price: $" << prices[index] << endl;
	cout << "Minifigures: " << minis[index] << endl;
	cout << "Piece count: " << parts[index] << endl;
}

