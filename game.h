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
#include <ctime>

//Custom class includes
#include "block.h"
#include "tower.h"
#include "blockmenu.h"
#include "towerupgrademenu.h"
#include "machine.h"

class Game
{
private:
    //private definitions
    sf::Event ev;
    sf::VideoMode videoMode;
    sf::RenderWindow *window;
    //texture definitions
    sf::Texture *blockTexture;
    sf::Texture *menuTexture;
    sf::Texture *plusTexture;
    //tower definitions
    Tower *tower;
    std::vector<int> numBlocks;
    unsigned long long int points = 4;
    sf::Text numPoints;
    sf::Font font;
    BlockMenu *menu;
    std::vector<sf::Color> colors;
    std::vector<Block> copyBlocks;
    bool menuExists = false;
    const int maxBlocks = 105;
    int currentBlocks = 0;
    TowerUpgradeMenu *towerUpgradeMenu;
    //machine definitions
    Machine machine;
    //private functions
    void initVariables();
    void initWindow();
    void initTextures();
    void initTower(std::vector<Block> &copyBlocks);
    void initNumBlocks();
    void resetTower(std::vector<int> &numBlocks);
    void updatePoints();
    void initColors();
    void initCopyBlocks(sf::Texture &blockTexture, std::vector<sf::Color> &colors);
    void countBlocks();
    void initTowerUpgradeMenu();
    //event functions
    void blockUpgradeMenuFunction();

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
