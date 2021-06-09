#include "block.h"
//constructors / destructors
Block::Block(int maxHp, sf::Color color, sf::Texture &blockTexture)
{
    this->maxHp = maxHp;
    this->setColor(color);
    this->setTexture(blockTexture);
    this->setScale(0.5f,0.5f);
    this->hp = this->maxHp;
}

Block::~Block()
{

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
//private functions



