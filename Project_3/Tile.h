#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
using namespace std;


class Tile
{

	sf::Sprite hiddenTile;
	sf::Sprite revTile;
	sf::Sprite flag;
	sf::Sprite bomb;
	//vector<sf::Sprite> nums;
	/*sf::Sprite num1;
	sf::Sprite num2;
	sf::Sprite num3;
	sf::Sprite num4;
	sf::Sprite num5;
	sf::Sprite num6;
	sf::Sprite num7;
	sf::Sprite num8;*/
	sf::Sprite numAdjBombs;


	bool hidden;
	bool flagged;
	bool hasBomb;
	int adjBombs;

public:
	Tile();
	void SetPosition(float xPos, float yPos);
	void Draw(sf::RenderWindow& window);
	sf::FloatRect GetBounds();
	void RevealTile();
	void ToggleFlag();
	void PlaceBomb();
	bool getHasBomb();
	void addAdjBomb();
	int getAdjBombs();
	void setNum();
};

