#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "TextureManager.h"

Tile::Tile()
{
	hiddenTile.setTexture(TextureManager::GetTexture("tile_hidden"));
	revTile.setTexture(TextureManager::GetTexture("tile_revealed"));
	flag.setTexture(TextureManager::GetTexture("flag"));
	bomb.setTexture(TextureManager::GetTexture("mine"));

	hidden = true;
	flagged = false;
	hasBomb = false;
	adjBombs = 0;
}

void Tile::SetPosition(float xPos, float yPos)
{
	hiddenTile.setPosition(xPos, yPos);
	revTile.setPosition(xPos, yPos);
	flag.setPosition(xPos, yPos);
	bomb.setPosition(xPos, yPos);
}

void Tile::Draw(sf::RenderWindow& window)
{
	if (hidden)
	{
		window.draw(hiddenTile);
		if (flagged)
			window.draw(flag);
	}
	else
	{
		window.draw(revTile);
		if (hasBomb)
			window.draw(bomb);
	}		
}

sf::FloatRect Tile::GetBounds()
{
	return hiddenTile.getGlobalBounds();
}

void Tile::RevealTile()
{
	if (!flagged)
		hidden = false;
}

void Tile::ToggleFlag()
{
	if (hidden)
		flagged = !flagged;
}

void Tile::PlaceBomb()
{
	hasBomb = true;
}

bool Tile::getHasBomb()
{
	return hasBomb;
}

void Tile::addAdjBomb()
{
	adjBombs++;
}

int Tile::getAdjBombs()
{
	return adjBombs;
}