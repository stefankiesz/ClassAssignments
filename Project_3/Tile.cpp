#include "Tile.h"
#include <SFML/Graphics.hpp>

Tile::Tile()
{
	texture.loadFromFile("images/tile_hidden.png");
	hidden = true;
	sprite.setTexture(texture);
}

void Tile::SetPosition(float xPos, float yPos)
{
	sprite.setPosition(xPos, yPos);
}

void Tile::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}