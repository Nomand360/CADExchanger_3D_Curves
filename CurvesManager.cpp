#include "CurvesManager.h"
#include <algorithm>
#include <iostream>

void CurvesManager::createCurvesContainer(std::vector<std::shared_ptr<Curve> > &curves)
{
    auto circ = std::make_shared<CreateCircle>();
    auto eclip = std::make_shared<CreateElipse>();;
    auto helix = std::make_shared<CreateHelix>();
    std::vector<std::shared_ptr<Creator>> factory;
    factory.emplace_back(circ);
    factory.emplace_back(eclip);
    factory.emplace_back(helix);
    int size = curve_size(gen);
    for(int i = 0; i < size; i++){
        curves.emplace_back(factory.at(curve_types(gen))->CreateCurve());
    }
}

void CurvesManager::createCirclesContainer(std::vector<std::shared_ptr<Curve> > &curves, std::vector<std::shared_ptr<Circle> > &circles)
{
    for(const auto &curv : curves){
        if(curv->getName() == "Circle"){
            auto circle = std::dynamic_pointer_cast<Circle>(curv);
            circles.emplace_back(circle);
        }
    }
}

void CurvesManager::showCurvesContainerWithParam(const std::vector<std::shared_ptr<Curve> > &curves, float param)
{
    for(const auto &curve : curves){
        std::cout << curve->getName() << ": " << " point: " << curve->getPoint(param) << " derivative: " << curve->getDerivative(param) << std::endl;
    }
}

void CurvesManager::showCurvesContainer(const std::vector<std::shared_ptr<Curve> > &curves)
{
    for(const auto &curve : curves){
        std::cout << curve->getName() << ": " << curve->getPosition() << std::endl;
    }
}

void CurvesManager::showCircleContainer(const std::vector<std::shared_ptr<Circle> > &circles)
{
    for(const auto &circle : circles){
        std::cout << circle->getName() << ": " << circle->getPosition() << " radius: " << circle->getRadius() << std::endl;
    }
}

void CurvesManager::sortCircleContainer(std::vector<std::shared_ptr<Circle> > &circles)
{
    std::sort(circles.begin(), circles.end(), [](std::shared_ptr<Circle> &l, std::shared_ptr<Circle> &r){ return l->getRadius() < r->getRadius();});
}

float CurvesManager::getTotalSumOfRadii(const std::vector<std::shared_ptr<Circle> > &circles)
{
    float sum = 0.f;
    for(const auto &circle : circles){
        sum += circle->getRadius();
    }
    return sum;
}
