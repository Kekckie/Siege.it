#include "block.h"
#include "blockmenu.h"
//constructors / destructors
Block::Block(int maxHp, sf::Color color, sf::Texture &blockTexture, int blockLevel)
{
    this->maxHp = maxHp;
    this->setColor(color);
    this->setTexture(blockTexture);
    this->setScale(0.5f,0.5f);
    this->hp = this->maxHp;
    this->blockLevel = blockLevel;
    this->menu = nullptr;
}

Block::~Block()
{
    delete menu;
}

bool Block::damageBlock(int dmg)
{
    this->hp-=dmg;
    if(hp <= 0)
    {
        return true;
    }
    return false;
}

int Block::getMaxHp()
{
    return maxHp;
}

std::string Block::stringColor()
{
    if(this->getColor() == sf::Color::White)
        return "White -> Blue";
    if(this->getColor() == sf::Color::Blue)
        return "Blue -> Cyan";
    if(this->getColor() == sf::Color::Cyan)
        return "Cyan -> Green";
    if(this->getColor() == sf::Color::Green)
        return "Green -> Magenta";
    if(this->getColor() == sf::Color::Magenta)
        return "Magenta -> Red";
    if(this->getColor() == sf::Color::Red)
        return "Red -> Yellow";
    if(this->getColor() == sf::Color::Yellow)
        return "Yellow -> Orange";
    if(this->getColor() == sf::Color(255,168,0))
        return "Orange(max)";
    return "error?";
}

int Block::getLevel()
{
    return blockLevel;
}

void Block::upgradeBlock(Block &block)
{
    this->hp = block.maxHp;
    this->maxHp = block.maxHp;
    this->setColor(block.getColor());
    this->blockLevel = block.blockLevel;
}

void Block::createMenu(sf::Texture &menuTexture, sf::Texture &plusTexture, sf::Vector2f &position)
{
    this->menu = new BlockMenu(menuTexture,plusTexture,position);
}

void Block::setInfo(std::string &info)
{
    this->menu->setMenuInfo(stringColor(),"Cost: " + info);
}

void Block::deleteMenu()
{
    if(this->menu != nullptr)
    {
        delete this->menu;
        this->menu = nullptr;
    }
}

//accessors

bool Block::menuExists()
{
    if(this->menu != nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

sf::FloatRect Block::getMenuPlus()
{
    return this->menu->getPlus();
}

sf::FloatRect Block::getMenuWindow()
{
    return this->menu->getGlobalBounds();
}

void Block::displayMenu(sf::RenderWindow &window)
{
    this->menu->menuDisplay(window);
}


//private functions



