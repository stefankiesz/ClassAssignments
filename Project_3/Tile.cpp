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
	/*for (int i = 0; i < 8; i++)
	{
		sf::Sprite tempSprite;
		nums.push_back(tempSprite);
		nums[i].setTexture(TextureManager::GetTexture("number_" + to_string(i+1)));
	}*/
	/*num1.setTexture(TextureManager::GetTexture("number_1"));
	num2.setTexture(TextureManager::GetTexture("number_2"));
	num3.setTexture(TextureManager::GetTexture("number_3"));
	num4.setTexture(TextureManager::GetTexture("number_4"));
	num5.setTexture(TextureManager::GetTexture("number_5"));
	num6.setTexture(TextureManager::GetTexture("number_6"));
	num7.setTexture(TextureManager::GetTexture("number_7"));
	num8.setTexture(TextureManager::GetTexture("number_8"));*/



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

	numAdjBombs.setPosition(xPos, yPos);


	/*for (int i = 0; i < 8; i ++)
		nums[i].setPosition(xPos, yPos);*/

	/*num1.setPosition(xPos,yPos);
	num2.setPosition(xPos,yPos);
	num3.setPosition(xPos,yPos);
	num4.setPosition(xPos,yPos);
	num5.setPosition(xPos,yPos);
	num6.setPosition(xPos,yPos);
	num7.setPosition(xPos,yPos);
	num8.setPosition(xPos,yPos);*/
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