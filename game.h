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
#include "machinechangemenu.h"
#include "machineupgrademenu.h"

class Game
{
private:
    //private definitions
    sf::Event ev;
    sf::VideoMode videoMode;
    sf::RenderWindow *window;
    sf::Clock clock;
    float counter = 0;
    sf::Sprite bg;
    sf::RectangleShape leftTower;
    sf::RectangleShape rightTower;
    sf::FloatRect bounds;
    //texture definitions
    sf::Texture *brickTexture;
    sf::Texture *bgTexture;
    sf::Texture *blockTexture;
    sf::Texture *menuTexture;
    sf::Texture *plusTexture;
    //tower definitions
    Tower *tower;
    std::vector<int> numBlocks;
    unsigned long long int points = 10000000000;
    sf::Text numPoints;
    sf::Font font;
    BlockMenu *menu;
    std::vector<sf::Color> colors;
    std::vector<Block> copyBlocks;
    bool menuExists = false;
    const int maxBlocks = 105;
    int currentBlocks = 0;
    TowerUpgradeMenu *towerUpgradeMenu;
    MachineChangeMenu *machineChangeMenu;
    MachineUpgradeMenu *machineUpgradeMenu;
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
    void getBounds();
    //event functions
    void blockUpgradeMenuFunction();
    void numBlocksUpdate();
    void damageBlocks();

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
