#include "Menu.h"
#include "CurvesManager.h"
#include <iostream>
#include <iomanip>

Menu::Menu()
{
    manager = std::make_shared<CurvesManager>();
    manager->createCurvesContainer(this->curves);
    manager->createCirclesContainer(this->curves, this->circles);
}

void Menu::mainMenu()
{
    bool done = false;
    std::cout << std::fixed<< std::setprecision(2);
    while(!done){
        switch(selectMenuItem()){
        case 1:{
            manager->showCurvesContainer(this->curves);
            break;
        }
        case 2:{
            manager->showCircleContainer(this->circles);
            break;
        }
        case 3:{
            manager->showCurvesContainerWithParam(this->curves, M_PI / 4.f);
            break;
        }
        case 4:{
            manager->sortCircleContainer(this->circles);
            std::cout << "Container sorted!" << std::endl;
            break;
        }
        case 5:{
            std::cout << "The total sum of radii: " << manager->getTotalSumOfRadii(this->circles) << std::endl;
            break;
        }
        case 6:{
            std::cout << "The nd of work!" << std::endl;
            done = true;
            break;
        }
        }
    }
}

int Menu::selectMenuItem()
{
    std::cout << "==========Main Menu==========" << std::endl;
    std::cout << "1 - Show curves container." << std::endl;
    std::cout << "2 - Show circles container(contain circles from first curves container)" << std::endl;
    std::cout << "3 - Print coordinates of points and derivatives of all curves in the container at t=PI/4" << std::endl;
    std::cout << "4 - Sort container of circles" << std::endl;
    std::cout << "5 - Compute the total sum of radii of circles" << std::endl;
    std::cout << "6 - Exit" << std::endl;
    return getNumber(1, 6);
}

int Menu::getNumber(int min, int max)
{
    int number = min - 1;
    while(true){
        std::cin >> number;
        if((number >= min) && (number <= max) && (std::cin.peek() == '\n')){
            break;
        }
        else{
            std::cout << "Please re-enter (expecting a number from " << min << " to " << max << "):" << std::endl;
            std::cin.clear();
            while(std::cin.get() != '\n'){}
        }
    }
    return number;
}
