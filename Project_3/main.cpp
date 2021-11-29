#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <ctime>
#include <unordered_map>

#include "TextureManager.h"

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
    sf::Sprite hiddenTile(TextureManager::GetTexture("tile_hidden"));

    sf::Texture texture;
    //texture.loadFromFile("C:/Users/Stefan/Desktop/Project_Minesweeper/images/tile_hidden.png");
    //texture.loadFromFile("images/tile_hidden.png");

    //sf::Sprite hiddenTile(texture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(hiddenTile);
        window.display();
    }

    TextureManager::Clear();

    return 0;
}

//int main()
//{
//    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
//    sf::CircleShape shape(100.f);
//    shape.setFillColor(sf::Color::Green);
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        window.clear();
//        window.draw(shape);
//        window.display();
//    }
//
//    return 0;
//}
