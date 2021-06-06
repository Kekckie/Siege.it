#ifndef TOWER_H
#define TOWER_H

#include "block.h"


class Tower
{
private:
    //tower variables that are used to generate all the blocks
    int totalNumberOfBlocks = 0;
    std::vector<sf::Color> colors;
    std::vector<int> numBlocks;
    std::vector<Block> towerBlocks;
    int tower_x = 1100, tower_y = 700;
    //private functions
    void initBlocks(sf::Texture &blockTexture, std::vector<sf::Color> &colors);
    void initColors();



public:
    //constructors / destructors
    Tower(sf::Texture &blockTexture,std::vector<int> &numBlocks);
    virtual ~Tower();
    //functions
    void towerDisplay(sf::RenderWindow &window);
};

#endif // TOWER_H
