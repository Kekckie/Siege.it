#ifndef MACHINEUPGRADEMENU_H
#define MACHINEUPGRADEMENU_H

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


class MachineUpgradeMenu
{
private:
    sf::Sprite menuBack;
    sf::Sprite firstPlus;
    sf::Sprite secondPlus;
    sf::Text firstStatInfo;
    sf::Text secondStatInfo;
    sf::Text firstStatData;
    sf::Text secondStatData;
    sf::Text firstCost;
    sf::Text secondCost;

    sf::Text menuText;

    sf::Font font;

    bool isThereSecondStat = false;


public:
    MachineUpgradeMenu(sf::Texture &menuBack, sf::Texture &plusTexture);
    ~MachineUpgradeMenu();
    //management functions
    void updateFirstInfo(std::string currentLevel, std::string currentDmg, std::string currentCost);
    void updateSecondInfoBallista(std::string currentLevel, std::string currentPiercing, std::string currentCost);
    void updateSecondInfoCannon(std::string currentLevel, std::string currentRadius, std::string currentCost);
    void secondStatSwitch(bool v);
    //display function
    void display(sf::RenderWindow &window);
    //accessors
    sf::FloatRect getFirstPlus();
    sf::FloatRect getSecondPlus();

};

#endif // MACHINEUPGRADEMENU_H
