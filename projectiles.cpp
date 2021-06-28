#include "projectiles.h"

Arrow::Arrow(int &dmg, int &piercing)
{
    this->piercing = piercing;
    this->dmg = dmg;
}

Arrow::~Arrow()
{

}

void Arrow::animate(sf::Time &elapsed)
{
    move(arrowSpeed_x*elapsed.asSeconds(),arrowSpeed_y*elapsed.asSeconds());
}

void Arrow::setSpeed(float x, float y)
{
    this->arrowSpeed_x = x;
    this->arrowSpeed_y = y;
}

Rock::Rock(int &dmg)
{
    this->dmg = dmg;
}

Rock::~Rock()
{

}

void Rock::animate(sf::Time &elapsed)
{
    move(rockSpeed_x*elapsed.asSeconds(),rockSpeed_y*elapsed.asSeconds());
    rockSpeed_y += elapsed.asSeconds()*500;
}

void Rock::setSpeed(float x, float y)
{
    this->rockSpeed_x = x;
    this->rockSpeed_y = y;
}

Bomb::Bomb()
{

}

Bomb::~Bomb()
{

}

void Bomb::animate(sf::Time &elapsed)
{
    move(bombSpeed_x*elapsed.asSeconds(),bombSpeed_y*elapsed.asSeconds());
    bombSpeed_y += elapsed.asSeconds()*400;
}

void Bomb::setSpeed(float x, float y)
{
    this->bombSpeed_x = x;
    this->bombSpeed_y = y;
}
