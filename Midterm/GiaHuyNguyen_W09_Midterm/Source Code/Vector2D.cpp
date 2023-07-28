#include "Vector2D.h"
#include <iostream>
#include <string>
#include <math.h>

using namespace std;
// 2D vector constructor; default is unit vector î
Vector2D::Vector2D(double aX, double aY)
{
    fX = aX;
    fY = aY;
}
// getters & setters for x and y coordinates
void Vector2D::setX(double aX)
{
    fX = aX;
}
double Vector2D::getX() const
{
    return fX;
}
void Vector2D::setY(double aY)
{
    fY = aY;
}
double Vector2D::getY() const
{
    return fY;
}
// 2D vector addition: this + aRHS; returns a fresh 2D vector
Vector2D Vector2D::operator+(const Vector2D &aRHS) const
{
    return {fX + aRHS.fX, fY + aRHS.fY};
}
// 2D vector subtraction: this - aRHS; returns a fresh 2D vector
Vector2D Vector2D::operator-(const Vector2D &aRHS) const
{
    return {fX - aRHS.fX, fY - aRHS.fY};
}
// Length (or magnitude) of a 2D vector
double Vector2D::magnitude() const
{
    return sqrt(fX * fX + fY * fY);
}
// Direction (angle) of 2D vector
// The angle is the tangent of y divided by x (hint: atan2)
double Vector2D::direction() const
{
    return atan2(fY, fX);
}
// Inner product (scalar product) of two 2D vectors
// Does not require angle between vectors
double Vector2D::dot(const Vector2D &aRHS) const
{
    return fX * aRHS.fX + fY * aRHS.fY;
}
// In 2D, the cross product of two 2D vectors is
// the determinate of the matrix
//
// | x1 x2 |
// det | | = x1*y2 - x2*y1
// | y1 y2 |
//
double Vector2D::cross(const Vector2D &aRHS) const
{
    return fX * aRHS.fY - fY * aRHS.fX;
}
// Angle between two 2D vectors
// The function must properly handle null vectors = [0,0]
// and return an angle consistent with the dot product.
double Vector2D::angleBetween(const Vector2D &aRHS) const
{
    double dot = fX * aRHS.fX + fY * aRHS.fY;
    double mag = magnitude() * aRHS.magnitude();
    if (mag == 0.0)
    {
        return 0.0;
    }
    return acos(dot / mag);
}
// I/O for 2D vectors
std::ostream &operator<<(std::ostream &aOutStream, const Vector2D &aObject)
{
    aOutStream << "[" << aObject.fX << ", " << aObject.fY << "]";
    return aOutStream;
}
std::istream &operator>>(std::istream &aInStream, Vector2D &aObject)
{
    aInStream >> aObject.fX >> aObject.fY;
    return aInStream;
}




