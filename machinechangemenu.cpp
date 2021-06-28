#include "machinechangemenu.h"

MachineChangeMenu::MachineChangeMenu(sf::Texture &menuBack)
{
    this->menuBack.setTexture(menuBack);
    this->ballistaIconTex.loadFromFile("textures/ballista/ballista.png");
    this->cannonIconTex.loadFromFile("textures/cannon/cannon.png");
    this->trebuchetteIconTex.loadFromFile("textures/trebuchette/loaded.png");

    this->ballistaIcon.setTexture(ballistaIconTex);
    this->cannonIcon.setTexture(cannonIconTex);
    this->trebuchetteIcon.setTexture(trebuchetteIconTex);

    this->menuBack.setScale(0.95,0.15);
    this->ballistaIcon.setScale(0.1,0.1);
    this->trebuchetteIcon.setScale(0.05,0.05);
    this->cannonIcon.setScale(0.20,0.20);

    this->menuBack.setPosition(10,10);
    this->ballistaIcon.setPosition(35,20);
    this->trebuchetteIcon.setPosition(135,20);
    this->cannonIcon.setPosition(255,20);
}

MachineChangeMenu::~MachineChangeMenu()
{

}

void MachineChangeMenu::display(sf::RenderWindow &window)
{
    window.draw(menuBack);
    window.draw(ballistaIcon);
    window.draw(cannonIcon);
    window.draw(trebuchetteIcon);
}

sf::FloatRect MachineChangeMenu::getBallistaButton()
{
    return this->ballistaIcon.getGlobalBounds();
}

sf::FloatRect MachineChangeMenu::getTrebuchetteButton()
{
    return this->trebuchetteIcon.getGlobalBounds();
}

sf::FloatRect MachineChangeMenu::getCannonButton()
{
    return this->cannonIcon.getGlobalBounds();
}
