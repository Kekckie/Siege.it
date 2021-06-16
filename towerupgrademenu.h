#ifndef TOWERUPGRADEMENU_H
#define TOWERUPGRADEMENU_H

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


class TowerUpgradeMenu
{
private:
    sf::Sprite menuBack;
    sf::Sprite plusSign;
    sf::Text upgradeText;
    sf::Text towerInfo;
    sf::Text cost;
    sf::Text costInfo;
    sf::Font font;

public:
    TowerUpgradeMenu(sf::Texture &menuTexture, sf::Texture &plusTexture, sf::Vector2f &position);
    virtual ~TowerUpgradeMenu();
    void menuDisplay(sf::RenderWindow &window);
    sf::FloatRect getPlus();
    void setMenuInfo(std::string blockInfo, std::string upgradeText);
    void setCost(std::string cost);
    sf::FloatRect getGlobalBounds();
};

#endif // TOWERUPGRADEMENU_H
