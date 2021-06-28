#ifndef TOWER_H
#define TOWER_H

#include "block.h"


class Tower
{
private:
    //tower variables that are used to generate all the blocks
    int totalNumberOfBlocks = 0, currentBlocks = 0;
    std::vector<sf::Color> colors;
    std::vector<int> numBlocks;
    int tower_x = 1100, tower_y = 700;
    std::ranlux24 *rng;
    int rd = rand();
    std::vector<Block> copyBlocks;
    //private functions
    void initCopyBlocks(std::vector<Block> &copyBlocks);
    void initBlocks();
    void initRanlux();
    void randomizeBlocks(std::ranlux24 &rng);
    void initColors();
    void setBlocksPosition();
    void countBlocks();



public:
    //public variables
    std::vector<Block> towerBlocks;
    //constructors / destructors
    Tower(std::vector<Block> &copyBlocks,std::vector<int> &numBlocks);
    virtual ~Tower();
    //functions
    void towerDisplay(sf::RenderWindow &window);
    void removeBlock();
    int getCurrentBlocks();
    int getMaxBlocks();
    void makeNewTower(std::vector<int> &numBlocks);
};

#endif // TOWER_H
