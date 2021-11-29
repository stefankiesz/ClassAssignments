#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <ctime>
#include <unordered_map>

#include "TextureManager.h"
#include "Tile.h"

using namespace std;

int main()
{
    int columns = 22;
    int rows = 16;
    
    sf::RenderWindow window(sf::VideoMode(columns * 32, rows*32 + 88), "Mine Sweeper");

    Tile myTile;
    myTile.SetPosition(100, 200);
    vector<Tile> tiles;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            myTile.SetPosition(32 * j, 32 * i);
            tiles.push_back(myTile);
        }
        
    }


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
       
        for (int i = 0; i < tiles.size(); i++)
        {
            tiles[i].Draw(window);
        }
        window.display();
    }

    //TextureManager::Clear();

    return 0;
}

