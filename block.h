#ifndef BLOCK_H
#define BLOCK_H

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
#include <string>

#include "blockmenu.h"

class Block : public sf::Sprite
{
private:
    //private variables
    int blockLevel;
    int hp, maxHp;
    sf::Texture blockTexture;
    BlockMenu *menu;
    //private functions

public:
    //public variables

    //constructort / destructors
    Block(int maxHp, sf::Color color, sf::Texture &blockTexture, int blockLevel);
    virtual ~Block();
    //functions
    bool damageBlock(int dmg);
    int getMaxHp();
    std::string stringColor();
    int getLevel();
    void upgradeBlock(Block &block);
    void createMenu(sf::Texture &menuTexture, sf::Texture &plusTexture, sf::Vector2f &position);
    void setInfo(std::string &info);
    void deleteMenu();
    Block *Clone() const {return new Block{*this};};

    //accessors
    bool menuExists();
    sf::FloatRect getMenuPlus();
    sf::FloatRect getMenuWindow();
    void displayMenu(sf::RenderWindow &window);

};

#endif // BLOCK_H
