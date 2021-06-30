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
    //machine levels
    int ballistaDmgLevel = 0;
    int ballistaPiercingLevel = 0;
    int trebuchetteDmgLevel = 0;
    int cannonDmgLevel = 0;
    int cannonRadiusLevel = 0;


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
    bool isBallista();
    int getDamageLevels();
    int getSecondStatLevels();
    int getSecondStatValues();
    int getDamageUpgradeCost();
    int getSecondStatUpgradeCost();
    //switchers
    void switchToBallista();
    void switchToTrebuchette();
    void switchToCannon();
    //upgraders
    void upgradeDmgLevel();
    void upgradeSecondStat();
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
    std::vector<int> dmgCosts = {10,100,500,700,1000,2000,4000,10000,20000,60000};
    std::vector<int> piercing = {1,2,3,4,5,6,7,8,9,12};
    std::vector<int> piercingCosts = {10,100,500,700,1000,2000,4000,10000,20000,60000};

public:
    Ballista(int dmgLevel, int piercingLevel);
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
    int getDmgLevel();
    int getPiercingLevel();
    int getPiercingValue();
    int getDamageUpgradeCost();
    int getPiercingUpgradeCost();
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
    std::vector<int> dmgCosts = {10,100,500,700,1000,2000,4000,10000,20000,60000};
    float animationCounter = 0;
    bool rockShot = false;
public:
    Trebuchette(int dmgLevel);
    ~Trebuchette();
    void display(sf::RenderWindow &window);
    void makeRock(sf::RenderWindow &window);
    void animate(sf::Time &elapsed, sf::FloatRect &bounds);
    //accessors
    bool rockExists();
    sf::FloatRect getRect();
    int getRockDmg();
    void rockDamaged(int &hpTaken);
    int getDmgLevel();
    int getDamageUpgradeCost();
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
    int dmgLevel = 9;
    int radiusLevel = 0;
    std::vector<int> radius = {10,20,30,40,50,70,90,120,150,200};
    std::vector<int> dmgCosts = {10,100,500,700,1000,2000,4000,10000,20000,60000};
    std::vector<int> dmg = {1,2,4,8,16,32,64,128,256,512};
    std::vector<int> radiusCosts = {10,100,500,700,1000,2000,4000,10000,20000,60000};
public:
    Cannon(int dmgLevel, int radiusLevel);
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
    int getDmgLevel();
    int getRadiusLevel();
    int getRadiusValue();
    int getDamageUpgradeCost();
    int getRadiusUpgradeCost();
};

#endif // MACHINE_H
