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
    this->initTower(*this->blockTexture,this->numBlocks);
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

void Game::initBlock()
{
    this->block1 = new Block(1,sf::Color::Transparent,*this->blockTexture);
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
    this->numBlocks[1] = 40;
}

void Game::resetTower(sf::Texture &blockTexture,std::vector<int> &numBlocks)
{
    this->tower->makeNewTower(blockTexture,numBlocks);
}

void Game::updatePoints()
{
    this->numPoints.setString("Points: " + std::to_string(points));
}

void Game::initTower(sf::Texture &blockTexture,std::vector<int> &numBlocks)
{
    this->tower = new Tower(blockTexture,numBlocks);
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
                for(auto it = this->tower->towerBlocks.begin(); it < this->tower->towerBlocks.end(); it++)
                {
                    if(it->getGlobalBounds().contains(window->mapPixelToCoords(getMousePositionRelativeToWindow())) and this->menu == nullptr)
                    {
                        sf::Vector2f position(getMousePositionRelativeToWindow());
                        BlockMenu *temp = new BlockMenu(*menuTexture,*plusTexture,position);
                        this->menu = temp;
                    }
                    else if(this->menu != nullptr and this->menu->getGlobalBounds().contains(window->mapPixelToCoords(getMousePositionRelativeToWindow())))
                    {
                        break;
                    }
                    else
                    {
                        delete this->menu;
                        this->menu = nullptr;
                    }
                }
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
        temp = new Tower(*blockTexture,numBlocks);
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
    if(this->menu != nullptr)
    {
        this->menu->menuDisplay(*this->window);
    }
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
