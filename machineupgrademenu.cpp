#include "machineupgrademenu.h"

MachineUpgradeMenu::MachineUpgradeMenu(sf::Texture &menuBack, sf::Texture &plusTexture)
{
    this->font.loadFromFile("c:\\windows\\fonts\\arial.ttf");
    //menuBack config
    this->menuBack.setTexture(menuBack);
    this->menuBack.rotate(270);
    this->menuBack.setPosition(11,250);
    this->menuBack.setScale(0.3,0.8);
    //menu text
    this->menuText.setFont(this->font);
    this->menuText.setPosition(34,135);
    this->menuText.setFillColor(sf::Color::White);
    this->menuText.setCharacterSize(20);
    this->menuText.setString("MACHINE STATS AND UPGRADES");
    //first stat config
    this->firstPlus.setTexture(plusTexture);
    this->firstPlus.setPosition(28,170);
    this->firstPlus.setScale(0.025,0.025);
    this->firstStatInfo.setFont(this->font);
    this->firstStatInfo.setFillColor(sf::Color::White);
    this->firstStatInfo.setCharacterSize(14);
    this->firstStatData.setFont(this->font);
    this->firstStatData.setFillColor(sf::Color::White);
    this->firstStatData.setCharacterSize(14);


    //second stat config
    this->secondPlus.setTexture(plusTexture);
    this->secondPlus.setPosition(28,210);
    this->secondPlus.setScale(0.025,0.025);
    this->secondStatInfo.setFont(this->font);
    this->secondStatInfo.setFillColor(sf::Color::White);
    this->secondStatInfo.setCharacterSize(14);
    this->secondStatData.setFont(this->font);
    this->secondStatData.setFillColor(sf::Color::White);
    this->secondStatData.setCharacterSize(14);

    this->firstCost.setFont(this->font);
    this->firstCost.setFillColor(sf::Color::White);
    this->firstCost.setCharacterSize(14);
    this->secondCost.setFont(this->font);
    this->secondCost.setFillColor(sf::Color::White);
    this->secondCost.setCharacterSize(14);




}

MachineUpgradeMenu::~MachineUpgradeMenu()
{

}

void MachineUpgradeMenu::updateFirstInfo(std::string currentLevel, std::string currentDmg, std::string currentCost)
{
    this->firstStatInfo.setString("Upgrade damage: " + currentLevel + "/10");
    this->firstStatInfo.setPosition(60,172);
    this->firstStatData.setString("Current damage: " + currentDmg);
    this->firstStatData.setPosition(240,172);
    this->firstCost.setPosition(395,172);
    if(currentLevel != "10")
    {
        this->firstCost.setString("Cost: " + currentCost);
    }
    else
    {
        this->firstCost.setString("Cost: -------");
    }

}

void MachineUpgradeMenu::updateSecondInfoBallista(std::string currentLevel, std::string currentPiercing, std::string currentCost)
{
    this->secondStatInfo.setString("Upgrade piercing: " + currentLevel + "/10");
    this->secondStatInfo.setPosition(60,210);
    this->secondStatData.setString("Current piercing: " + currentPiercing);
    this->secondStatData.setPosition(240,210);
    this->secondCost.setPosition(395,210);
    if(currentLevel != "10")
    {
        this->secondCost.setString("Cost: " + currentCost);
    }
    else
    {
        this->secondCost.setString("Cost: -------");
    }
}

void MachineUpgradeMenu::updateSecondInfoCannon(std::string currentLevel, std::string currentRadius, std::string currentCost)
{
    this->secondStatInfo.setString("Upgrade radius: " + currentLevel + "/10");
    this->secondStatInfo.setPosition(60,210);
    this->secondStatData.setString("Current radius: " + currentRadius);
    this->secondStatData.setPosition(240,210);
    this->secondCost.setPosition(395,210);
    if(currentLevel != "10")
    {
        this->secondCost.setString("Cost: " + currentCost);
    }
    else
    {
        this->secondCost.setString("Cost: -------");
    }
}

void MachineUpgradeMenu::secondStatSwitch(bool v)
{
    this->isThereSecondStat = v;
}

void MachineUpgradeMenu::display(sf::RenderWindow &window)
{
    window.draw(menuBack);
    window.draw(firstPlus);
    window.draw(firstStatInfo);
    window.draw(firstStatData);
    window.draw(menuText);
    window.draw(firstCost);
    if(isThereSecondStat)
    {
        window.draw(secondPlus);
        window.draw(secondStatInfo);
        window.draw(secondStatData);
        window.draw(secondCost);
    }
}

sf::FloatRect MachineUpgradeMenu::getFirstPlus()
{
    return this->firstPlus.getGlobalBounds();
}

sf::FloatRect MachineUpgradeMenu::getSecondPlus()
{
    return this->secondPlus.getGlobalBounds();
}
