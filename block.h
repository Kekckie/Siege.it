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
#include <math.h>

#include "blockmenu.h"

class Block : public sf::Sprite
{
private:
    //private variables
    int blockLevel;
    int hp, maxHp;
    sf::Texture blockTexture;
    BlockMenu *menu;
    bool canBeDamaged;
    float speed = 0;
    //private functions

public:
    //public variables

    //constructort / destructors
    Block(int maxHp, sf::Color color, sf::Texture &blockTexture, int blockLevel);
    virtual ~Block();
    //functions
    bool damageBlock(int dmg);
    int getMaxHp();
    int getCurrentHp();
    std::string stringColor();
    int getLevel();
    void upgradeBlock(Block &block);
    void createMenu(sf::Texture &menuTexture, sf::Texture &plusTexture, sf::Vector2f &position);
    void setInfo(std::string &info);
    void deleteMenu();
    Block *Clone() const {return new Block{*this};};
    void switchDamagable(bool flag);

    //accessors
    bool menuExists();
    sf::FloatRect getMenuPlus();
    sf::FloatRect getMenuWindow();
    void displayMenu(sf::RenderWindow &window);
    int cost();
    bool isDamaged();

    void animate(sf::Time &elapsed);
    void touching();


};

#endif // BLOCK_H
