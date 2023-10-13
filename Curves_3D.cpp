#include "Curves_3D.h"
#include <math.h>

Vec3f Circle::getPoint(float t)
{
    return Vec3f(getPosition().x + radius * cos(t), getPosition().y + radius * sin(t), getPosition().z);
}

Vec3f Circle::getDerivative(float t)
{
    return Vec3f(radius * -sin(t), radius * cos(t), getPosition().z);
}

Vec3f Elipse::getPoint(float t)
{
    return Vec3f(getPosition().x + xRadius * cos(t), getPosition().y + yRadius * sin(t), getPosition().z);
}

Vec3f Elipse::getDerivative(float t)
{
    return Vec3f(xRadius * -sin(t), yRadius * cos(t), getPosition().z);
}

Vec3f Helixes3D::getPoint(float t)
{
    return Vec3f(getPosition().x + radius * cos(t), getPosition().y + radius * sin(t), getPosition().z + step / (2 * M_PI) * t);
}

Vec3f Helixes3D::getDerivative(float t)
{
    return Vec3f(radius * -sin(t), radius * cos(t), step / (2 * M_PI));
}
