#include "machine.h"
//Machine
Machine::Machine()
{
    this->ballista = nullptr;
}

Machine::~Machine()
{
    delete this->ballista;
}

void Machine::display(sf::RenderWindow &window)
{
    if(this->ballista != nullptr)
    {
        this->ballista->display(window);
    }
}

void Machine::makeBallista()
{
    this->ballista = new Ballista();
}

void Machine::rotateMachine(sf::RenderWindow &win)
{
    if(this->ballista != nullptr)
    {
        this->ballista->rotateBow(win);
    }
}
//Ballista

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

    sf::Vector2f position(100,650);

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
    makeArrow(position);


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
    if(this->arrow != nullptr)
    {
        window.draw(*arrow);
    }
    window.draw(bow);
}

void Ballista::makeArrow(sf::Vector2f position)
{
    this->arrow = new sf::Sprite();
    this->arrow->setTexture(this->arrowTex);
    this->arrow->setScale(0.2,0.2);
    this->arrow->setPosition(position.x+110,position.y+20);
    this->arrow->setOrigin(300,145);
}

void Ballista::rotateBow(sf::RenderWindow &win)
{
        sf::Vector2f curPos = bow.getPosition();
        sf::Vector2i position = sf::Mouse::getPosition(win);

        const float PI = 3.14159265;

        float dx = curPos.x - position.x;
        float dy = curPos.y - position.y;

        float rotation = ((atan2(dy, dx)) * 180 / PI) -180;

        bow.setRotation(rotation);
        if(this->arrow != nullptr)
        {
            this->arrow->setRotation(rotation);
        }
}
