#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <unordered_map>
#include <fstream>
#include <sstream>

#include "TextureManager.h"
#include "Tile.h"
#include "Random.h"

using namespace std;


void ClearAdj(vector<Tile>& tiles, int columns, int i, bool first);
void NewBoard(int columns, int rows, int bombs, vector<Tile>& tiles);
void NewBoard(int columns, int rows, vector<int>& bombIndexes, vector<Tile>& tiles);

int main()
{
    ifstream file("boards/config.cfg");
    string value;
    vector<int> bombIndexes;
    int columns;
    file >> columns;
    int rows;
    file >> rows;
    int bombs;
    file >> bombs;
    file.close();

    //int columns = 25;
    //int rows = 16;
    //int bombs = 400;

    bool gameOver = false;
    bool gameWon = false;
    int unrevTiles = columns * rows - bombs;
    
    sf::RenderWindow window(sf::VideoMode(columns * 32, rows*32 + 88), "Minesweeper");

    vector<Tile> tiles;
    NewBoard(columns, rows, bombs, tiles);
   
    sf::Sprite smiley;
    smiley.setTexture(TextureManager::GetTexture("face_happy"));
    smiley.setPosition(window.getSize().x/2 - 32, window.getSize().y - 88);
    
    sf::Sprite sadFace;
    sadFace.setTexture(TextureManager::GetTexture("face_lose"));
    sadFace.setPosition(window.getSize().x / 2 - 32, window.getSize().y - 88);

    sf::Sprite winFace;
    winFace.setTexture(TextureManager::GetTexture("face_win"));
    winFace.setPosition(window.getSize().x / 2 - 32, window.getSize().y - 88);

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

    sf::Sprite digits;
    digits.setTexture(TextureManager::GetTexture("digits"));
    digits.setPosition(window.getSize().x / 2 - 32 + 64 * 5, window.getSize().y - 88);

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
                    for ( int i = 0; i < tiles.size(); i++)
                    {
                        if (tiles[i].GetBounds().contains(mousePosition) && !gameOver && !gameWon)
                        {
                            if (tiles[i].GetHidden() && !tiles[i].getHasBomb())
                            {
                                ClearAdj(tiles, columns, i, true);
                            }
                            if (tiles[i].getHasBomb() && !tiles[i].GetHasFlag())
                            {
                                gameOver = true;
                                for (unsigned int i = 0; i < tiles.size(); i++)
                                {
                                    tiles[i].LostGame();
                                    if (tiles[i].getHasBomb())
                                        tiles[i].RevealTile();
                                }
                            }
                            tiles[i].RevealTile();
                            
                        }
                        
                    }
                    int counter = 0;
                    for (int i = 0; i < tiles.size(); i++)
                    {
                        if (tiles[i].GetHidden() && !tiles[i].getHasBomb())
                            counter++;
                    }
                    unrevTiles = counter;

                    if (unrevTiles == 0 && !gameOver)
                    {
                        gameWon = true;
                        for (unsigned int i = 0; i < tiles.size(); i++)
                        {
                            tiles[i].WonGame();
                            /*if (tiles[i].getHasBomb())
                                if(!tiles[i].GetHasFlag())
                                    tiles[i].ToggleFlag();*/
                        }
                    }
                    if (debug.getGlobalBounds().contains(mousePosition))
                    {
                        for (unsigned int i = 0; i < tiles.size(); i++)
                        {
                           tiles[i].ToggleDebug();
                        }
                    }
                    if (smiley.getGlobalBounds().contains(mousePosition))
                    {
                        for (unsigned int i = 0; i < tiles.size(); i++)
                        {
                            gameOver = false;
                            gameWon = false;
                            NewBoard(columns, rows, bombs, tiles);
                        }
                    }
                    if (test1.getGlobalBounds().contains(mousePosition))
                    {
                        //ifstream inFile("/boards/testboard1.brd");
                        ifstream inFile("boards/testboard1.brd");
                        string lines = "";
                        string value;
                        vector<int> bombIndexes;
                        while (inFile >> value)
                        {
                            lines.append(value);
                        }
                        for (int i = 0; i < lines.size(); i++)
                        {
                            if (lines[i] == '1')
                            {
                                bombIndexes.push_back(i);
                            }
                        }
                        inFile.close();
                        gameOver = false;
                        gameWon = false;
                        NewBoard(columns, rows, bombIndexes, tiles);
                    }
                    if (test2.getGlobalBounds().contains(mousePosition))
                    {
                        //ifstream inFile("/boards/testboard1.brd");
                        ifstream inFile("boards/testboard2.brd");
                        string lines = "";
                        string value;
                        vector<int> bombIndexes;
                        while (inFile >> value)
                        {
                            lines.append(value);
                        }
                        for (int i = 0; i < lines.size(); i++)
                        {
                            if (lines[i] == '1')
                            {
                                bombIndexes.push_back(i);
                            }
                        }
                        inFile.close();
                        gameOver = false;
                        gameWon = false;
                        NewBoard(columns, rows, bombIndexes, tiles);
                    }if (test3.getGlobalBounds().contains(mousePosition))
                    {
                        //ifstream inFile("/boards/testboard1.brd");
                        ifstream inFile("boards/testboard3.brd");
                        string lines = "";
                        string value;
                        vector<int> bombIndexes;
                        while (inFile >> value)
                        {
                            lines.append(value);
                        }
                        for (int i = 0; i < lines.size(); i++)
                        {
                            if (lines[i] == '1')
                            {
                                bombIndexes.push_back(i);
                            }
                        }
                        inFile.close();
                        gameOver = false;
                        gameWon = false;
                        NewBoard(columns, rows, bombIndexes, tiles);
                    }
                }

                if (event.mouseButton.button == sf::Mouse::Right && !gameOver)
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
        if (gameOver)
            window.draw(sadFace);
        if (gameWon)
            window.draw(winFace);
        window.draw(debug);
        window.draw(test1);
        window.draw(test2);
        window.draw(test3);


        window.display();
    }

    TextureManager::Clear();

    return 0;
}


void ClearAdj(vector<Tile>& tiles, int columns, int i, bool first)
{
  
    if (tiles[i].getHasBomb() == false && (first || (!first && tiles[i].getAdjBombs() == 0)) && !tiles[i].GetAdjChecked() &&
        tiles[i].getAdjBombs() == 0 && !tiles[i].GetHasFlag())
    {
        tiles[i].SetAdjCheckedTrue();
        if (i - columns >= 0 && tiles[i - columns].getHasBomb() == false)
        {
            tiles[i - columns].RevealTile();
            if (tiles[i - columns].getAdjBombs() == 0 && tiles[i - columns].getHasBomb() == false)
                ClearAdj(tiles, columns, i - columns, false);
        }
        if (i - columns + 1 >= 0 && (i - columns + 1) % columns != 0 && tiles[i - columns + 1].getHasBomb() == false &&
            tiles[i].getAdjBombs() == 0)
        {
            tiles[i - columns + 1].RevealTile();
            if (tiles[i - columns + 1].getAdjBombs() == 0)
                ClearAdj(tiles, columns, i - columns + 1, false);
        }
        if (i - columns - 1 >= 0 && (i - columns) % columns != 0 && tiles[i - columns - 1].getHasBomb() == false && 
            tiles[i].getAdjBombs() == 0)
        {
            tiles[i - columns - 1].RevealTile();
            if (tiles[i - columns - 1].getAdjBombs() == 0)
                ClearAdj(tiles, columns, i - columns - 1, false);
        }
        if (i + columns < tiles.size() && tiles[i + columns].getHasBomb() == false)
        {   
            tiles[i + columns].RevealTile();
            if (tiles[i + columns].getAdjBombs() == 0)
            { 
                ClearAdj(tiles, columns, i + columns, false);
            }
        }    
        if (i + columns + 1 < tiles.size() && (i + columns + 1) % columns != 0 && tiles[i + columns + 1].getHasBomb() == false &&
            tiles[i].getAdjBombs() == 0)
        {
            tiles[i + columns + 1].RevealTile();
            if (tiles[i + columns + 1].getAdjBombs() == 0)
                ClearAdj(tiles, columns, i + columns + 1, false);
        }
        if (i + columns - 1 < tiles.size() && (i - columns) % columns != 0 && tiles[i + columns - 1].getHasBomb() == false &&
            tiles[i].getAdjBombs() == 0)
        {
            tiles[i + columns - 1].RevealTile();
            if (tiles[i + columns - 1].getAdjBombs() == 0)
                ClearAdj(tiles, columns, i + columns - 1, false);
        }
        if (i - 1 >= 0 && (i) % columns != 0 && tiles[i - 1].getHasBomb() == false)
        {
            tiles[i - 1].RevealTile();
            if (tiles[i - 1].getAdjBombs() == 0)
                ClearAdj(tiles, columns, i - 1, false);
        }
        if (i + 1 < tiles.size() && (i + 1) % columns != 0 && tiles[i + 1].getHasBomb() == false)
        {
            tiles[i + 1].RevealTile();
            if (tiles[i + 1].getAdjBombs() == 0)
                ClearAdj(tiles, columns, i + 1, false);
        }
    }
    
}


void NewBoard(int columns, int rows, int bombs, vector<Tile>& tiles)
{
    tiles.clear();
    Tile myTile;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            myTile.SetPosition(32 * j, 32 * i);
            tiles.push_back(myTile);
        }
    }

    vector<int> bombIndexes;
    while (bombIndexes.size() < bombs)
    {
        int num = Random::Int(0, tiles.size() - 1);
        bool contains = false;
        for (int i = 0; i < bombIndexes.size(); i++)
            if (bombIndexes[i] == num)
                contains = true;
        if (!contains)
            bombIndexes.push_back(num);
    }

    /*for (int i = 0; i < bombs; i++)
    {
        int num = Random::Int(0, tiles.size() - 1);
        tiles[num].PlaceBomb();
    }*/
    for (int i = 0; i < bombs; i++)
    {
        tiles[bombIndexes[i]].PlaceBomb();
    }

    for (int i = 0; i < tiles.size(); i++)
    {
        if (i - columns >= 0 && tiles[i - columns].getHasBomb())
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
        if (i - 1 >= 0 && (i) % columns != 0 && tiles[i - 1].getHasBomb())
            tiles[i].addAdjBomb();
        if (i + 1 < tiles.size() && (i + 1) % columns != 0 && tiles[i + 1].getHasBomb())
            tiles[i].addAdjBomb();
        tiles[i].setNum();
    }
}

void NewBoard(int columns, int rows, vector<int>& bombIndexes, vector<Tile>& tiles)
{
    tiles.clear();
    Tile myTile;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            myTile.SetPosition(32 * j, 32 * i);
            tiles.push_back(myTile);
        }
    }

    for (int i = 0; i < bombIndexes.size(); i++)
    {
        cout << bombIndexes[i] << endl;
        tiles[bombIndexes[i]].PlaceBomb();
    }

    for (int i = 0; i < tiles.size(); i++)
    {
        if (i - columns >= 0 && tiles[i - columns].getHasBomb())
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
        if (i - 1 >= 0 && (i) % columns != 0 && tiles[i - 1].getHasBomb())
            tiles[i].addAdjBomb();
        if (i + 1 < tiles.size() && (i + 1) % columns != 0 && tiles[i + 1].getHasBomb())
            tiles[i].addAdjBomb();
        tiles[i].setNum();
    }
}
