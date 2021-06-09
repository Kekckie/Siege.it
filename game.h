#ifndef GAME_H
#define GAME_H
//Standard and SFML includes
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <functional>
#include <stdlib.h>
#include <string>
#include <random>
#include <iostream>
#include <memory>
#include <vector>

//Custom class includes
#include "block.h"
#include "tower.h"
#include "blockmenu.h"

class Game
{
private:
    //private definitions
    sf::Event ev;
    sf::VideoMode videoMode;
    sf::RenderWindow *window;
    Block *block1;
    sf::Texture *blockTexture;
    sf::Texture *menuTexture;
    sf::Texture *plusTexture;
    Tower *tower;
    std::vector<int> numBlocks;
    unsigned long long int points = 0;
    sf::Text numPoints;
    sf::Font font;
    BlockMenu *menu;
    //private functions
    void initVariables();
    void initWindow();
    void initBlock();
    void initTextures();
    void initTower(sf::Texture &blockTexture,std::vector<int> &numBlocks);
    void initNumBlocks();
    void resetTower(sf::Texture &blockTexture,std::vector<int> &numBlocks);
    void updatePoints();

public:
    //constructors
    Game();
    virtual ~Game();
    //functions
    void pollEvents();
    void update();
    void render();
    //accessors
    bool running() const;
    sf::Vector2i getMousePositionRelativeToWindow();
};


#endif // GAME_H
