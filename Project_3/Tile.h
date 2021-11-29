#pragma once
#include <SFML/Graphics.hpp>

class Tile
{

	sf::Sprite sprite;
	sf::Texture texture;

	bool hidden;

public:
	Tile();
	void SetPosition(float xPos, float yPos);
	void Draw(sf::RenderWindow& window);
};

