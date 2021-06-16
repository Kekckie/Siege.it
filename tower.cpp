#include "tower.h"

//private functions
void Tower::initCopyBlocks(std::vector<Block> &copyBlocks)
{
    this->copyBlocks = copyBlocks;
}

void Tower::initBlocks()
{
    for(int i = 0; i < numBlocks.size(); i++)
    {
        for(int j = 0 ; j < numBlocks[i]; j++)
        {
            Block *tempBlock = copyBlocks[i].Clone();
            this->towerBlocks.emplace_back(*tempBlock);
            currentBlocks++;
        }
    }
}

void Tower::initRanlux()
{
    this->rd = rand();
    this->rng = new std::ranlux24(this->rd);
}



void Tower::randomizeBlocks(std::ranlux24 &rng)
{
    std::shuffle(std::begin(this->towerBlocks), std::end(this->towerBlocks), rng);
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

void Tower::setBlocksPosition()
{
    int blocks = 0;
    int offset_x = 0, offset_y = 0;
    for(auto &block : towerBlocks)
    {
        offset_x = (blocks%7)*40;
        offset_y = (blocks/7)*40;
        block.setPosition(this->tower_x+offset_x, this->tower_y-offset_y);
        blocks++;
    }
}

//constructors / destructors
Tower::Tower(std::vector<Block> &copyBlocks, std::vector<int> &numBlocks)
{
    this->numBlocks = numBlocks;
    initColors();
    initCopyBlocks(copyBlocks);
    initBlocks();
    initRanlux();
    randomizeBlocks(*rng);
    setBlocksPosition();

}
Tower::~Tower()
{
    delete rng;
}

//functions
void Tower::towerDisplay(sf::RenderWindow &window)
{
    for(auto &block : this->towerBlocks)
    {
        window.draw(block);
    }
    for(auto &block : this->towerBlocks)
    {
        if(block.menuExists())
            block.displayMenu(window);
    }
}

void Tower::removeBlock()
{
    currentBlocks--;
}

int Tower::getCurrentBlocks()
{
    return currentBlocks;
}

int Tower::getMaxBlocks()
{
    return totalNumberOfBlocks;
}

void Tower::makeNewTower(std::vector<int> &numBlocks)
{
    towerBlocks.clear();
    totalNumberOfBlocks = 0;
    currentBlocks = 0;
    this->numBlocks = numBlocks;
    initColors();
    initBlocks();
    initRanlux();
    randomizeBlocks(*rng);
    setBlocksPosition();
}




