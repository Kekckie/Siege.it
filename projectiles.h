#ifndef ARROW_H
#define ARROW_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <functional>
#include <stdlib.h>
#include <string>
#include <random>
#include <iostream>
#include <memory>
#include <vector>
#include <ctime>

class Arrow : public sf::Sprite
{
private:
    float arrowSpeed_x, arrowSpeed_y;
public:
    int dmg, piercing;
    Arrow(int &dmg, int &piercing);
    ~Arrow();
    void animate(sf::Time &elapsed);
    void setSpeed(float x, float y);
};

class Rock : public sf::Sprite
{
private:
    float rockSpeed_x, rockSpeed_y;
public:
    int dmg;
    Rock(int &dmg);
    ~Rock();
    void animate(sf::Time &elapsed);
    void setSpeed(float x, float y);
};

class Bomb : public sf::Sprite
{
private:
    float bombSpeed_x, bombSpeed_y;
public:
    Bomb();
    ~Bomb();
    void animate(sf::Time &elapsed);
    void setSpeed(float x, float y);
};

#endif // ARROW_H
