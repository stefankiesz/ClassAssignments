#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <ctime>
#include <unordered_map>

#include "TextureManager.h"
#include "Tile.h"
#include "Random.h"

using namespace std;

int main()
{
    int columns = 22;
    int rows = 16;
    int bombs = 50;


    
    sf::RenderWindow window(sf::VideoMode(columns * 32, rows*32 + 88), "Minesweeper");

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

    vector<int> bombIndexes;
    for (int i = 0; i < bombs; i++)
    {
        int num = Random::Int(0, tiles.size() - 1);
        tiles[num].PlaceBomb();
    }

    for (int i = 0; i < tiles.size(); i++)
    {
        if(i - columns >= 0 && tiles[i - columns].getHasBomb())
            tiles[i].addAdjBomb();
        if (i - columns + 1 >= 0 && (i - columns + 1) % columns != 0 && tiles[i - columns + 1].getHasBomb())
            tiles[i].addAdjBomb();
        if (i - columns - 1 >= 0 && (i - columns) % columns != 0 && tiles[i - columns - 1].getHasBomb())
            tiles[i].addAdjBomb();
        if (i + columns < tiles.size() && tiles[i + columns].getHasBomb())
            tiles[i].addAdjBomb();
        if (i + columns + 1 < tiles.size() && (i + columns + 1) % columns != 0 && tiles[i + columns + 1].getHasBomb())
            tiles[i].addAdjBomb();
        if (i + columns - 1 < tiles.size() && (i - columns) % columns != 0 && tiles[i + columns - 1].getHasBomb())
            tiles[i].addAdjBomb();
        if (i - 1 >= 0 && (i) % columns != 0 && tiles[i-1].getHasBomb())
            tiles[i].addAdjBomb();
        if (i + 1 < tiles.size() && (i+1) % columns != 0 && tiles[i + 1].getHasBomb())
            tiles[i].addAdjBomb();
        tiles[i].setNum();
    }
    

    sf::Sprite smiley;
    smiley.setTexture(TextureManager::GetTexture("face_happy"));
    smiley.setPosition(window.getSize().x/2 - 32, window.getSize().y - 88);

    sf::Sprite debug;
    debug.setTexture(TextureManager::GetTexture("debug"));
    debug.setPosition(window.getSize().x / 2 - 32 + 64 *2, window.getSize().y - 88);

    sf::Sprite test1;
    test1.setTexture(TextureManager::GetTexture("test_1"));
    test1.setPosition(window.getSize().x / 2 - 32 + 64 * 3, window.getSize().y - 88);

    sf::Sprite test2;
    test2.setTexture(TextureManager::GetTexture("test_2"));
    test2.setPosition(window.getSize().x / 2 - 32 + 64 * 4, window.getSize().y - 88);

    sf::Sprite test3;
    test3.setTexture(TextureManager::GetTexture("test_3"));
    test3.setPosition(window.getSize().x / 2 - 32 + 64 * 5, window.getSize().y - 88);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2f mousePosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                    for (unsigned int i = 0; i < tiles.size(); i++)
                    {
                        if (tiles[i].GetBounds().contains(mousePosition))
                        {
                            tiles[i].RevealTile();
                        }
                            

                    }
                }

                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    sf::Vector2f mousePosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                    for (unsigned int i = 0; i < tiles.size(); i++)
                    {
                        if (tiles[i].GetBounds().contains(mousePosition))
                            tiles[i].ToggleFlag();
                    }
                }
                
            }

        }

        window.clear();
       
        for (int i = 0; i < tiles.size(); i++)
        {
            tiles[i].Draw(window);
        }

        window.draw(smiley);
        window.draw(debug);
        window.draw(test1);
        window.draw(test2);
        window.draw(test3);


        window.display();
    }

    TextureManager::Clear();

    return 0;
}




