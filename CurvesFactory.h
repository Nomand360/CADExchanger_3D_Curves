#ifndef CURVESFACTORY_H
#define CURVESFACTORY_H
#include "Curves_3D.h"
#include <memory>
#include <random>

enum Curves{
    circle,
    elipse,
    helix
};

class Creator
{
public:
    virtual ~Creator(){};
    virtual std::shared_ptr<Curve> CreateCurve() = 0;
protected:
    std::random_device rd_;
    std::mt19937 gen_{rd_()};
    std::uniform_real_distribution<float> x_y_pos{-10, 10};
    std::uniform_real_distribution<float> dis_positive{0, 10};
};

class CreateCircle : public Creator
{
public:
    std::shared_ptr<Curve> CreateCurve() override{
        return std::make_shared<Circle>(x_y_pos(gen_), x_y_pos(gen_), dis_positive(gen_));
    }
};

class CreateElipse : public Creator
{
public:
    std::shared_ptr<Curve> CreateCurve() override{
        return std::make_shared<Elipse>(x_y_pos(gen_), x_y_pos(gen_), dis_positive(gen_), dis_positive(gen_));
    }
};

class CreateHelix : public Creator
{
public:
    std::shared_ptr<Curve> CreateCurve() override{
        return std::make_shared<Helixes3D>(x_y_pos(gen_), x_y_pos(gen_), x_y_pos(gen_), dis_positive(gen_), dis_positive(gen_));
    }
};

#endif // CURVESFACTORY_H
