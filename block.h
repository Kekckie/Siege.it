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

class Block : public sf::Sprite
{
private:
    //private variables
    int hp, maxHp;
    sf::Color color;
    sf::Texture blockTexture;

    //private functions

public:
    //constructort / destructors
    Block(int maxHp, sf::Color color, sf::Texture &blockTexture);
    virtual ~Block();
    //functions
    bool damageBlock(int dmg);
};

#endif // BLOCK_H
