#ifndef MACHINE_H
#define MACHINE_H
class Ballista;
class Trebuchette;
class Cannon;

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
#include "projectiles.h"

class Machine
{
private:
    //Machine pointers
    Ballista *ballista;
    Trebuchette *trebuchette;
    Cannon *cannon;


public:
    Machine();
    virtual ~Machine();
    void display(sf::RenderWindow &window);
    void makeBallista();
    void makeTrebuchette();
    void makeCannon();
    void rotateMachine(sf::RenderWindow &win);
    void shoot(sf::RenderWindow &win);
    void animate(sf::Time &elapsed, sf::FloatRect &bounds);
    sf::FloatRect getProjectileRect();
    int getProjectileDamage();
    float getRadius();
    void update(int &hpTaken);
    void update();
    bool isCannon();
    //switchers
    void switchToBallista();
    void switchToTrebuchette();
    void switchToCannon();
};

//==========================================================================

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
    Arrow *arrow;
    //variables
    int dmgLevel = 0;
    int piercingLevel = 0;
    std::vector<int> dmg = {1,2,4,8,16,32,64,128,256,512};
    std::vector<int> piercing = {1,2,3,4,5,6,7,8,9,12};

public:
    Ballista();
    virtual ~Ballista();
    void display(sf::RenderWindow &window);
    void makeArrow(sf::RenderWindow &window);
    void rotateBow(sf::RenderWindow &window);
    void animate(sf::Time &elapsed, sf::FloatRect &bounds);
    //accessors
    bool arrowExists();
    sf::FloatRect getRect();
    int getArrowDmg();
    void blockPierced();
};

//=========================================================================
class Trebuchette
{
private:
    //Textures
    sf::Texture chassisTex;
    sf::Texture backWheelTex;
    sf::Texture frontWheelTex;
    sf::Texture armTex;
    sf::Texture rockTex;
    //static elements
    sf::Sprite frontWheel;
    sf::Sprite backWheel;
    sf::Sprite chassis;
    //moving elements
    sf::Sprite arm;
    Rock *rock;
    //variables
    int dmgLevel = 0;
    std::vector<int> dmg = {2,8,32,64,128,512,1024,2048,4096,10000};
    float animationCounter = 0;
    bool rockShot = false;
public:
    Trebuchette();
    ~Trebuchette();
    void display(sf::RenderWindow &window);
    void makeRock(sf::RenderWindow &window);
    void animate(sf::Time &elapsed, sf::FloatRect &bounds);
    //accessors
    bool rockExists();
    sf::FloatRect getRect();
    int getRockDmg();
    void rockDamaged(int &hpTaken);

};
//============================================================================
class Cannon
{
private:
    //textures
    sf::Texture bodyTex;
    sf::Texture cannonTex;
    sf::Texture wheelTex;
    sf::Texture bombTex;
    //static elements
    sf::Sprite wheel;
    sf::Sprite body;
    //moving elements
    sf::Sprite cannon;
    Bomb *bomb;
    //variables
    int dmgLevel = 0;
    int radiusLevel = 0;
    std::vector<int> radius = {50,100,150,200,250,300,350,400,450,500};
    std::vector<int> dmg = {1,2,3,4,5,6,7,8,9,10};
public:
    Cannon();
    ~Cannon();
    void display(sf::RenderWindow &window);
    void makeBomb(sf::RenderWindow &window);
    void animate(sf::Time &elapsed, sf::FloatRect &bounds);
    void rotateCannon(sf::RenderWindow &window);
    void bombHit();
    //accessors
    bool bombExists();
    sf::FloatRect getRect();
    int getBombDmg();
    int getBombRadius();


};

#endif // MACHINE_H
