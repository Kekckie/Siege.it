#include "machine.h"
//Machine
Machine::Machine()
{
    this->ballista = nullptr;
    this->trebuchette = nullptr;
    this->cannon = nullptr;
}

Machine::~Machine()
{
    delete this->ballista;
    delete this->trebuchette;
    delete this->cannon;
}

void Machine::display(sf::RenderWindow &window)
{
    if(this->ballista != nullptr)
    {
        this->ballista->display(window);
    }
    if(this->trebuchette != nullptr)
    {
        this->trebuchette->display(window);
    }
    if(this->cannon != nullptr)
    {
        this->cannon->display(window);
    }
}

void Machine::makeBallista()
{
    this->ballista = new Ballista();
}

void Machine::makeTrebuchette()
{
    this->trebuchette = new Trebuchette();
}

void Machine::makeCannon()
{
    this->cannon = new Cannon();
}

void Machine::rotateMachine(sf::RenderWindow &win)
{
    if(this->ballista != nullptr)
    {
        this->ballista->rotateBow(win);
    }
    if(this->cannon != nullptr)
    {
        this->cannon->rotateCannon(win);
    }
}

void Machine::shoot(sf::RenderWindow &win)
{
    if(this->ballista != nullptr)
    {
        this->ballista->makeArrow(win);
    }
    if(this->trebuchette != nullptr)
    {
        this->trebuchette->makeRock(win);
    }
    if(this->cannon != nullptr)
    {
        this->cannon->makeBomb(win);
    }
}

void Machine::animate(sf::Time &elapsed, sf::FloatRect &bounds)
{
    if(this->ballista != nullptr)
    {
        if(this->ballista->arrowExists())
        {
            this->ballista->animate(elapsed, bounds);
        }
    }
    if(this->trebuchette != nullptr)
    {
        this->trebuchette->animate(elapsed, bounds);
    }
    if(this->cannon != nullptr)
    {
        this->cannon->animate(elapsed, bounds);
    }
}

sf::FloatRect Machine::getProjectileRect()
{
    if(this->ballista != nullptr)
    {
        return this->ballista->getRect();
    }
    if(this->trebuchette != nullptr)
    {
        return this->trebuchette->getRect();
    }
}

int Machine::getProjectileDamage()
{
    if(this->ballista != nullptr)
    {
        return this->ballista->getArrowDmg();
    }
    if(this->trebuchette != nullptr)
    {
        return this->trebuchette->getRockDmg();
    }
    if(this->cannon != nullptr)
    {
        return this->cannon->getBombDmg();
    }
}
float Machine::getRadius()
{
    if(this->cannon != nullptr)
    {
        return this->cannon->getBombRadius();
    }
}

void Machine::update(int &hpTaken)
{
    if(this->ballista != nullptr)
    {
       this->ballista->blockPierced();
    }
    if(this->trebuchette != nullptr)
    {
        this->trebuchette->rockDamaged(hpTaken);
    }

}

void Machine::update()
{
    if(this->cannon != nullptr)
    {
        this->cannon->bombHit();
    }
}

bool Machine::isCannon()
{
    if(this->cannon != nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Machine::switchToBallista()
{
    if(this->ballista == nullptr)
    {
        if(this->trebuchette != nullptr)
        {
            delete this->trebuchette;
            this->trebuchette = nullptr;
        }
        if(this->cannon != nullptr)
        {
            delete this->cannon;
            this->cannon = nullptr;
        }
        this->ballista = new Ballista();
    }
}

void Machine::switchToTrebuchette()
{
    if(this->trebuchette == nullptr)
    {
        if(this->ballista != nullptr)
        {
            delete this->ballista;
            this->ballista = nullptr;
        }
        if(this->cannon != nullptr)
        {
            delete this->cannon;
            this->cannon = nullptr;
        }
        this->trebuchette = new Trebuchette();
    }
}

void Machine::switchToCannon()
{
    if(this->cannon == nullptr)
    {
        if(this->trebuchette != nullptr)
        {
            delete this->trebuchette;
            this->trebuchette = nullptr;
        }
        if(this->ballista != nullptr)
        {
            delete this->ballista;
            this->ballista = nullptr;
        }
        this->cannon = new Cannon();
    }
}


//Ballista========================================================================

Ballista::Ballista()
{
    this->frontWheelTex.loadFromFile("textures/ballista/pieces/front-wheel.png");
    this->backWheelTex.loadFromFile("textures/ballista/pieces/backwheel.png");
    this->chassisTex.loadFromFile("textures/ballista/pieces/chassis.png");
    this->bowTex.loadFromFile("textures/ballista/pieces/bow.png");
    this->arrowTex.loadFromFile("textures/ballista/pieces/spear.png");
    this->frontWheelTex.setSmooth(true);
    this->backWheelTex.setSmooth(true);
    this->chassisTex.setSmooth(true);
    this->bowTex.setSmooth(true);
    this->arrowTex.setSmooth(true);

    sf::Vector2f position(80,650);

    this->backWheel.setTexture(this->backWheelTex);
    this->backWheel.setScale(0.2,0.2);
    this->backWheel.setPosition(position.x+10,position.y+70);

    this->frontWheel.setTexture(this->frontWheelTex);
    this->frontWheel.setScale(0.2,0.2);
    this->frontWheel.setPosition(position.x+110,position.y+55);

    this->chassis.setTexture(this->chassisTex);
    this->chassis.setScale(0.2,0.2);
    this->chassis.setPosition(position.x,position.y);
    this->chassis.rotate(-5);

    this->bow.setTexture(this->bowTex);
    this->bow.setScale(0.2,0.2);
    this->bow.setPosition(position.x+110,position.y+20);
    this->bow.setOrigin(600,180);

    this->arrow = nullptr;
}

Ballista::~Ballista()
{
    delete this->arrow;
}

void Ballista::display(sf::RenderWindow &window)
{
    window.draw(chassis);
    window.draw(frontWheel);
    window.draw(backWheel);
    if(arrowExists())
    {
        window.draw(*arrow);
    }
    window.draw(bow);
}

void Ballista::makeArrow(sf::RenderWindow &window)
{
    if(!arrowExists())
    {
        sf::Vector2f position(100,650);
        this->arrow = new Arrow(dmg[dmgLevel],piercing[piercingLevel]);
        this->arrow->setTexture(arrowTex);
        this->arrow->setScale(0.15,0.15);
        this->arrow->setPosition(position.x+100,position.y);
        this->arrow->setOrigin(sf::Vector2f(arrowTex.getSize().x,arrowTex.getSize().y/2));

        sf::Vector2f curPos = bow.getPosition();
        sf::Vector2f position2 = window.mapPixelToCoords(sf::Mouse::getPosition(window));

        const float PI = 3.14159265;

        float dx = position2.x - curPos.x;
        float dy = position2.y - curPos.y;

        float vectorLength = sqrt(dx*dx+dy*dy);

        dx = dx/vectorLength;
        dy = dy/vectorLength;

        this->arrow->setSpeed(dx*2000,dy*2000);

        dx = position2.x - curPos.x;
        dy = position2.y - curPos.y;

        float rotation = ((atan2(dy, dx)) * 180 / PI);

        arrow->setRotation(rotation);
    }

}

void Ballista::rotateBow(sf::RenderWindow &window)
{
    sf::Vector2f curPos = bow.getPosition();
    sf::Vector2i position = sf::Mouse::getPosition(window);

    const float PI = 3.14159265;

    float dx = position.x - curPos.x;
    float dy = position.y - curPos.y;

    float rotation = ((atan2(dy, dx)) * 180 / PI);

    bow.setRotation(rotation);
}

void Ballista::animate(sf::Time &elapsed, sf::FloatRect &bounds)
{
    this->arrow->animate(elapsed);
    if(this->arrow->getGlobalBounds().left > bounds.width
            or this->arrow->getGlobalBounds().top > bounds.height
            or this->arrow->getGlobalBounds().left + this->arrow->getGlobalBounds().width < bounds.left
            or this->arrow->getGlobalBounds().top + this->arrow->getGlobalBounds().height < bounds.top)
    {
        delete this->arrow;
        this->arrow = nullptr;
    }
    if(this->arrowExists() and this->arrow->piercing <= 0)
    {
        delete this->arrow;
        this->arrow = nullptr;
    }
}

bool Ballista::arrowExists()
{
    if(this->arrow != nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

sf::FloatRect Ballista::getRect()
{
    if(arrowExists())
    {
        return this->arrow->getGlobalBounds();
    }
}

int Ballista::getArrowDmg()
{
    return this->arrow->dmg;
}

void Ballista::blockPierced()
{
    this->arrow->piercing--;
}
//Trebuchette=======================================================================

Trebuchette::Trebuchette()
{
    this->frontWheelTex.loadFromFile("textures/trebuchette/pieces/wheel-front.png");
    this->backWheelTex.loadFromFile("textures/trebuchette/pieces/wheel-back.png");
    this->chassisTex.loadFromFile("textures/trebuchette/pieces/chassis.png");
    this->armTex.loadFromFile("textures/trebuchette/pieces/arm.png");
    this->rockTex.loadFromFile("textures/trebuchette/pieces/stone.png");
    this->frontWheelTex.setSmooth(true);
    this->backWheelTex.setSmooth(true);
    this->chassisTex.setSmooth(true);
    this->armTex.setSmooth(true);
    this->rockTex.setSmooth(true);

    sf::Vector2f position(100,650);

    this->backWheel.setTexture(this->backWheelTex);
    this->backWheel.setScale(-0.2,0.2);
    this->backWheel.setPosition(position.x+5,position.y+80);

    this->frontWheel.setTexture(this->frontWheelTex);
    this->frontWheel.setScale(-0.2,0.2);
    this->frontWheel.setPosition(position.x+130,position.y+65);

    this->chassis.setTexture(this->chassisTex);
    this->chassis.setScale(-0.2,0.2);
    this->chassis.setPosition(position.x+150,position.y);

    this->arm.setTexture(this->armTex);
    this->arm.setScale(-0.2,0.2);
    this->arm.setPosition(position.x+90,position.y+15);
    this->arm.setOrigin(380,200);

    this->rock = nullptr;
}
Trebuchette::~Trebuchette()
{

}

void Trebuchette::display(sf::RenderWindow &window)
{
    window.draw(arm);
    window.draw(chassis);
    window.draw(frontWheel);
    window.draw(backWheel);
    if(this->rockExists())
    {
        window.draw(*rock);
    }

}

void Trebuchette::makeRock(sf::RenderWindow &window)
{
    if(!rockExists())
    {
        sf::Vector2f position(100,650);
        this->rock = new Rock(dmg[dmgLevel]);
        this->rock->setTexture(rockTex);
        this->rock->setScale(0.2,0.2);
        this->rock->setPosition(position.x,position.y);
        this->rock->setOrigin(sf::Vector2f(rockTex.getSize().x,rockTex.getSize().y/2));

        sf::Vector2f curPos = arm.getPosition();
        sf::Vector2f position2 = window.mapPixelToCoords(sf::Mouse::getPosition(window));

        float dx = position2.x - curPos.x;
        float dy = position2.y - curPos.y;

        float vectorLength = sqrt(dx*dx+dy*dy);

        dx = dx/vectorLength;
        dy = dy/vectorLength;

        this->rock->setSpeed(dx*700,dy*1000);

        this->rockShot = true;
    }
}

void Trebuchette::animate(sf::Time &elapsed, sf::FloatRect &bounds)
{
    if(this->rock != nullptr)
    {
        this->rock->animate(elapsed);
        if(this->rock->getGlobalBounds().left > bounds.width
                or this->rock->getGlobalBounds().top > bounds.height
                or this->rock->getGlobalBounds().left + this->rock->getGlobalBounds().width < bounds.left)
        {
            delete this->rock;
            this->rock = nullptr;
            this->rockShot = false;
            this->arm.setRotation(0);
        }
        if(this->rockExists() and this->rock->dmg <= 0)
        {
            delete this->rock;
            this->rock = nullptr;
            this->rockShot = false;
            this->arm.setRotation(0);
        }
    }
    if(this->animationCounter <= 1 and this->rockShot == true)
    {
        this->arm.rotate(200*elapsed.asSeconds());
        this->animationCounter += elapsed.asSeconds();
    }
    else if(this->animationCounter > 1 and this->rockShot == true)
    {
        this->animationCounter = 0;
        this->rockShot = false;
        this->arm.setRotation(0);
    }
}

bool Trebuchette::rockExists()
{
    if(this->rock != nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

sf::FloatRect Trebuchette::getRect()
{
    if(rockExists())
    {
        return this->rock->getGlobalBounds();
    }
}

int Trebuchette::getRockDmg()
{
    return this->rock->dmg;
}

void Trebuchette::rockDamaged(int &hpTaken)
{
    this->rock->dmg -= hpTaken;
}

//Cannon======================================================================

Cannon::Cannon()
{
    this->cannonTex.loadFromFile("textures/cannon/parts/cannon.png");
    this->bodyTex.loadFromFile("textures/cannon/parts/body.png");
    this->wheelTex.loadFromFile("textures/cannon/parts/wheel.png");
    this->bombTex.loadFromFile("textures/cannon/parts/cannonball.png");
    this->cannonTex.setSmooth(true);
    this->bodyTex.setSmooth(true);
    this->wheelTex.setSmooth(true);
    this->bombTex.setSmooth(true);

    sf::Vector2f position(100,650);

    this->wheel.setTexture(this->wheelTex);
    this->wheel.setScale(0.3,0.3);
    this->wheel.setPosition(position.x+70, position.y+45);

    this->cannon.setTexture(this->cannonTex);
    this->cannon.setScale(0.3,0.3);
    this->cannon.setPosition(position.x+100, position.y+30);
    this->cannon.setOrigin(100,70);


    this->body.setTexture(this->bodyTex);
    this->body.setScale(0.3,0.3);
    this->body.setPosition(position.x, position.y);

    this->bomb = nullptr;
}

Cannon::~Cannon()
{

}

void Cannon::display(sf::RenderWindow &window)
{
    if(this->bombExists())
    {
        window.draw(*bomb);
    }
    window.draw(cannon);
    window.draw(body);
    window.draw(wheel);


}

void Cannon::makeBomb(sf::RenderWindow &window)
{
    if(!this->bombExists())
    {
        sf::Vector2f position(200,650);
        this->bomb = new Bomb();
        this->bomb->setTexture(bombTex);
        this->bomb->setScale(0.15,0.15);
        this->bomb->setPosition(position.x,position.y);

        sf::Vector2f curPos = cannon.getPosition();
        sf::Vector2f position2 = window.mapPixelToCoords(sf::Mouse::getPosition(window));

        float dx = position2.x - curPos.x;
        float dy = position2.y - curPos.y;

        float vectorLength = sqrt(dx*dx+dy*dy);

        dx = dx/vectorLength;
        dy = dy/vectorLength;

        this->bomb->setSpeed(dx*1000,dy*1000);
    }
}

void Cannon::animate(sf::Time &elapsed, sf::FloatRect &bounds)
{
    if(this->bomb != nullptr)
    {
        this->bomb->animate(elapsed);
        if(this->bomb->getGlobalBounds().left > bounds.width
                or this->bomb->getGlobalBounds().top > bounds.height
                or this->bomb->getGlobalBounds().left + this->bomb->getGlobalBounds().width < bounds.left)
        {
            delete this->bomb;
            this->bomb = nullptr;
        }
    }
}

void Cannon::rotateCannon(sf::RenderWindow &window)
{
    sf::Vector2f curPos = cannon.getPosition();
    sf::Vector2i position = sf::Mouse::getPosition(window);

    const float PI = 3.14159265;

    float dx = position.x - curPos.x;
    float dy = position.y - curPos.y;

    float rotation = ((atan2(dy, dx)) * 180 / PI);

    cannon.setRotation(rotation);
}

void Cannon::bombHit()
{
    delete this->bomb;
    this->bomb = nullptr;
}

bool Cannon::bombExists()
{
    if(this->bomb != nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

sf::FloatRect Cannon::getRect()
{
    if(bombExists())
    {
        return this->bomb->getGlobalBounds();
    }
}

int Cannon::getBombDmg()
{
    return this->dmg[dmgLevel];
}

int Cannon::getBombRadius()
{
    return this->radius[radiusLevel];
}
