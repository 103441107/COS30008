#include "Point2D.h"
#include <iostream>
#include <string>
#include <math.h>
#include <cmath>
#define M_PI 3.14159265358979323846

using namespace std;
static const Point2D gCoordinateOrigin = Point2D("origin", 0, 0);
// Constructor
Point2D::Point2D()
{
    fId = "";
    fPosition = Vector2D(0, 0);
    fOrigin = &gCoordinateOrigin;
}
Point2D::Point2D(const std::string &aId, double aX, double aY)
{
    fId = aId;
    fPosition = Vector2D(aX, aY);
    fOrigin = &gCoordinateOrigin;
}
Point2D::Point2D(std::istream &aIStream)
{
    aIStream >> fId >> fPosition;
    fOrigin = &gCoordinateOrigin;
}
// getters & setters
const std::string &Point2D::getId() const
{
    return fId;
}
void Point2D::setX(const double &aX)
{
    fPosition.setX(aX);
}
const double Point2D::getX() const
{
    return fPosition.getX();
}
void Point2D::setY(const double &aY)
{
    fPosition.setY(aY);
}
const double Point2D::getY() const
{
    return fPosition.getY();
}
void Point2D::setOrigin(const Point2D &aPoint)
{
    fOrigin = &aPoint;
}
const Point2D &Point2D::getOrigin() const
{
    return *fOrigin;
}
// Direction (angle) of point w.r.t. aOther
double Point2D::directionTo(const Point2D &aOther) const
{
    Vector2D v = aOther.fPosition - fPosition;
    return v.direction();
}
// Length ( or magnitude) of point w.r.t. aOther
double Point2D::magnitudeTo(const Point2D &aOther) const
{
    Vector2D v = aOther.fPosition - fPosition;
    return v.magnitude();
}
// 2D vector this – aRHS
Vector2D Point2D::operator-(const Point2D &aRHS) const
{
    return fPosition - aRHS.fPosition;
}
// Direction (angle) of point w. r.t. origin
double Point2D::direction() const
{
    return fOrigin->directionTo(*this);
}
// Length (or magnitude) of point w.r.t. origin
double Point2D::magnitude() const
{
    return fOrigin->magnitudeTo(*this);
}
// Are this point and aOther on the same line segment?
bool Point2D::isCollinear(const Point2D &aOther) const
{
    double d = directionTo(aOther);
    return (abs(d) <= 1e-4 || abs(d - M_PI) <= 1e-4);
}
// Does line segment this-aP2 make a right turn at this point?
bool Point2D::isClockwise(const Point2D &aP0, const Point2D &aP2) const
{
    double val = (fPosition.getY() - aP0.fPosition.getY()) * (aP2.fPosition.getX() - fPosition.getX()) -
                 (fPosition.getX() - aP0.fPosition.getX()) * (aP2.fPosition.getY() - fPosition.getY());
    if (val < 0)
    {
        return false;
    }
    return true;
}
//// Is this' y-coordinate less than aRHS's y-coordinate?
// If there is a tie, this' x-coordinate less than aRHS's x-coordinate?
bool Point2D::operator<(const Point2D &aRHS) const
{
    if (fPosition.getY() < aRHS.fPosition.getY())
    {
        return true;
    }
    else if (fPosition.getY() == aRHS.fPosition.getY())
    {
        if (fPosition.getX() < aRHS.fPosition.getX())
        {
            return true;
        }
    }
    return false;
}
// I/O for 2D points
std::ostream &operator<<(std::ostream &aOStream, const Point2D &aObject)
{
    aOStream << aObject.fId << ": (" << aObject.fPosition.getX() << ", "
             << aObject.fPosition.getY() << ")";
    return aOStream;
}
std::istream &operator>>(std::istream &aIStream, Point2D &aObject)
{
    aIStream >> aObject.fId >> aObject.fPosition;
    return aIStream;
}
