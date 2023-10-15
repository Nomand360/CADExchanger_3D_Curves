#ifndef MENU_H
#define MENU_H
#include <vector>
#include <memory>

class Curve;
class Circle;
class CurvesManager;

class Menu
{
public:
    Menu();
    void mainMenu();
    int selectMenuItem();
private:
    int getNumber(int min, int max);
    std::vector<std::shared_ptr<Curve>> curves;
    std::vector<std::shared_ptr<Circle>> circles;
    std::shared_ptr<CurvesManager> manager;

};

#endif // MENU_H
