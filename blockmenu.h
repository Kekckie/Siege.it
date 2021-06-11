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

class BlockMenu
{
private:
    sf::Sprite menuBack;
    sf::Sprite plusSign;
    sf::Text upgradeText , blockInfo;
    sf::Font font;

public:
    BlockMenu(sf::Texture &menuTexture, sf::Texture &plusTexture, sf::Vector2f &position);
    virtual ~BlockMenu();
    void menuDisplay(sf::RenderWindow &window);
    sf::FloatRect getGlobalBounds();
    void setMenuInfo(std::string blockInfo, std::string upgradeText);
    sf::FloatRect getPlus();
};

#endif // BLOCKMENU_H
