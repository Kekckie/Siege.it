#include "blockmenu.h"
#include "block.h"

BlockMenu::BlockMenu(sf::Texture &menuTexture, sf::Texture &plusTexture, sf::Vector2f &position)
{
    this->menuBack.setTexture(menuTexture);
    this->menuBack.setScale(0.3,0.3);
    this->menuBack.setPosition(position);

    this->plusSign.setTexture(plusTexture);
    this->plusSign.setScale(0.02,0.02);
    this->plusSign.setPosition(position.x+7,position.y+7);


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
