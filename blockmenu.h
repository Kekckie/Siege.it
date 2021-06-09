#ifndef BLOCKMENU_H
#define BLOCKMENU_H

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

#include "block.h"

class BlockMenu
{
private:
    sf::Sprite menuBack;
    sf::Sprite plusSign;
    sf::Text upgradeText , blockInfo;

public:
    BlockMenu(sf::Texture &menuTexture, sf::Texture &plusTexture, sf::Vector2f &position);
    virtual ~BlockMenu();
    void menuDisplay(sf::RenderWindow &window);
    sf::FloatRect getGlobalBounds();
};

#endif // BLOCKMENU_H
