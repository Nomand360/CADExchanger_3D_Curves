#include "CurvesManager.h"
#include <vector>
#include <iostream>


int main()
{
    std::vector<std::shared_ptr<Curve>> curves;
    std::vector<std::shared_ptr<Circle>> circles;
    CurvesManager manager;
    manager.createCurvesContainer(curves);
    std::cout << curves.size() << std::endl;
    manager.showCurvesContainer(curves);
    manager.createCirclesContainer(curves, circles);
    std::cout << circles.size() << std::endl;
    manager.showCircleContainer(circles);
    manager.showCurvesContainerWithParam(curves, M_PI / 4.f);
    return 0;
}
