#pragma once
#include <SFML/Graphics.hpp>

class Tile
{

	sf::Sprite hiddenTile;
	sf::Sprite revTile;
	sf::Sprite flag;


	bool hidden;
	bool flagged;
	bool hasBomb;

public:
	Tile();
	void SetPosition(float xPos, float yPos);
	void Draw(sf::RenderWindow& window);
	sf::FloatRect GetBounds();
	void RevealTile();
	void ToggleFlag();

};

