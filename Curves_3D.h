#ifndef CURVES_3D_H
#define CURVES_3D_H
#include "Vec3.h"
#include <string>

class Curve
{
public:
    Curve(){}
    Curve(float xPos, float yPos, float zPos) : position(xPos, yPos, zPos){}
    Vec3f getPosition() const {return position;}
    std::string getName() const {return name;}
    virtual ~Curve() = default;
    virtual Vec3f getPoint(float t) = 0;
    virtual Vec3f getDerivative(float t) = 0;
protected:
    Vec3f position;
    std::string name;
};

class Circle : public Curve
{
public:
    explicit Circle(float rad) : radius(rad){
        name = "Circle";
    }
    Circle(float xPos, float yPos, float _radius) : Curve(xPos, yPos, 0.f), radius(_radius){
        name = "Circle";
    }
    Vec3f getPoint(float t) override;
    Vec3f getDerivative(float t) override;
    float getRadius() const {return radius;}
private:
    float radius;

};

class Elipse : public Curve
{
public:
    explicit Elipse(float xRad, float yRad) : xRadius(xRad), yRadius(yRad){
        name = "Elipse";
    }
    Elipse(float xPos, float yPos, float xRad, float yRad) : Curve(xPos, yPos, 0.f), xRadius(xRad), yRadius(yRad){
        name = "Elipse";
    }
    Vec3f getPoint(float t) override;
    Vec3f getDerivative(float t) override;
private:
    float xRadius;
    float yRadius;
};

class Helixes3D : public Curve
{
public:
    Helixes3D(float _radius, float _step) : radius(_radius), step(_step){
        name = "Helixes3D";
    }
    Helixes3D(float xPos, float yPos, float zPos, float _radius, float _step) : Curve(xPos, yPos, zPos), radius(_radius), step(_step){
        name = "Helixes3D";
    }
    Vec3f getPoint(float t) override;
    Vec3f getDerivative(float t) override;
private:
    float radius;
    float step;
};


#endif // CURVES_3D_H
