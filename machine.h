#ifndef MACHINE_H
#define MACHINE_H
class Ballista;
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

class Machine
{
private:
    //Machine pointers
    Ballista *ballista;


public:
    Machine();
    virtual ~Machine();
    void display(sf::RenderWindow &window);
    void makeBallista();
    void rotateMachine(sf::RenderWindow &win);
};

class Ballista
{
private:
    //textures;
    sf::Texture frontWheelTex;
    sf::Texture backWheelTex;
    sf::Texture chassisTex;
    sf::Texture bowTex;
    sf::Texture arrowTex;
    //static elements
    sf::Sprite frontWheel;
    sf::Sprite backWheel;
    sf::Sprite chassis;
    //moving elements
    sf::Sprite bow;
    sf::Sprite *arrow;

public:
    Ballista();
    virtual ~Ballista();
    void display(sf::RenderWindow &window);
    void makeArrow(sf::Vector2f position);
    void rotateBow(sf::RenderWindow &win);
};

#endif // MACHINE_H
