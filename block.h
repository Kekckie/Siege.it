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

#include "blockmenu.h"

class Block : public sf::Sprite
{
private:
    //private variables
    int hp, maxHp;
    sf::Color color;
    sf::Texture blockTexture;
    //private functions

public:
    //public variables

    //constructort / destructors
    Block(int maxHp, sf::Color color, sf::Texture &blockTexture);
    virtual ~Block();
    //functions
    bool damageBlock(int dmg);
    int getMaxHp();
};

#endif // BLOCK_H
