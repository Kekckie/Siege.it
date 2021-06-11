#include "game.h"
#include "block.h"
#include "blockmenu.h"


//constructors / destructors
Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initTextures();
    this->initNumBlocks();
    this->initColors();
    this->initCopyBlocks(*blockTexture,colors);
    this->initTower(this->copyBlocks);
}

Game::~Game()
{
    delete this->window;
    delete this->block1;
    delete this->blockTexture;
    delete this->tower;
    delete this->menuTexture;
    delete this->menu;
}

//private functions
void Game::initVariables()
{
    this->videoMode.height = 900;
    this->videoMode.width = 1600;
    this->numPoints.setString("Points: " + std::to_string(points));
    this->numPoints.setFillColor(sf::Color::White);
    this->font.loadFromFile("c:\\windows\\fonts\\arial.ttf");
    this->numPoints.setFont(font);
    this->numPoints.setCharacterSize(20);
    this->numPoints.setPosition(750,20);

    this->window = nullptr;

    this->block1 = nullptr;

    this->blockTexture = nullptr;
    this->menuTexture = nullptr;
    this->plusTexture = nullptr;

    this->tower = nullptr;

    this->menu = nullptr;
}

void Game::initWindow()
{
    this->window = new sf::RenderWindow(this->videoMode,"SiegeIT", sf::Style::Titlebar | sf::Style::Close);
}

void Game::initTextures()
{
    this->blockTexture = new sf::Texture();
    this->blockTexture->loadFromFile("textures/block.png");
    this->blockTexture->setSmooth(true);

    this->menuTexture = new sf::Texture();
    this->menuTexture->loadFromFile("textures/BlankPanel.png");

    this->plusTexture = new sf::Texture();
    this->plusTexture->loadFromFile("textures/plusButton.png");
    this->plusTexture->setSmooth(true);
}

void Game::initNumBlocks()
{
    for(int i = 0; i < 8; i++)
    {
        this->numBlocks.emplace_back(0);
    }
    this->numBlocks[0] = 40;
    this->numBlocks[7] = 40;
}

void Game::resetTower(std::vector<int> &numBlocks)
{
    this->tower->makeNewTower(numBlocks);
}

void Game::updatePoints()
{
    this->numPoints.setString("Points: " + std::to_string(points));
}

void Game::initColors()
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

void Game::initCopyBlocks(sf::Texture &blockTexture, std::vector<sf::Color> &colors)
{
    for(int i = 0; i < colors.size(); i++)
    {
        Block tempBlock(pow(2,i),colors[i],blockTexture,i);
        this->copyBlocks.emplace_back(tempBlock);
    }
}

void Game::blockUpgradeMenuFunction()
{
    for(auto it = this->tower->towerBlocks.begin(); it < this->tower->towerBlocks.end(); it++)
    {
        if(it->getGlobalBounds().contains(window->mapPixelToCoords(getMousePositionRelativeToWindow())) and menuExists == false)
        {
            sf::Vector2f position(getMousePositionRelativeToWindow());
//                        BlockMenu *temp = new BlockMenu(*menuTexture,*plusTexture,position);
            it->createMenu(*menuTexture,*plusTexture,position);
            if(it->getColor() == sf::Color(255,168,0))
            {
                std::string tempString = "-------";
                it->setInfo(tempString);
            }
            else
            {
                std::string tempString = std::to_string(int(pow(it->getMaxHp()+1,2)));
                it->setInfo(tempString);
            }
            menuExists = true;
        }
        else if(it->menuExists() and it->getMenuPlus().contains(window->mapPixelToCoords(getMousePositionRelativeToWindow())))
        {
            if(it->getLevel() < 7)
            {
                it->upgradeBlock(copyBlocks[it->getLevel()+1]);
                this->numBlocks[it->getLevel()]--;
                this->numBlocks[it->getLevel()+1]++;
                std::string tempString = std::to_string(int(pow(it->getMaxHp()+1,2)));
                if(it->getColor() == sf::Color(255,168,0))
                {
                    std::string tempString = "-------";
                    it->setInfo(tempString);
                }
                else
                {
                    it->setInfo(tempString);
                }
            }
        }
        if(it->menuExists() and !it->getMenuWindow().contains(window->mapPixelToCoords(getMousePositionRelativeToWindow())))
        {
            it->deleteMenu();
            menuExists = false;
        }
    }
}

void Game::initTower(std::vector<Block> &copyBlocks)
{
    this->tower = new Tower(copyBlocks,numBlocks);
}
//functions
void Game::pollEvents()
{
    /*
     *event processing loop for a game
    */
    while(this->window->pollEvent(this->ev))
    {
        switch(this->ev.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::MouseButtonPressed:
            if(ev.mouseButton.button == sf::Mouse::Left)
            {
                blockUpgradeMenuFunction();
            }
            break;

        }
        /*
        if(it->damageBlock(1))
        {
                this->points += it->getMaxHp();
                this->tower->towerBlocks.erase(it);
                this->tower->removeBlock();
                it--;
                updatePoints();
        }
        */
    }
}
void Game::update()
{
    this->pollEvents();
    if(this->tower->getCurrentBlocks() <= this->tower->getMaxBlocks()/10)
    {
        Tower *temp;
        temp = new Tower(copyBlocks,numBlocks);
        delete tower;
        tower = temp;
    }
}
void Game::render()
{
    //Clearing game objects
    this->window->clear(sf::Color::Black);

    //Drawing game objects
    this->tower->towerDisplay(*this->window);
    this->window->draw(numPoints);

    this->window->display();
}
//accessors
bool Game::running() const
{
    return this->window->isOpen();
}

sf::Vector2i Game::getMousePositionRelativeToWindow()
{
    return sf::Mouse::getPosition(*window);
}
