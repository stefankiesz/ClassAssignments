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
	sf::Sprite numAdjBombs;


	bool hidden;
	bool flagged;
	bool hasBomb;
	int adjBombs;
	bool debugOn;
	bool adjChecked;
	bool lostGame;

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
	void ToggleDebug();
	bool GetHidden();
	bool GetAdjChecked();
	void SetAdjCheckedTrue();
	bool GetHasFlag();
	void LostGame();

};

