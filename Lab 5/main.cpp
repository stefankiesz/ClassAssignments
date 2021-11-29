#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	cout << "Which file(s) to open?\n";
	cout << "1. friendlyships.shp" << endl;
	cout << "2. enemyships.shp" << endl;
	cout << "3. Both files" << endl;
	int option;
	cin >> option;

	/* Load files here */
	vector<string> names;
	vector<string> classes;
	vector<short> lengths;
	vector<int> shields;
	vector<float> warps;
	vector<vector<string>> wepNames;
	vector<vector<int>> wepRat;
	vector<vector<float>> wepCons;


	if (option == 3)
	{
		ifstream inFile("C:/Users/Stefan/Desktop/friendlyships.shp", ios_base::binary);
		unsigned int count;
		inFile.read((char*)&count, sizeof(count));
		for (unsigned int i = 0; i < count; i++)
		{
			unsigned int count2;
			inFile.read((char*)&count2, sizeof(count2));
			char* buffer = new char[count2];
			inFile.read(buffer, count2);
			string word = buffer;
			names.push_back(buffer);
			delete[] buffer;

			inFile.read((char*)&count2, sizeof(count2));
			buffer = new char[count2];
			inFile.read(buffer, count2);
			word = buffer;
			classes.push_back(buffer);
			delete[] buffer;

			short numS;
			inFile.read((char*)&numS, sizeof(numS));
			lengths.push_back(numS);

			int numI;
			inFile.read((char*)&numI, sizeof(numI));
			shields.push_back(numI);

			float numF;
			inFile.read((char*)&numF, sizeof(numF));
			warps.push_back(numF);

			wepNames.push_back(vector<string>());
			wepRat.push_back(vector<int>());
			wepCons.push_back(vector<float>());

			inFile.read((char*)&count2, sizeof(count2));
			for (unsigned int i = 0; i < count2; i++)
			{
				unsigned int count3;
				inFile.read((char*)&count3, sizeof(count3));
				char* buffer = new char[count3];
				inFile.read(buffer, count3);
				string word = buffer;
				wepNames[wepNames.size() - 1].push_back(buffer);
				delete[] buffer;

				inFile.read((char*)&numI, sizeof(numI));
				wepRat[wepRat.size() - 1].push_back(numI);

				inFile.read((char*)&numF, sizeof(numF));
				wepCons[wepCons.size() - 1].push_back(numF);
			}
		}
			ifstream inFile2("C:/Users/Stefan/Desktop/enemyships.shp", ios_base::binary);
			inFile2.read((char*)&count, sizeof(count));
			for (unsigned int i = 0; i < count; i++)
			{
				unsigned int count2;
				inFile2.read((char*)&count2, sizeof(count2));
				char* buffer = new char[count2];
				inFile2.read(buffer, count2);
				string word = buffer;
				names.push_back(buffer);
				delete[] buffer;

				inFile2.read((char*)&count2, sizeof(count2));
				buffer = new char[count2];
				inFile2.read(buffer, count2);
				word = buffer;
				classes.push_back(buffer);
				delete[] buffer;

				short numS;
				inFile2.read((char*)&numS, sizeof(numS));
				lengths.push_back(numS);

				int numI;
				inFile2.read((char*)&numI, sizeof(numI));
				shields.push_back(numI);

				float numF;
				inFile2.read((char*)&numF, sizeof(numF));
				warps.push_back(numF);

				wepNames.push_back(vector<string>());
				wepRat.push_back(vector<int>());
				wepCons.push_back(vector<float>());

				inFile2.read((char*)&count2, sizeof(count2));
				for (unsigned int i = 0; i < count2; i++)
				{
					unsigned int count3;
					inFile2.read((char*)&count3, sizeof(count3));
					char* buffer = new char[count3];
					inFile2.read(buffer, count3);
					string word = buffer;
					wepNames[wepNames.size() - 1].push_back(buffer);
					delete[] buffer;

					inFile2.read((char*)&numI, sizeof(numI));
					wepRat[wepRat.size() - 1].push_back(numI);

					inFile2.read((char*)&numF, sizeof(numF));
					wepCons[wepCons.size() - 1].push_back(numF);
				}
			}
			
	}
	else
	{
	ifstream inFile;
		if (option == 1)
		{
				inFile.open("C:/Users/Stefan/Desktop/friendlyships.shp", ios_base::binary);
			}
			else {
				inFile.open("C:/Users/Stefan/Desktop/enemyships.shp", ios_base::binary);
			}
			unsigned int count;
			inFile.read((char*)&count, sizeof(count));
			for (unsigned int i = 0; i < count; i++)
			{
				unsigned int count2;
				inFile.read((char*)&count2, sizeof(count2));
				char* buffer = new char[count2];
				inFile.read(buffer, count2);
				string word = buffer;
				names.push_back(buffer);
				delete[] buffer;

				inFile.read((char*)&count2, sizeof(count2));
				buffer = new char[count2];
				inFile.read(buffer, count2);
				word = buffer;
				classes.push_back(buffer);
				delete[] buffer;

				short numS;
				inFile.read((char*)&numS, sizeof(numS));
				lengths.push_back(numS);

				int numI;
				inFile.read((char*)&numI, sizeof(numI));
				shields.push_back(numI);

				float numF;
				inFile.read((char*)&numF, sizeof(numF));
				warps.push_back(numF);

				wepNames.push_back(vector<string>());
				wepRat.push_back(vector<int>());
				wepCons.push_back(vector<float>());

				inFile.read((char*)&count2, sizeof(count2));
				for (unsigned int i = 0; i < count2; i++)
				{
					unsigned int count3;
					inFile.read((char*)&count3, sizeof(count3));
					char* buffer = new char[count3];
					inFile.read(buffer, count3);
					string word = buffer;
					wepNames[wepNames.size() - 1].push_back(buffer);
					delete[] buffer;

					inFile.read((char*)&numI, sizeof(numI));
					wepRat[wepRat.size() - 1].push_back(numI);

					inFile.read((char*)&numF, sizeof(numF));
					wepCons[wepCons.size() - 1].push_back(numF);
				}
			}
		
	}

	



	cout << "1. Print all ships" << endl;
	cout << "2. Starship with the strongest weapon" << endl;
	cout << "3. Strongest starship overall" << endl;
	cout << "4. Weakest ship (ignoring unarmed)" << endl;
	cout << "5. Unarmed ships" << endl;

	cin >> option;

	/* Work your magic here */
	if (option == 1)
	{
		for (unsigned int i = 0; i < names.size(); i++)
		{
			cout << "Name: " << names[i] << endl;
			cout << "Class: " << classes[i] << endl;
			cout << "Length: " << lengths[i] << endl;
			cout << "Shield capacity: " << shields[i] << endl;
			cout << "Maximum Warp: " << warps[i] << endl;
			cout << "Armaments:" << endl;
			unsigned int totFire = 0;
			if (wepNames[i].size() < 1)
			{
				cout << "Unarmed";
			}
			else 
			{
				for (unsigned int j = 0; j < wepNames[i].size(); j++)
				{
					totFire += wepRat[i][j];
					cout << wepNames[i][j] << ", ";
					cout << wepRat[i][j] << ", ";
					cout << wepCons[i][j] << endl;
				}
				cout << "Total firepower: " << totFire << endl;
			}

			cout << endl;
		}

	}
	else 
	{
		if (option == 2)
		{
			unsigned int maxInd = 0;
			int max = 0;
			for (unsigned int i = 0; i < wepRat.size(); i++)
			{
				for (unsigned int j = 0; j < wepRat[i].size(); j++)
				{
					if (wepRat[i][j] > max)
					{
						max = wepRat[i][j];
						maxInd = i;
					}
				}
			}
			unsigned int i = maxInd;
			cout << "Name: " << names[i] << endl;
			cout << "Class: " << classes[i] << endl;
			cout << "Length: " << lengths[i] << endl;
			cout << "Shield capacity: " << shields[i] << endl;
			cout << "Maximum Warp: " << warps[i] << endl;
			cout << "Armaments:" << endl;
			unsigned int totFire = 0;
			if (wepNames[i].size() < 1)
			{
				cout << "Unarmed";
			}
			else
			{
				for (unsigned int j = 0; j < wepNames[i].size(); j++)
				{
					totFire += wepRat[i][j];
					cout << wepNames[i][j] << ", ";
					cout << wepRat[i][j] << ", ";
					cout << wepCons[i][j] << endl;
				}
				cout << "Total firepower: " << totFire << endl;
			}

			cout << endl;
		}
		else
		{
			if (option == 3)
			{
				unsigned int maxInd = 0;
				int max = 0;
				for (unsigned int i = 0; i < wepRat.size(); i++)
				{
					int tot = 0;
					for (unsigned int j = 0; j < wepRat[i].size(); j++)
					{
						tot += wepRat[i][j];
					}
					if (tot > max)
					{
						max = tot;
						maxInd = i;
					}
				}
				unsigned int i = maxInd;
				cout << "Name: " << names[i] << endl;
				cout << "Class: " << classes[i] << endl;
				cout << "Length: " << lengths[i] << endl;
				cout << "Shield capacity: " << shields[i] << endl;
				cout << "Maximum Warp: " << warps[i] << endl;
				cout << "Armaments:" << endl;
				unsigned int totFire = 0;
				if (wepNames[i].size() < 1)
				{
					cout << "Unarmed";
				}
				else
				{
					for (unsigned int j = 0; j < wepNames[i].size(); j++)
					{
						totFire += wepRat[i][j];
						cout << wepNames[i][j] << ", ";
						cout << wepRat[i][j] << ", ";
						cout << wepCons[i][j] << endl;
					}
					cout << "Total firepower: " << totFire << endl;
				}

				cout << endl;
			}
			else if (option == 4)
			{
				unsigned int minInd = 0;
				int min = 2147483647;
				for (unsigned int i = 0; i < wepRat.size(); i++)
				{
					int tot = 0;
					for (unsigned int j = 0; j < wepRat[i].size(); j++)
					{
						tot += wepRat[i][j];
					}
					if (tot < min && tot > 0)
					{
						min = tot;
						minInd = i;
					}
				}
				unsigned int i = minInd;
				cout << "Name: " << names[i] << endl;
				cout << "Class: " << classes[i] << endl;
				cout << "Length: " << lengths[i] << endl;
				cout << "Shield capacity: " << shields[i] << endl;
				cout << "Maximum Warp: " << warps[i] << endl;
				cout << "Armaments:" << endl;
				unsigned int totFire = 0;
				if (wepNames[i].size() < 1)
				{
					cout << "Unarmed";
				}
				else
				{
					for (unsigned int j = 0; j < wepNames[i].size(); j++)
					{
						totFire += wepRat[i][j];
						cout << wepNames[i][j] << ", ";
						cout << wepRat[i][j] << ", ";
						cout << wepCons[i][j] << endl;
					}
					cout << "Total firepower: " << totFire << endl;
				}

				cout << endl;
			}
			else if (option == 5)
			{
	
				for (unsigned int i = 0; i < wepRat.size(); i++)
				{
					int tot = 0;
					for (unsigned int j = 0; j < wepRat[i].size(); j++)
					{
						tot += wepRat[i][j];
					}
					if (tot == 0)
					{
						cout << "Name: " << names[i] << endl;
						cout << "Class: " << classes[i] << endl;
						cout << "Length: " << lengths[i] << endl;
						cout << "Shield capacity: " << shields[i] << endl;
						cout << "Maximum Warp: " << warps[i] << endl;
						cout << "Armaments:" << endl;
						cout << "Unarmed" << endl;
						cout << endl;

					

					}
				}
				
			}
		}
	}


	return 0;
}