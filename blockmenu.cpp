#include "blockmenu.h"

BlockMenu::BlockMenu(sf::Texture &menuTexture, sf::Texture &plusTexture, sf::Vector2f &position)
{
    this->menuBack.setTexture(menuTexture);
    this->menuBack.setScale(0.3,0.3);
    this->menuBack.setPosition(position);

    this->plusSign.setTexture(plusTexture);
    this->plusSign.setScale(0.02,0.02);
    this->plusSign.setPosition(position.x+7,position.y+7);

    this->font.loadFromFile("c:\\windows\\fonts\\arial.ttf");

    this->upgradeText.setFont(font);
    this->blockInfo.setFont(font);
    this->upgradeText.setFillColor(sf::Color::White);
    this->blockInfo.setFillColor(sf::Color::White);
    this->upgradeText.setCharacterSize(14);
    this->blockInfo.setCharacterSize(14);
    this->upgradeText.setPosition(position.x+30,position.y+7);
    this->blockInfo.setPosition(position.x+12, position.y+30);

}

BlockMenu::~BlockMenu()
{

}

void BlockMenu::menuDisplay(sf::RenderWindow &window)
{
    window.draw(menuBack);
    window.draw(plusSign);
    window.draw(upgradeText);
    window.draw(blockInfo);
}

sf::FloatRect BlockMenu::getGlobalBounds()
{
    return this->menuBack.getGlobalBounds();
}

void BlockMenu::setMenuInfo(std::string info, std::string uptext)
{
    this->blockInfo.setString(info);
    this->upgradeText.setString(uptext);

}

sf::FloatRect BlockMenu::getPlus()
{
    return this->plusSign.getGlobalBounds();
}
