#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "TextureManager.h"

Tile::Tile()
{
	hiddenTile.setTexture(TextureManager::GetTexture("tile_hidden"));
	revTile.setTexture(TextureManager::GetTexture("tile_revealed"));
	flag.setTexture(TextureManager::GetTexture("flag"));

	hidden = true;
	flagged = false;
	hasBomb = false;
}

void Tile::SetPosition(float xPos, float yPos)
{
	hiddenTile.setPosition(xPos, yPos);
	revTile.setPosition(xPos, yPos);
	flag.setPosition(xPos, yPos);
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
		window.draw(revTile);
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