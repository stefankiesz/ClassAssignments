#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;


void test()
{

	unsigned short width;
	unsigned short height;
	//vector<vector<unsigned char>> pixels;
	//vector<vector<unsigned char>> pixels2;

	ifstream inFile("C:/Users/Stefan/Desktop/ClassAssignments/Project_2/extracredit.tga", ios_base::binary);
	ifstream inFile2("C:/Users/Stefan/Desktop/ImageProcessing/examples/EXAMPLE_extracredit.tga", ios_base::binary);

	unsigned char charCount;
	unsigned short shortCount;

	inFile.read((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&shortCount, sizeof(shortCount));
	inFile2.read((char*)&shortCount, sizeof(shortCount));

	inFile.read((char*)&shortCount, sizeof(shortCount));
	inFile2.read((char*)&shortCount, sizeof(shortCount));

	inFile.read((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));


	inFile.read((char*)&shortCount, sizeof(shortCount));
	inFile2.read((char*)&shortCount, sizeof(shortCount));

	inFile.read((char*)&shortCount, sizeof(shortCount));
	inFile2.read((char*)&shortCount, sizeof(shortCount));


	inFile.read((char*)&width, sizeof(width));
	inFile2.read((char*)&width, sizeof(width));

	inFile.read((char*)&height, sizeof(height));
	inFile2.read((char*)&height, sizeof(height));


	inFile.read((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));


	inFile.read((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));


	cout << width << endl;
	cout << height << endl;


	unsigned char pix;
	unsigned char pix2;
	unsigned char pix3;
	unsigned int counter = 0;

	for (unsigned int i = 0; i < (unsigned int)width * height; i++)
	{
		
		inFile.read((char*)&pix, sizeof(pix));
		inFile2.read((char*)&pix2, sizeof(pix2));
		if (pix != pix2)
		{
			cout << "failure" << endl;
			cout << (int)pix << endl;
			cout << (int)pix2 << endl << endl;

		}
		inFile.read((char*)&pix, sizeof(pix));
		inFile2.read((char*)&pix2, sizeof(pix2));
		if (pix != pix2)
		{
			cout << "failure" << endl;
			cout << (int)pix << endl;
			cout << (int)pix2 << endl << endl;

		}
		inFile.read((char*)&pix, sizeof(pix));
		inFile2.read((char*)&pix2, sizeof(pix2));
		if (pix != pix2)
		{
			cout << "failure" << endl;
			cout << (int)pix << endl;
			cout << (int)pix2 << endl << endl;

		}
		counter++;
	}
}


void part1()
{
	unsigned short width;
	unsigned short height;
	//vector<vector<unsigned char>> pixels;
	//vector<vector<unsigned char>> pixels2;

	ifstream inFile("C:/Users/Stefan/Desktop/ImageProcessing/input/layer1.tga", ios_base::binary);
	ifstream inFile2("C:/Users/Stefan/Desktop/ImageProcessing/input/pattern1.tga", ios_base::binary);
	ifstream inFile3("C:/Users/Stefan/Desktop/ImageProcessing/examples/EXAMPLE_part1.tga", ios_base::binary);
	ofstream file("part1.tga", ios_base::binary);

	unsigned char charCount;
	unsigned short shortCount;

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&shortCount, sizeof(shortCount));
	file.write((char*)&shortCount, sizeof(shortCount));
	inFile2.read((char*)&shortCount, sizeof(shortCount));

	inFile.read((char*)&shortCount, sizeof(shortCount));
	file.write((char*)&shortCount, sizeof(shortCount));
	inFile2.read((char*)&shortCount, sizeof(shortCount));

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));


	inFile.read((char*)&shortCount, sizeof(shortCount));
	file.write((char*)&shortCount, sizeof(shortCount));
	inFile2.read((char*)&shortCount, sizeof(shortCount));

	inFile.read((char*)&shortCount, sizeof(shortCount));
	file.write((char*)&shortCount, sizeof(shortCount));
	inFile2.read((char*)&shortCount, sizeof(shortCount));


	inFile.read((char*)&width, sizeof(width));
	file.write((char*)&width, sizeof(width));
	inFile2.read((char*)&width, sizeof(width));

	inFile.read((char*)&height, sizeof(height));
	file.write((char*)&height, sizeof(height));
	inFile2.read((char*)&height, sizeof(height));


	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));


	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));


	cout << width << endl;
	cout << height << endl;


	unsigned char pix;
	unsigned char pix2;
	unsigned char pix3;
	unsigned int counter = 0;

	for (unsigned int i = 0; i < (unsigned int)width * height; i++)
	{
		//pixels.push_back(vector<unsigned char>());
		//pixels2.push_back(vector<unsigned char>());

		inFile.read((char*)&pix, sizeof(pix));
		inFile2.read((char*)&pix2, sizeof(pix2));
		pix3 = (pix * pix2 / 255.0) + 0.5f;
		file.write((char*)&pix3, sizeof(pix));
		//pixels[i].push_back(pix);
		//pixels2[i].push_back(pix);
		inFile.read((char*)&pix, sizeof(pix));
		inFile2.read((char*)&pix2, sizeof(pix2));
		pix3 = (pix * pix2 / 255.0) + 0.5f;
		file.write((char*)&pix3, sizeof(pix));
		//pixels[i].push_back(pix);
		//pixels2[i].push_back(pix);
		inFile.read((char*)&pix, sizeof(pix));
		inFile2.read((char*)&pix2, sizeof(pix2));
		pix3 = (pix * pix2 / 255.0) + 0.5f;
		file.write((char*)&pix3, sizeof(pix));
		//pixels[i].push_back(pix);
		//pixels2[i].push_back(pix);
		counter++;
	}

	file.close();
}


void part2()
{
	unsigned short width;
	unsigned short height;
	//vector<vector<unsigned char>> pixels;
	//vector<vector<unsigned char>> pixels2;

	ifstream inFile("C:/Users/Stefan/Desktop/ImageProcessing/input/layer2.tga", ios_base::binary);
	ifstream inFile2("C:/Users/Stefan/Desktop/ImageProcessing/input/car.tga", ios_base::binary);
	ofstream file("part2.tga", ios_base::binary);

	unsigned char charCount;
	unsigned short shortCount;

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&shortCount, sizeof(shortCount));
	file.write((char*)&shortCount, sizeof(shortCount));
	inFile2.read((char*)&shortCount, sizeof(shortCount));

	inFile.read((char*)&shortCount, sizeof(shortCount));
	file.write((char*)&shortCount, sizeof(shortCount));
	inFile2.read((char*)&shortCount, sizeof(shortCount));

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));


	inFile.read((char*)&shortCount, sizeof(shortCount));
	file.write((char*)&shortCount, sizeof(shortCount));
	inFile2.read((char*)&shortCount, sizeof(shortCount));

	inFile.read((char*)&shortCount, sizeof(shortCount));
	file.write((char*)&shortCount, sizeof(shortCount));
	inFile2.read((char*)&shortCount, sizeof(shortCount));


	inFile.read((char*)&width, sizeof(width));
	file.write((char*)&width, sizeof(width));
	inFile2.read((char*)&width, sizeof(width));

	inFile.read((char*)&height, sizeof(height));
	file.write((char*)&height, sizeof(height));
	inFile2.read((char*)&height, sizeof(height));


	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));


	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));


	cout << width << endl;
	cout << height << endl;


	unsigned char pix;
	unsigned char pix2;
	unsigned char pix3;
	int pixl3;
	unsigned int counter = 0;

	for (unsigned int i = 0; i < (unsigned int)width * height; i++)
	{
		//pixels.push_back(vector<unsigned char>());
		//pixels2.push_back(vector<unsigned char>());

		inFile.read((char*)&pix, sizeof(pix));
		inFile2.read((char*)&pix2, sizeof(pix2));
		pixl3 = pix2 - pix;
		if (pixl3 < 0) { pixl3 = 0; }
		pix3 = pixl3;
		file.write((char*)&pix3, sizeof(pix3));
		//pixels[i].push_back(pix);
		//pixels2[i].push_back(pix);
		inFile.read((char*)&pix, sizeof(pix));
		inFile2.read((char*)&pix2, sizeof(pix2));
		pixl3 = pix2 - pix;
		if (pixl3 < 0) { pixl3 = 0; }
		pix3 = pixl3;
		file.write((char*)&pix3, sizeof(pix3));
		//pixels[i].push_back(pix);
		//pixels2[i].push_back(pix);
		inFile.read((char*)&pix, sizeof(pix));
		inFile2.read((char*)&pix2, sizeof(pix2));
		pixl3 = pix2 - pix;
		if (pixl3 < 0) { pixl3 = 0; }
		pix3 = pixl3;
		file.write((char*)&pix3, sizeof(pix3));
		//pixels[i].push_back(pix);
		//pixels2[i].push_back(pix);
		counter++;
	}

	file.close();
}


void part3()
{
	unsigned short width;
	unsigned short height;
	//vector<vector<unsigned char>> pixels;
	//vector<vector<unsigned char>> pixels2;

	ifstream inFile("C:/Users/Stefan/Desktop/ImageProcessing/input/layer1.tga", ios_base::binary);
	ifstream inFile2("C:/Users/Stefan/Desktop/ImageProcessing/input/pattern2.tga", ios_base::binary);
	ifstream inFile3("C:/Users/Stefan/Desktop/ImageProcessing/input/text.tga", ios_base::binary);

	ofstream file("part3.tga", ios_base::binary);

	unsigned char charCount;
	unsigned short shortCount;

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));
	inFile3.read((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));
	inFile3.read((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));
	inFile3.read((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&shortCount, sizeof(shortCount));
	file.write((char*)&shortCount, sizeof(shortCount));
	inFile2.read((char*)&shortCount, sizeof(shortCount));
	inFile3.read((char*)&shortCount, sizeof(shortCount));

	inFile.read((char*)&shortCount, sizeof(shortCount));
	file.write((char*)&shortCount, sizeof(shortCount));
	inFile2.read((char*)&shortCount, sizeof(shortCount));
	inFile3.read((char*)&shortCount, sizeof(shortCount));

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));
	inFile3.read((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&shortCount, sizeof(shortCount));
	file.write((char*)&shortCount, sizeof(shortCount));
	inFile2.read((char*)&shortCount, sizeof(shortCount));
	inFile3.read((char*)&shortCount, sizeof(shortCount));

	inFile.read((char*)&shortCount, sizeof(shortCount));
	file.write((char*)&shortCount, sizeof(shortCount));
	inFile2.read((char*)&shortCount, sizeof(shortCount));
	inFile3.read((char*)&shortCount, sizeof(shortCount));


	inFile.read((char*)&width, sizeof(width));
	file.write((char*)&width, sizeof(width));
	inFile2.read((char*)&shortCount, sizeof(shortCount));
	inFile3.read((char*)&shortCount, sizeof(shortCount));

	inFile.read((char*)&height, sizeof(height));
	file.write((char*)&height, sizeof(height));
	inFile2.read((char*)&shortCount, sizeof(shortCount));
	inFile3.read((char*)&shortCount, sizeof(shortCount));


	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));
	inFile3.read((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));
	inFile3.read((char*)&charCount, sizeof(charCount));


	cout << width << endl;
	cout << height << endl;


	unsigned char pix;
	unsigned char pix2;
	unsigned char pix3;
	unsigned char pix4;
	unsigned int counter = 0;

	int pixl;
	int pixl2;
	int pixl4;
	int pix6;

	for (unsigned int i = 0; i < (unsigned int)width * height; i++)
	{
		//pixels.push_back(vector<unsigned char>());
		//pixels2.push_back(vector<unsigned char>());

		inFile.read((char*)&pix, sizeof(pix));
		inFile2.read((char*)&pix2, sizeof(pix2));
		inFile3.read((char*)&pix3, sizeof(pix3));
		pixl = pix;
		pixl2 = pix2;
		pixl4 = (1 - (1 - ((int)(((pixl * pixl2) / 255.0) + 0.5f) / 255.0)) * ((1 - pix3 / 255.0))) * 255.0 + 0.5f;
		if (pixl4 < 0) { pixl4 = 0; };
		if (pixl4 > 255) { pixl4 = 255; };
		pix4 = pixl4;
		file.write((char*)&pix4, sizeof(pix));
		//pixels[i].push_back(pix);
		//pixels2[i].push_back(pix);
		inFile.read((char*)&pix, sizeof(pix));
		inFile2.read((char*)&pix2, sizeof(pix2));
		inFile3.read((char*)&pix3, sizeof(pix3));
		pixl = pix;
		pixl2 = pix2;
		pixl4 = (1 - (1 - ((int)(((pixl * pixl2) / 255.0) + 0.5f) / 255.0)) * ((1 - pix3 / 255.0))) * 255.0 + 0.5f;
		if (pixl4 < 0) { pixl4 = 0; };
		if (pixl4 > 255) { pixl4 = 255; };
		pix4 = pixl4;
		file.write((char*)&pix4, sizeof(pix));
		//pixels[i].push_back(pix);
		//pixels2[i].push_back(pix);
		inFile.read((char*)&pix, sizeof(pix));
		inFile2.read((char*)&pix2, sizeof(pix2));
		inFile3.read((char*)&pix3, sizeof(pix3));
		pixl = pix;
		pixl2 = pix2;
		pixl4 = (1 - (1 - ((int)(((pixl * pixl2) / 255.0) + 0.5f) / 255.0)) * ((1 - pix3 / 255.0))) * 255.0 + 0.5f;
		if (pixl4 < 0) { pixl4 = 0; };
		if (pixl4 > 255) { pixl4 = 255; };
		pix4 = pixl4;
		file.write((char*)&pix4, sizeof(pix));
		//pixels[i].push_back(pix);
		//pixels2[i].push_back(pix);
		counter++;
	}

	file.close();
}


void part4()
{
	unsigned short width;
	unsigned short height;
	//vector<vector<unsigned char>> pixels;
	//vector<vector<unsigned char>> pixels2;

	ifstream inFile("C:/Users/Stefan/Desktop/ImageProcessing/input/layer2.tga", ios_base::binary);
	ifstream inFile2("C:/Users/Stefan/Desktop/ImageProcessing/input/circles.tga", ios_base::binary);
	ifstream inFile3("C:/Users/Stefan/Desktop/ImageProcessing/input/pattern2.tga", ios_base::binary);

	ofstream file("part4.tga", ios_base::binary);

	unsigned char charCount;
	unsigned short shortCount;

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));
	inFile3.read((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));
	inFile3.read((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));
	inFile3.read((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&shortCount, sizeof(shortCount));
	file.write((char*)&shortCount, sizeof(shortCount));
	inFile2.read((char*)&shortCount, sizeof(shortCount));
	inFile3.read((char*)&shortCount, sizeof(shortCount));

	inFile.read((char*)&shortCount, sizeof(shortCount));
	file.write((char*)&shortCount, sizeof(shortCount));
	inFile2.read((char*)&shortCount, sizeof(shortCount));
	inFile3.read((char*)&shortCount, sizeof(shortCount));

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));
	inFile3.read((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&shortCount, sizeof(shortCount));
	file.write((char*)&shortCount, sizeof(shortCount));
	inFile2.read((char*)&shortCount, sizeof(shortCount));
	inFile3.read((char*)&shortCount, sizeof(shortCount));

	inFile.read((char*)&shortCount, sizeof(shortCount));
	file.write((char*)&shortCount, sizeof(shortCount));
	inFile2.read((char*)&shortCount, sizeof(shortCount));
	inFile3.read((char*)&shortCount, sizeof(shortCount));


	inFile.read((char*)&width, sizeof(width));
	file.write((char*)&width, sizeof(width));
	inFile2.read((char*)&shortCount, sizeof(shortCount));
	inFile3.read((char*)&shortCount, sizeof(shortCount));

	inFile.read((char*)&height, sizeof(height));
	file.write((char*)&height, sizeof(height));
	inFile2.read((char*)&shortCount, sizeof(shortCount));
	inFile3.read((char*)&shortCount, sizeof(shortCount));


	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));
	inFile3.read((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));
	inFile3.read((char*)&charCount, sizeof(charCount));


	cout << width << endl;
	cout << height << endl;


	unsigned char pix;
	unsigned char pix2;
	unsigned char pix3;
	unsigned char pix4;
	unsigned int counter = 0;

	int pixl;
	int pixl2;
	int pixl4;
	int pix6;

	for (unsigned int i = 0; i < (unsigned int)width * height; i++)
	{
		//pixels.push_back(vector<unsigned char>());
		//pixels2.push_back(vector<unsigned char>());

		inFile.read((char*)&pix, sizeof(pix));
		inFile2.read((char*)&pix2, sizeof(pix2));
		inFile3.read((char*)&pix3, sizeof(pix3));
		pixl = pix;
		pixl2 = pix2;
		pixl4 = (((pixl * pixl2) / 255.0) + 0.5f) - pix3;
		if (pixl4 < 0) { pixl4 = 0; };
		if (pixl4 > 255) { pixl4 = 255; };
		pix4 = pixl4;
		file.write((char*)&pix4, sizeof(pix));
		//pixels[i].push_back(pix);
		//pixels2[i].push_back(pix);
		inFile.read((char*)&pix, sizeof(pix));
		inFile2.read((char*)&pix2, sizeof(pix2));
		inFile3.read((char*)&pix3, sizeof(pix3));
		pixl = pix;
		pixl2 = pix2;
		pixl4 = (((pixl * pixl2) / 255.0) + 0.5f) - pix3;
		if (pixl4 < 0) { pixl4 = 0; };
		if (pixl4 > 255) { pixl4 = 255; };
		pix4 = pixl4;
		file.write((char*)&pix4, sizeof(pix));
		//pixels[i].push_back(pix);
		//pixels2[i].push_back(pix);
		inFile.read((char*)&pix, sizeof(pix));
		inFile2.read((char*)&pix2, sizeof(pix2));
		inFile3.read((char*)&pix3, sizeof(pix3));
		pixl = pix;
		pixl2 = pix2;
		pixl4 = (((pixl * pixl2) / 255.0) + 0.5f) - pix3;
		if (pixl4 < 0) { pixl4 = 0; };
		if (pixl4 > 255) { pixl4 = 255; };
		pix4 = pixl4;
		file.write((char*)&pix4, sizeof(pix));
		//pixels[i].push_back(pix);
		//pixels2[i].push_back(pix);
		counter++;
	}

	file.close();
}


void part5()
{
	unsigned short width;
	unsigned short height;
	//vector<vector<unsigned char>> pixels;
	//vector<vector<unsigned char>> pixels2;

	ifstream inFile("C:/Users/Stefan/Desktop/ImageProcessing/input/layer1.tga", ios_base::binary);
	ifstream inFile2("C:/Users/Stefan/Desktop/ImageProcessing/input/pattern1.tga", ios_base::binary);
	ifstream inFile3("C:/Users/Stefan/Desktop/ImageProcessing/examples/EXAMPLE_part1.tga", ios_base::binary);
	ofstream file("part5.tga", ios_base::binary);

	unsigned char charCount;
	unsigned short shortCount;

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&shortCount, sizeof(shortCount));
	file.write((char*)&shortCount, sizeof(shortCount));
	inFile2.read((char*)&shortCount, sizeof(shortCount));

	inFile.read((char*)&shortCount, sizeof(shortCount));
	file.write((char*)&shortCount, sizeof(shortCount));
	inFile2.read((char*)&shortCount, sizeof(shortCount));

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));


	inFile.read((char*)&shortCount, sizeof(shortCount));
	file.write((char*)&shortCount, sizeof(shortCount));
	inFile2.read((char*)&shortCount, sizeof(shortCount));

	inFile.read((char*)&shortCount, sizeof(shortCount));
	file.write((char*)&shortCount, sizeof(shortCount));
	inFile2.read((char*)&shortCount, sizeof(shortCount));


	inFile.read((char*)&width, sizeof(width));
	file.write((char*)&width, sizeof(width));
	inFile2.read((char*)&width, sizeof(width));

	inFile.read((char*)&height, sizeof(height));
	file.write((char*)&height, sizeof(height));
	inFile2.read((char*)&height, sizeof(height));


	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));


	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));


	cout << width << endl;
	cout << height << endl;


	unsigned char pix;
	unsigned char pix2;
	unsigned char pix3;
	int pixl3;
	unsigned int counter = 0;

	for (unsigned int i = 0; i < (unsigned int)width * height; i++)
	{
		//pixels.push_back(vector<unsigned char>());
		//pixels2.push_back(vector<unsigned char>());

		inFile.read((char*)&pix, sizeof(pix));
		inFile2.read((char*)&pix2, sizeof(pix2));
		if ((pix2 / 255.0) <= 0.5) { pixl3 = (2*pix * pix2 / 255.0) + 0.5f; }
		else { pixl3 = (1 - 2*(1 - pix / 255.0) * (1 - pix2 / 255.0)) * 255.0 + 0.5f; }
		if (pixl3 < 0) { pixl3 = 0; };
		if (pixl3 > 255) { pixl3 = 255; };
		pix3 = pixl3;
		file.write((char*)&pix3, sizeof(pix));
		//pixels[i].push_back(pix);
		//pixels2[i].push_back(pix);
		inFile.read((char*)&pix, sizeof(pix));
		inFile2.read((char*)&pix2, sizeof(pix2));
		if ((pix2 / 255.0) <= 0.5) { pixl3 = (2 * pix * pix2 / 255.0) + 0.5f; }
		else { pixl3 = (1 - 2 * (1 - pix / 255.0) * (1 - pix2 / 255.0)) * 255.0 + 0.5f; }
		if (pixl3 < 0) { pixl3 = 0; };
		if (pixl3 > 255) { pixl3 = 255; };
		pix3 = pixl3;
		file.write((char*)&pix3, sizeof(pix));
		//pixels[i].push_back(pix);
		//pixels2[i].push_back(pix);
		inFile.read((char*)&pix, sizeof(pix));
		inFile2.read((char*)&pix2, sizeof(pix2));
		if ((pix2 / 255.0) <= 0.5) { pixl3 = (2 * pix * pix2 / 255.0) + 0.5f; }
		else { pixl3 = (1 - 2 * (1 - pix / 255.0) * (1 - pix2 / 255.0)) * 255.0 + 0.5f; }
		if (pixl3 < 0) { pixl3 = 0; };
		if (pixl3 > 255) { pixl3 = 255; };
		pix3 = pixl3;
		file.write((char*)&pix3, sizeof(pix));
		//pixels[i].push_back(pix);
		//pixels2[i].push_back(pix);
		counter++;
	}

	file.close();
}


void part6()
{
	unsigned short width;
	unsigned short height;
	//vector<vector<unsigned char>> pixels;
	//vector<vector<unsigned char>> pixels2;

	ifstream inFile("C:/Users/Stefan/Desktop/ImageProcessing/input/car.tga", ios_base::binary);
	ofstream file("part6.tga", ios_base::binary);

	unsigned char charCount;
	unsigned short shortCount;

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&shortCount, sizeof(shortCount));
	file.write((char*)&shortCount, sizeof(shortCount));

	inFile.read((char*)&shortCount, sizeof(shortCount));
	file.write((char*)&shortCount, sizeof(shortCount));

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));


	inFile.read((char*)&shortCount, sizeof(shortCount));
	file.write((char*)&shortCount, sizeof(shortCount));

	inFile.read((char*)&shortCount, sizeof(shortCount));
	file.write((char*)&shortCount, sizeof(shortCount));


	inFile.read((char*)&width, sizeof(width));
	file.write((char*)&width, sizeof(width));

	inFile.read((char*)&height, sizeof(height));
	file.write((char*)&height, sizeof(height));


	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));


	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));


	cout << width << endl;
	cout << height << endl;


	unsigned char pix;
	unsigned char pix2;
	unsigned char pix3;
	unsigned int pixl3;
	unsigned int counter = 0;

	for (unsigned int i = 0; i < (unsigned int)width * height; i++)
	{
		//pixels.push_back(vector<unsigned char>());
		//pixels2.push_back(vector<unsigned char>());

		inFile.read((char*)&pix, sizeof(pix));
		file.write((char*)&pix, sizeof(pix));
		//pixels[i].push_back(pix);
		//pixels2[i].push_back(pix);
		inFile.read((char*)&pix, sizeof(pix));
		pixl3 = (pix + 200);
		if (pixl3 > 255) { pixl3 = 255; }
		pix3 = pixl3;
		file.write((char*)&pix3, sizeof(pix3));
		//pixels[i].push_back(pix);
		//pixels2[i].push_back(pix);
		inFile.read((char*)&pix, sizeof(pix));
		file.write((char*)&pix, sizeof(pix));
		//pixels[i].push_back(pix);
		//pixels2[i].push_back(pix);
		counter++;
	}

	file.close();
}


void part7()
{
	unsigned short width;
	unsigned short height;
	//vector<vector<unsigned char>> pixels;
	//vector<vector<unsigned char>> pixels2;

	ifstream inFile("C:/Users/Stefan/Desktop/ImageProcessing/input/car.tga", ios_base::binary);
	ofstream file("part7.tga", ios_base::binary);

	unsigned char charCount;
	unsigned short shortCount;

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&shortCount, sizeof(shortCount));
	file.write((char*)&shortCount, sizeof(shortCount));

	inFile.read((char*)&shortCount, sizeof(shortCount));
	file.write((char*)&shortCount, sizeof(shortCount));

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));


	inFile.read((char*)&shortCount, sizeof(shortCount));
	file.write((char*)&shortCount, sizeof(shortCount));

	inFile.read((char*)&shortCount, sizeof(shortCount));
	file.write((char*)&shortCount, sizeof(shortCount));


	inFile.read((char*)&width, sizeof(width));
	file.write((char*)&width, sizeof(width));

	inFile.read((char*)&height, sizeof(height));
	file.write((char*)&height, sizeof(height));


	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));


	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));


	cout << width << endl;
	cout << height << endl;


	unsigned char pix;
	unsigned char pix2;
	unsigned char pix3;
	int pixl3;
	unsigned int counter = 0;

	for (unsigned int i = 0; i < (unsigned int)width * height; i++)
	{
		//pixels.push_back(vector<unsigned char>());
		//pixels2.push_back(vector<unsigned char>());

		inFile.read((char*)&pix, sizeof(pix));
		pix3 = 0;
		file.write((char*)&pix3, sizeof(pix));
		//pixels[i].push_back(pix);
		//pixels2[i].push_back(pix);
		inFile.read((char*)&pix, sizeof(pix));
		file.write((char*)&pix, sizeof(pix3));
		//pixels[i].push_back(pix);
		//pixels2[i].push_back(pix);
		inFile.read((char*)&pix, sizeof(pix));
		pixl3 = pix * 4;
		if (pixl3 > 255) { pixl3 = 255; }
		pix3 = pixl3;
		file.write((char*)&pix3, sizeof(pix));
		//pixels[i].push_back(pix);
		//pixels2[i].push_back(pix);
		counter++;
	}

	file.close();
}


void part8()
{
	unsigned short width;
	unsigned short height;
	//vector<vector<unsigned char>> pixels;
	//vector<vector<unsigned char>> pixels2;

	ifstream inFile("C:/Users/Stefan/Desktop/ImageProcessing/input/car.tga", ios_base::binary);
	ofstream filer("part8_r.tga", ios_base::binary);
	ofstream fileg("part8_g.tga", ios_base::binary);
	ofstream fileb("part8_b.tga", ios_base::binary);


	unsigned char charCount;
	unsigned short shortCount;

	inFile.read((char*)&charCount, sizeof(charCount));
	filer.write((char*)&charCount, sizeof(charCount));
	fileg.write((char*)&charCount, sizeof(charCount));
	fileb.write((char*)&charCount, sizeof(charCount));


	inFile.read((char*)&charCount, sizeof(charCount));
	filer.write((char*)&charCount, sizeof(charCount));
	fileg.write((char*)&charCount, sizeof(charCount));
	fileb.write((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&charCount, sizeof(charCount));
	filer.write((char*)&charCount, sizeof(charCount));
	fileg.write((char*)&charCount, sizeof(charCount));
	fileb.write((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&shortCount, sizeof(shortCount));
	filer.write((char*)&shortCount, sizeof(shortCount));
	fileg.write((char*)&shortCount, sizeof(shortCount));
	fileb.write((char*)&shortCount, sizeof(shortCount));

	inFile.read((char*)&shortCount, sizeof(shortCount));
	filer.write((char*)&shortCount, sizeof(shortCount));
	fileg.write((char*)&shortCount, sizeof(shortCount));
	fileb.write((char*)&shortCount, sizeof(shortCount));

	inFile.read((char*)&charCount, sizeof(charCount));
	filer.write((char*)&charCount, sizeof(charCount));
	fileg.write((char*)&charCount, sizeof(charCount));
	fileb.write((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&shortCount, sizeof(shortCount));
	filer.write((char*)&shortCount, sizeof(shortCount));
	fileg.write((char*)&shortCount, sizeof(shortCount));
	fileb.write((char*)&shortCount, sizeof(shortCount));

	inFile.read((char*)&shortCount, sizeof(shortCount));
	filer.write((char*)&shortCount, sizeof(shortCount));
	fileg.write((char*)&shortCount, sizeof(shortCount));
	fileb.write((char*)&shortCount, sizeof(shortCount));


	inFile.read((char*)&width, sizeof(width));
	filer.write((char*)&width, sizeof(width));
	fileg.write((char*)&width, sizeof(width));
	fileb.write((char*)&width, sizeof(width));

	inFile.read((char*)&height, sizeof(height));
	filer.write((char*)&height, sizeof(height));
	fileg.write((char*)&height, sizeof(height));
	fileb.write((char*)&height, sizeof(height));


	inFile.read((char*)&charCount, sizeof(charCount));
	filer.write((char*)&charCount, sizeof(charCount));
	fileg.write((char*)&charCount, sizeof(charCount));
	fileb.write((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&charCount, sizeof(charCount));
	filer.write((char*)&charCount, sizeof(charCount));
	fileg.write((char*)&charCount, sizeof(charCount));
	fileb.write((char*)&charCount, sizeof(charCount));

	cout << width << endl;
	cout << height << endl;


	unsigned char pix;
	unsigned char pix2;
	unsigned char pix3;
	int pixl3;
	unsigned int counter = 0;

	for (unsigned int i = 0; i < (unsigned int)width * height; i++)
	{
		//pixels.push_back(vector<unsigned char>());
		//pixels2.push_back(vector<unsigned char>());

		inFile.read((char*)&pix, sizeof(pix));
		fileb.write((char*)&pix, sizeof(pix));
		fileb.write((char*)&pix, sizeof(pix));
		fileb.write((char*)&pix, sizeof(pix));
		//pixels[i].push_back(pix);
		//pixels2[i].push_back(pix);
		inFile.read((char*)&pix, sizeof(pix));
		fileg.write((char*)&pix, sizeof(pix));
		fileg.write((char*)&pix, sizeof(pix));
		fileg.write((char*)&pix, sizeof(pix));
		//pixels[i].push_back(pix);
		//pixels2[i].push_back(pix);
		inFile.read((char*)&pix, sizeof(pix));
		filer.write((char*)&pix, sizeof(pix));
		filer.write((char*)&pix, sizeof(pix));
		filer.write((char*)&pix, sizeof(pix));
		//pixels[i].push_back(pix);
		//pixels2[i].push_back(pix);
		counter++;
	}

	filer.close();
	fileg.close();
	fileb.close();
}


void part9()
{
	unsigned short width;
	unsigned short height;
	//vector<vector<unsigned char>> pixels;
	//vector<vector<unsigned char>> pixels2;

	ifstream inFile("C:/Users/Stefan/Desktop/ImageProcessing/input/layer_red.tga", ios_base::binary);
	ifstream inFile2("C:/Users/Stefan/Desktop/ImageProcessing/input/layer_green.tga", ios_base::binary);
	ifstream inFile3("C:/Users/Stefan/Desktop/ImageProcessing/input/layer_blue.tga", ios_base::binary);

	ofstream file("part9.tga", ios_base::binary);

	unsigned char charCount;
	unsigned short shortCount;

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));
	inFile3.read((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));
	inFile3.read((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));
	inFile3.read((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&shortCount, sizeof(shortCount));
	file.write((char*)&shortCount, sizeof(shortCount));
	inFile2.read((char*)&shortCount, sizeof(shortCount));
	inFile3.read((char*)&shortCount, sizeof(shortCount));

	inFile.read((char*)&shortCount, sizeof(shortCount));
	file.write((char*)&shortCount, sizeof(shortCount));
	inFile2.read((char*)&shortCount, sizeof(shortCount));
	inFile3.read((char*)&shortCount, sizeof(shortCount));

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));
	inFile3.read((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&shortCount, sizeof(shortCount));
	file.write((char*)&shortCount, sizeof(shortCount));
	inFile2.read((char*)&shortCount, sizeof(shortCount));
	inFile3.read((char*)&shortCount, sizeof(shortCount));

	inFile.read((char*)&shortCount, sizeof(shortCount));
	file.write((char*)&shortCount, sizeof(shortCount));
	inFile2.read((char*)&shortCount, sizeof(shortCount));
	inFile3.read((char*)&shortCount, sizeof(shortCount));


	inFile.read((char*)&width, sizeof(width));
	file.write((char*)&width, sizeof(width));
	inFile2.read((char*)&shortCount, sizeof(shortCount));
	inFile3.read((char*)&shortCount, sizeof(shortCount));

	inFile.read((char*)&height, sizeof(height));
	file.write((char*)&height, sizeof(height));
	inFile2.read((char*)&shortCount, sizeof(shortCount));
	inFile3.read((char*)&shortCount, sizeof(shortCount));


	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));
	inFile3.read((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));
	inFile3.read((char*)&charCount, sizeof(charCount));


	cout << width << endl;
	cout << height << endl;


	unsigned char pix;
	unsigned char pix2;
	unsigned char pix3;
	unsigned char pix4;

	int pixl;
	int pixl2;
	int pixl4;
	int pix6;

	for (unsigned int i = 0; i < (unsigned int)width * height; i++)
	{
		//pixels.push_back(vector<unsigned char>());
		//pixels2.push_back(vector<unsigned char>());

		inFile3.read((char*)&pix3, sizeof(pix3));
		inFile3.read((char*)&pix3, sizeof(pix3));
		inFile3.read((char*)&pix3, sizeof(pix3));
		file.write((char*)&pix3, sizeof(pix3));
		//pixels[i].push_back(pix);
		//pixels2[i].push_back(pix);
		inFile2.read((char*)&pix3, sizeof(pix3));
		inFile2.read((char*)&pix3, sizeof(pix3));
		inFile2.read((char*)&pix3, sizeof(pix3));
		file.write((char*)&pix3, sizeof(pix3));
		//pixels[i].push_back(pix);
		//pixels2[i].push_back(pix);
		inFile.read((char*)&pix3, sizeof(pix3));
		inFile.read((char*)&pix3, sizeof(pix3));
		inFile.read((char*)&pix3, sizeof(pix3));
		file.write((char*)&pix3, sizeof(pix3));
		//pixels[i].push_back(pix);
		//pixels2[i].push_back(pix);
	}

	file.close();
}


void part10()
{
	unsigned short width;
	unsigned short height;
	vector<vector<unsigned char>> pixels;

	ifstream inFile("C:/Users/Stefan/Desktop/ImageProcessing/input/text2.tga", ios_base::binary);
	ofstream file("part10.tga", ios_base::binary);

	unsigned char charCount;
	unsigned short shortCount;

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&shortCount, sizeof(shortCount));
	file.write((char*)&shortCount, sizeof(shortCount));

	inFile.read((char*)&shortCount, sizeof(shortCount));
	file.write((char*)&shortCount, sizeof(shortCount));

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));


	inFile.read((char*)&shortCount, sizeof(shortCount));
	file.write((char*)&shortCount, sizeof(shortCount));

	inFile.read((char*)&shortCount, sizeof(shortCount));
	file.write((char*)&shortCount, sizeof(shortCount));


	inFile.read((char*)&width, sizeof(width));
	file.write((char*)&width, sizeof(width));

	inFile.read((char*)&height, sizeof(height));
	file.write((char*)&height, sizeof(height));


	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));


	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));


	cout << width << endl;
	cout << height << endl;


	unsigned char pix;
	unsigned char pix2;
	unsigned char pix3;
	int pixl3;

	for (unsigned int i = 0; i < (unsigned int)width * height; i++)
	{
		pixels.push_back(vector<unsigned char>());

		inFile.read((char*)&pix, sizeof(pix));
		pixels[i].push_back(pix);

		inFile.read((char*)&pix, sizeof(pix));
		pixels[i].push_back(pix);

		inFile.read((char*)&pix, sizeof(pix));
		pixels[i].push_back(pix);
	}

	for (unsigned int i = 0; i < (unsigned int)width * height; i++)
	{
		pix3 = pixels[pixels.size() - 1 - i][0];
		file.write((char*)&pix3, sizeof(pix3));

		pix3 = pixels[pixels.size() - 1 - i][1];
		file.write((char*)&pix3, sizeof(pix3));

		pix3 = pixels[pixels.size() - 1 - i][2];
		file.write((char*)&pix3, sizeof(pix3));
	}



	file.close();
}


void extracredit()
{
	unsigned short width;
	unsigned short height;
	vector<vector<unsigned char>> pixels;

	ifstream inFile("C:/Users/Stefan/Desktop/ImageProcessing/input/car.tga", ios_base::binary);
	ifstream inFile2("C:/Users/Stefan/Desktop/ImageProcessing/input/circles.tga", ios_base::binary);
	ifstream inFile3("C:/Users/Stefan/Desktop/ImageProcessing/input/pattern1.tga", ios_base::binary);
	ifstream inFile4("C:/Users/Stefan/Desktop/ImageProcessing/input/text.tga", ios_base::binary);


	ofstream file("extracredit.tga", ios_base::binary);

	unsigned char charCount;
	unsigned short shortCount;

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));
	inFile3.read((char*)&charCount, sizeof(charCount));
	inFile4.read((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));
	inFile3.read((char*)&charCount, sizeof(charCount));
	inFile4.read((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));
	inFile3.read((char*)&charCount, sizeof(charCount));
	inFile4.read((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&shortCount, sizeof(shortCount));
	file.write((char*)&shortCount, sizeof(shortCount));
	inFile2.read((char*)&shortCount, sizeof(shortCount));
	inFile3.read((char*)&shortCount, sizeof(shortCount));
	inFile4.read((char*)&shortCount, sizeof(shortCount));

	inFile.read((char*)&shortCount, sizeof(shortCount));
	file.write((char*)&shortCount, sizeof(shortCount));
	inFile2.read((char*)&shortCount, sizeof(shortCount));
	inFile3.read((char*)&shortCount, sizeof(shortCount));
	inFile4.read((char*)&shortCount, sizeof(shortCount));

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));
	inFile3.read((char*)&charCount, sizeof(charCount));
	inFile4.read((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&shortCount, sizeof(shortCount));
	file.write((char*)&shortCount, sizeof(shortCount));
	inFile2.read((char*)&shortCount, sizeof(shortCount));
	inFile3.read((char*)&shortCount, sizeof(shortCount));
	inFile4.read((char*)&shortCount, sizeof(shortCount));

	inFile.read((char*)&shortCount, sizeof(shortCount));
	file.write((char*)&shortCount, sizeof(shortCount));
	inFile2.read((char*)&shortCount, sizeof(shortCount));
	inFile3.read((char*)&shortCount, sizeof(shortCount));
	inFile4.read((char*)&shortCount, sizeof(shortCount));


	inFile.read((char*)&width, sizeof(width));
	width *= 2;
	file.write((char*)&width, sizeof(width));
	inFile2.read((char*)&shortCount, sizeof(shortCount));
	inFile3.read((char*)&shortCount, sizeof(shortCount));
	inFile4.read((char*)&shortCount, sizeof(shortCount));

	inFile.read((char*)&height, sizeof(height));
	height *= 2;
	file.write((char*)&height, sizeof(height));
	inFile2.read((char*)&shortCount, sizeof(shortCount));
	inFile3.read((char*)&shortCount, sizeof(shortCount));
	inFile4.read((char*)&shortCount, sizeof(shortCount));


	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));
	inFile3.read((char*)&charCount, sizeof(charCount));
	inFile4.read((char*)&charCount, sizeof(charCount));

	inFile.read((char*)&charCount, sizeof(charCount));
	file.write((char*)&charCount, sizeof(charCount));
	inFile2.read((char*)&charCount, sizeof(charCount));
	inFile3.read((char*)&charCount, sizeof(charCount));
	inFile4.read((char*)&charCount, sizeof(charCount));


	cout << width << endl;
	cout << height << endl;


	unsigned char pix;
	unsigned char pix2;
	unsigned char pix3;
	int pixl3;

	for (unsigned int j = 0; j < (unsigned int)height / 2; j++)
	{
		for (unsigned int i = 0; i < (unsigned int)width / 2; i++)
		{
			//pixels.push_back(vector<unsigned char>());
			inFile4.read((char*)&pix, sizeof(pix));
			file.write((char*)&pix, sizeof(pix));
			//pixels[i].push_back(pix);
			inFile4.read((char*)&pix, sizeof(pix));
			file.write((char*)&pix, sizeof(pix));			
			//pixels[i].push_back(pix);
			inFile4.read((char*)&pix, sizeof(pix));
			file.write((char*)&pix, sizeof(pix));
			//pixels[i].push_back(pix);
		}
		for (unsigned int i = 0; i < (unsigned int)width / 2; i++)
		{
			//pixels.push_back(vector<unsigned char>());
			inFile3.read((char*)&pix, sizeof(pix));
			file.write((char*)&pix, sizeof(pix));
			//pixels[i].push_back(pix);
			inFile3.read((char*)&pix, sizeof(pix));
			file.write((char*)&pix, sizeof(pix));
			//pixels[i].push_back(pix);
			inFile3.read((char*)&pix, sizeof(pix));
			file.write((char*)&pix, sizeof(pix));
			//pixels[i].push_back(pix);
		}
	}

	for (unsigned int j = 0; j < (unsigned int)height / 2; j++)
	{
		for (unsigned int i = 0; i < (unsigned int)width / 2; i++)
		{
			//pixels.push_back(vector<unsigned char>());
			inFile.read((char*)&pix, sizeof(pix));
			file.write((char*)&pix, sizeof(pix));
			//pixels[i].push_back(pix);
			inFile.read((char*)&pix, sizeof(pix));
			file.write((char*)&pix, sizeof(pix));
			//pixels[i].push_back(pix);
			inFile.read((char*)&pix, sizeof(pix));
			file.write((char*)&pix, sizeof(pix));
			//pixels[i].push_back(pix);
		}
		for (unsigned int i = 0; i < (unsigned int)width / 2; i++)
		{
			//pixels.push_back(vector<unsigned char>());
			inFile2.read((char*)&pix, sizeof(pix));
			file.write((char*)&pix, sizeof(pix));
			//pixels[i].push_back(pix);
			inFile2.read((char*)&pix, sizeof(pix));
			file.write((char*)&pix, sizeof(pix));
			//pixels[i].push_back(pix);
			inFile2.read((char*)&pix, sizeof(pix));
			file.write((char*)&pix, sizeof(pix));
			//pixels[i].push_back(pix);
		}
	}
	

	file.close();
}



int main()
{
	//part1();
	extracredit();
	test();

	return 0;
}

