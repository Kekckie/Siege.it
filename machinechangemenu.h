#ifndef MACHINECHANGEMENU_H
#define MACHINECHANGEMENU_H

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

class MachineChangeMenu
{
private:
    sf::Texture ballistaIconTex;
    sf::Texture trebuchetteIconTex;
    sf::Texture cannonIconTex;
    sf::Sprite menuBack;
    sf::Sprite ballistaIcon;
    sf::Sprite trebuchetteIcon;
    sf::Sprite cannonIcon;
public:
    MachineChangeMenu(sf::Texture &menuBack);
    ~MachineChangeMenu();
    void display(sf::RenderWindow &window);
    sf::FloatRect getBallistaButton();
    sf::FloatRect getTrebuchetteButton();
    sf::FloatRect getCannonButton();
};

#endif // MACHINECHANGEMENU_H
