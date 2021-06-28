#include "towerupgrademenu.h"

TowerUpgradeMenu::TowerUpgradeMenu(sf::Texture &menuTexture, sf::Texture &plusTexture, sf::Vector2f &position)
{
    this->menuBack.setTexture(menuTexture);
    this->menuBack.setScale(0.3,0.3);
    this->menuBack.rotate(270);
    this->menuBack.setPosition(position);

    this->plusSign.setTexture(plusTexture);
    this->plusSign.setScale(0.025,0.025);
    this->plusSign.setPosition(position.x+12, position.y-85);

    this->font.loadFromFile("c:\\windows\\fonts\\arial.ttf");

    this->upgradeText.setFont(font);
    this->towerInfo.setFont(font);
    this->cost.setFont(font);
    this->costInfo.setFont(font);
    this->upgradeText.setFillColor(sf::Color::White);
    this->towerInfo.setFillColor(sf::Color::White);
    this->cost.setFillColor(sf::Color::White);
    this->costInfo.setFillColor(sf::Color::White);
    this->upgradeText.setCharacterSize(14);
    this->towerInfo.setCharacterSize(14);
    this->cost.setCharacterSize(14);
    this->costInfo.setCharacterSize(14);
    this->upgradeText.setPosition(position.x+40,position.y-82);
    this->towerInfo.setPosition(position.x+17, position.y-110);
    this->cost.setPosition(position.x+105, position.y-55);
    this->costInfo.setPosition(position.x+17, position.y-55);

    this->costInfo.setString("Current cost:");
}

TowerUpgradeMenu::~TowerUpgradeMenu()
{

}

void TowerUpgradeMenu::menuDisplay(sf::RenderWindow &window)
{
    window.draw(menuBack);
    window.draw(plusSign);
    window.draw(upgradeText);
    window.draw(towerInfo);
    window.draw(cost);
    window.draw(costInfo);
}
sf::FloatRect TowerUpgradeMenu::getPlus()
{
    return this->plusSign.getGlobalBounds();
}

void TowerUpgradeMenu::setMenuInfo(std::string info, std::string uptext)
{
    this->towerInfo.setString(info);
    this->upgradeText.setString(uptext);

}

void TowerUpgradeMenu::setCost(std::string cost)
{
    this->cost.setString(cost);
}

sf::FloatRect TowerUpgradeMenu::getGlobalBounds()
{
    return this->menuBack.getGlobalBounds();
}

void TowerUpgradeMenu::setNumberOfBlocks(std::string number)
{
    this->upgradeText.setString(number+ " / 105");
}
