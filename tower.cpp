#include "tower.h"

//private functions
    //void Tower::initBlockNumbers(std::vector<int> &numBlocks)
    //{
    //this->numberOfBlockOfCertainType[sf::Color::White] = numBlocks[0];
    //this->numberOfBlockOfCertainType[sf::Color::Blue] = numBlocks[1];
    //this->numberOfBlockOfCertainType[sf::Color::Cyan] = numBlocks[2];
    //this->numberOfBlockOfCertainType[sf::Color::Green] = numBlocks[3];
    //this->numberOfBlockOfCertainType[sf::Color::Magenta] = numBlocks[4];
    //this->numberOfBlockOfCertainType[sf::Color::Red] = numBlocks[5];
    //this->numberOfBlockOfCertainType[sf::Color::Yellow] = numBlocks[6];
    //this->numberOfBlockOfCertainType[sf::Color(255,168,0)] = numBlocks[7];
    //}

void Tower::initBlocks(sf::Texture &blockTexture, std::vector<sf::Color> &colors)
{
    for(int i = 0; i < colors.size(); i++)
    {
        for(int j = 0; j < numBlocks[i]; j++)
        {
            Block tempBlock(pow(2,i),colors[i],blockTexture);
            int offset_x = 0, offset_y = 0;
            offset_x = (totalNumberOfBlocks%7)*40;
            offset_y = (totalNumberOfBlocks/7)*40;
            tempBlock.setPosition(tower_x+offset_x,tower_y-offset_y);
            this->towerBlocks.emplace_back(tempBlock);
            totalNumberOfBlocks++;
        }
    }
}

void Tower::initColors()
{
    this->colors.emplace_back(sf::Color::White);
    this->colors.emplace_back(sf::Color::Blue);
    this->colors.emplace_back(sf::Color::Cyan);
    this->colors.emplace_back(sf::Color::Green);
    this->colors.emplace_back(sf::Color::Magenta);
    this->colors.emplace_back(sf::Color::Red);
    this->colors.emplace_back(sf::Color::Yellow);
    this->colors.emplace_back(sf::Color(255,168,0));
}

//constructors / destructors
Tower::Tower(sf::Texture &blockTexture, std::vector<int> &numBlocks)
{
    this->numBlocks = numBlocks;
    initColors();
    initBlocks(blockTexture,colors);
}
Tower::~Tower()
{

}

//functions
void Tower::towerDisplay(sf::RenderWindow &window)
{
    for(auto &block : this->towerBlocks)
    {
        window.draw(block);
    }
}
