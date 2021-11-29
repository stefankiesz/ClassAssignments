#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "Tile.h"
#include "TextureManager.h"

using namespace std;


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
	debugOn = false;
}

void Tile::SetPosition(float xPos, float yPos)
{
	hiddenTile.setPosition(xPos, yPos);
	revTile.setPosition(xPos, yPos);
	flag.setPosition(xPos, yPos);
	bomb.setPosition(xPos, yPos);

	numAdjBombs.setPosition(xPos, yPos);

}

void Tile::Draw(sf::RenderWindow& window)
{
	if (hidden)
	{
		window.draw(hiddenTile);
		if (flagged)
			window.draw(flag);
		else
			if (debugOn && hasBomb)
				window.draw(bomb);
	}
	else
	{
		window.draw(revTile);
		if (hasBomb)
			window.draw(bomb);
		else
		{
			if (adjBombs > 0 && adjBombs < 9)
			{
				window.draw(numAdjBombs);
			}
		}
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

void Tile::setNum()
{
	if (adjBombs > 0)
	{
		numAdjBombs.setTexture(TextureManager::GetTexture("number_" + to_string(adjBombs)));

	}
}

void Tile::ToggleDebug()
{
	debugOn = !debugOn;
}