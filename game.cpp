#include "game.h"

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
    this->countBlocks();
    this->initTowerUpgradeMenu();

    this->machine.makeBallista();

    this->getBounds();

    this->machineChangeMenu = new MachineChangeMenu(*menuTexture);

    this->machineUpgradeMenu = new MachineUpgradeMenu(*menuTexture, *plusTexture);
    this->machineUpgradeMenu->updateFirstInfo(std::to_string(this->machine.getDamageLevels()), std::to_string(this->machine.getProjectileDamage()), std::to_string(this->machine.getDamageUpgradeCost()));
    this->machineUpgradeMenu->updateSecondInfoBallista(std::to_string(this->machine.getSecondStatLevels()), std::to_string(this->machine.getSecondStatValues()), std::to_string(this->machine.getSecondStatUpgradeCost()));
    this->machineUpgradeMenu->secondStatSwitch(true);

    this->bg.setTexture(*bgTexture);
    this->bg.setScale(0.5,0.5);

    this->leftTower.setSize(sf::Vector2f(200,200));
    this->leftTower.setTexture(brickTexture);
    this->leftTower.setPosition(70,750);

    this->rightTower.setSize(sf::Vector2f(300,300));
    this->rightTower.setTexture(brickTexture);
    this->rightTower.setPosition(1090,750);
}

Game::~Game()
{
    delete this->window;
    delete this->blockTexture;
    delete this->tower;
    delete this->menuTexture;
    delete this->menu;
    delete this->towerUpgradeMenu;
    delete this->machineChangeMenu;
    delete this->machineUpgradeMenu;
    delete this->bgTexture;
    delete this->brickTexture;
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

    this->blockTexture = nullptr;
    this->menuTexture = nullptr;
    this->plusTexture = nullptr;
    this->bgTexture = nullptr;
    this->brickTexture = nullptr;

    this->tower = nullptr;

    this->menu = nullptr;

    this->towerUpgradeMenu = nullptr;

    this->machineChangeMenu = nullptr;

    this->machineUpgradeMenu = nullptr;

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

    this->bgTexture = new sf::Texture();
    this->bgTexture->loadFromFile("textures/background.png");
    this->bgTexture->setSmooth(true);

    this->brickTexture = new sf::Texture();
    this->brickTexture->loadFromFile("textures/brick.jpeg");
    this->brickTexture->setRepeated(true);
}

void Game::initNumBlocks()
{
    for(int i = 0; i < 8; i++)
    {
        this->numBlocks.emplace_back(0);
    }
    this->numBlocks[0] = 1;
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
        Block tempBlock(pow(4,i),colors[i],blockTexture,i);
        this->copyBlocks.emplace_back(tempBlock);
    }
}

void Game::countBlocks()
{
    for(auto &number : numBlocks)
    {
        currentBlocks+=number;
    }
}

void Game::initTowerUpgradeMenu()
{
    sf::Vector2f position(1400,140);
    this->towerUpgradeMenu = new TowerUpgradeMenu(*menuTexture,*plusTexture,position);
    this->towerUpgradeMenu->setMenuInfo("Upgrade block number", std::to_string(currentBlocks) + " / 105");
    this->towerUpgradeMenu->setCost(std::to_string(int(this->currentBlocks*2)));
}

void Game::getBounds()
{
    this->bounds.left = 0;
    this->bounds.top = 0;
    this->bounds.width = window->getSize().x;
    this->bounds.height = window->getSize().y;
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
                std::string tempString = std::to_string(int(it->cost()));
                it->setInfo(tempString);
            }
            menuExists = true;
        }
        else if(it->menuExists() and it->getMenuPlus().contains(window->mapPixelToCoords(getMousePositionRelativeToWindow())))
        {
            if(it->getLevel() < 7)
            {
                if(points >= it->cost())
                {
                    this->numBlocks[it->getLevel()]--;
                    it->upgradeBlock(copyBlocks[it->getLevel()+1]);
                    this->numBlocks[it->getLevel()]++;
                    points -= it->cost();
                    updatePoints();
                    std::string tempString = std::to_string(it->cost());
                    if(it->getLevel() == 7)
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
        }
        if(it->menuExists() and !it->getMenuWindow().contains(window->mapPixelToCoords(getMousePositionRelativeToWindow())))
        {
            it->deleteMenu();
            menuExists = false;
        }
    }
}

void Game::numBlocksUpdate()
{
    if(this->towerUpgradeMenu->getPlus().contains(sf::Vector2f(getMousePositionRelativeToWindow())))
    {
         if(this->points >= currentBlocks*4 and currentBlocks < 105)
         {
             this->points -= currentBlocks*4;
             updatePoints();
             this->numBlocks[0]++;
             currentBlocks++;
             this->tower->makeNewTower(numBlocks);
             menuExists = false;
             this->towerUpgradeMenu->setCost(std::to_string(int(this->currentBlocks*4)));
             this->towerUpgradeMenu->setNumberOfBlocks(std::to_string(currentBlocks));
         }
    }
}

void Game::damageBlocks()
{
    for(auto it = this->tower->towerBlocks.begin(); it < this->tower->towerBlocks.end(); it++)
    {
        if(!it->isDamaged() and it->getGlobalBounds().intersects(this->machine.getProjectileRect()) and !this->machine.isCannon())
        {
            it->switchDamagable(true);
            int curHp = it->getCurrentHp();
            if(it->damageBlock(this->machine.getProjectileDamage()))
            {
                this->points += it->getMaxHp();
                this->tower->towerBlocks.erase(it);
                this->tower->removeBlock();
                it--;
                updatePoints();
            }
            this->machine.update(curHp);
        }
        if(it->getGlobalBounds().intersects(this->machine.getProjectileRect()) and this->machine.isCannon())
        {
            sf::Vector2f center = it->getPosition();

            sf::CircleShape boom(50);
            boom.setPosition(center);
            float Radius1 = this->machine.getRadius();

            this->machine.update();

            for(auto it = this->tower->towerBlocks.begin(); it < this->tower->towerBlocks.end(); it++)
            {
                float Radius2 = (it->getGlobalBounds().width + it->getGlobalBounds().height) / 4;
                float xd = boom.getPosition().x - it->getPosition().x;
                float yd = boom.getPosition().y - it->getPosition().y;
                if(sqrt(xd * xd + yd * yd) <= Radius1 + Radius2)
                {
                    if(it->damageBlock(this->machine.getProjectileDamage()))
                    {
                        this->points += it->getMaxHp();
                        this->tower->towerBlocks.erase(it);
                        this->tower->removeBlock();
                        it--;
                        updatePoints();
                    }
                }
            }
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
                numBlocksUpdate();
                if(getMousePositionRelativeToWindow().x < 1000)
                {
                    this->machine.shoot(*window);
                        for(auto &block : this->tower->towerBlocks)
                        {
                            block.switchDamagable(false);
                        }
                }
                sf::Vector2f position(getMousePositionRelativeToWindow());
                if(this->machineChangeMenu->getBallistaButton().contains(position))
                {
                    this->machine.switchToBallista();
                    this->machineUpgradeMenu->updateFirstInfo(std::to_string(this->machine.getDamageLevels()),std::to_string(this->machine.getProjectileDamage()), std::to_string(this->machine.getDamageUpgradeCost()));
                    this->machineUpgradeMenu->updateSecondInfoBallista(std::to_string(this->machine.getSecondStatLevels()), std::to_string(this->machine.getSecondStatValues()), std::to_string(this->machine.getSecondStatUpgradeCost()));
                    this->machineUpgradeMenu->secondStatSwitch(true);
                }
                if(this->machineChangeMenu->getTrebuchetteButton().contains(position))
                {
                    this->machine.switchToTrebuchette();
                    this->machineUpgradeMenu->updateFirstInfo(std::to_string(this->machine.getDamageLevels()),std::to_string(this->machine.getProjectileDamage()), std::to_string(this->machine.getDamageUpgradeCost()));
                    this->machineUpgradeMenu->secondStatSwitch(false);
                }
                if(this->machineChangeMenu->getCannonButton().contains(position))
                {
                    this->machine.switchToCannon();
                    this->machineUpgradeMenu->updateFirstInfo(std::to_string(this->machine.getDamageLevels()),std::to_string(this->machine.getProjectileDamage()), std::to_string(this->machine.getDamageUpgradeCost()));
                    this->machineUpgradeMenu->updateSecondInfoCannon(std::to_string(this->machine.getSecondStatLevels()), std::to_string(this->machine.getSecondStatValues()), std::to_string(this->machine.getSecondStatUpgradeCost()));
                    this->machineUpgradeMenu->secondStatSwitch(true);
                }
                if(this->machineUpgradeMenu->getFirstPlus().contains(position))
                {
                    if(this->machine.getDamageLevels() < 10 and this->points >= this->machine.getDamageUpgradeCost())
                    {
                        this->machine.upgradeDmgLevel();
                        this->points -= this->machine.getDamageUpgradeCost();
                        this->updatePoints();
                        this->machineUpgradeMenu->updateFirstInfo(std::to_string(this->machine.getDamageLevels()),std::to_string(this->machine.getProjectileDamage()), std::to_string(this->machine.getDamageUpgradeCost()));
                    }
                }
                if(this->machineUpgradeMenu->getSecondPlus().contains(position))
                {
                    if(this->machine.getSecondStatLevels() < 10 and this->points >= this->machine.getSecondStatUpgradeCost())
                    {
                        this->machine.upgradeSecondStat();
                        this->points -= this->machine.getSecondStatUpgradeCost();
                        this->updatePoints();
                        if(this->machine.isCannon())
                        {
                            this->machineUpgradeMenu->updateSecondInfoCannon(std::to_string(this->machine.getSecondStatLevels()), std::to_string(this->machine.getSecondStatValues()), std::to_string(this->machine.getSecondStatUpgradeCost()));
                        }
                        else if(this->machine.isBallista())
                        {
                            this->machineUpgradeMenu->updateSecondInfoBallista(std::to_string(this->machine.getSecondStatLevels()), std::to_string(this->machine.getSecondStatValues()), std::to_string(this->machine.getSecondStatUpgradeCost()));
                        }
                    }
                }
            }
            if(ev.mouseButton.button == sf::Mouse::Right)
            {
                resetTower(numBlocks);
                menuExists = false;
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
    sf::Time elapsed = clock.restart();
    this->pollEvents();
    if(this->tower->getCurrentBlocks() <= this->tower->getMaxBlocks()/7)
    {
        this->counter += elapsed.asSeconds();
        if(this->counter>1)
        {
            Tower *temp;
            temp = new Tower(copyBlocks,numBlocks);
            delete tower;
            tower = temp;
            menuExists = false;
            this->counter = 0;
        }
    }
    this->machine.rotateMachine(*window);
    this->machine.animate(elapsed, bounds);
    this->damageBlocks();

    for(auto it = this->tower->towerBlocks.begin(); it < this->tower->towerBlocks.end(); it++)
    {
        if(it->getGlobalBounds().intersects(this->rightTower.getGlobalBounds()))
        {
            it->touching();
        }
        for(auto it2 = this->tower->towerBlocks.begin(); it2 < this->tower->towerBlocks.end(); it2++)
        {
            if(it!=it2)
            {
                if(it->getGlobalBounds().contains(it2->getGlobalBounds().left+20,it2->getGlobalBounds().top))
                {
                    it->touching();
                }
            }
        }
        it->animate(elapsed);
    }
}
void Game::render()
{
    //Clearing game objects
    this->window->clear(sf::Color::Black);
    //drawing main objects and background
    this->window->draw(this->bg);
    this->window->draw(this->leftTower);
    this->window->draw(this->rightTower);

    //Drawing game objects
    this->tower->towerDisplay(*this->window);
    this->window->draw(numPoints);
    this->towerUpgradeMenu->menuDisplay(*window);

    this->machine.display(*window);

    this->machineChangeMenu->display(*window);

    this->machineUpgradeMenu->display(*window);

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
