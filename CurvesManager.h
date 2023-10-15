#ifndef CURVESMANAGER_H
#define CURVESMANAGER_H
#include <memory>
#include "CurvesFactory.h"
#include <vector>
#include <memory.h>
#include "Curves_3D.h"

class CurvesManager
{
public:
    void createCurvesContainer(std::vector<std::shared_ptr<Curve>> &curves);
    void createCirclesContainer(std::vector<std::shared_ptr<Curve>> &curves, std::vector<std::shared_ptr<Circle> > &circles);
    void showCurvesContainerWithParam(const std::vector<std::shared_ptr<Curve> > &curves, float param);
    void showCurvesContainer(const std::vector<std::shared_ptr<Curve> > &curves);
    void showCircleContainer(const std::vector<std::shared_ptr<Circle> > &circles);
    void sortCircleContainer(std::vector<std::shared_ptr<Circle> > &circles);
    float getTotalSumOfRadii(const std::vector<std::shared_ptr<Circle> > &circles);
private:
    std::random_device random;
    std::mt19937 gen{random()};
    std::uniform_int_distribution<int> curve_types{circle, helix};
    std::uniform_int_distribution<int> curve_size{10, 40};
};

#endif // CURVESMANAGER_H
