#include "game.h"
#include "block.h"


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
}

//private functions
void Game::initVariables()
{
    this->videoMode.height = 900;
    this->videoMode.width = 1600;

    this->window = nullptr;

    this->block1 = nullptr;

    this->blockTexture = nullptr;

    this->tower = nullptr;
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
}

void Game::initNumBlocks()
{
    for(int i = 0; i < 8; i++)
    {
        this->numBlocks.emplace_back(0);
    }
    this->numBlocks[0] = 40;

    this->numBlocks[4] = 40;
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
        case sf::Event::Closed:
            this->window->close();
            break;
    }
}
void Game::update()
{
    this->pollEvents();


}
void Game::render()
{
    //Clearing game objects
    this->window->clear(sf::Color::Black);

    //Drawing game objects
    this->tower->towerDisplay(*this->window);
    this->window->display();
}
//accessors
bool Game::running() const
{
    return this->window->isOpen();
}
