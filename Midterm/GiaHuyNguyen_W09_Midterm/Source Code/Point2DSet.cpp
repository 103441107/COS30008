#include "Point2DSet.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;
// Add a 2D point to set
void Point2DSet::add(const Point2D& aPoint)
{
    fPoints.push_back(aPoint);
}
void Point2DSet::add(Point2D&& aPoint)
{
    fPoints.push_back(aPoint);
}
// Remove the last point in the set
void Point2DSet::removeLast()
{
    fPoints.pop_back();
}
// Tests aPoint, returns true if aPoint makes no left turn
bool Point2DSet::doesNotTurnLeft(const Point2D& aPoint) const
{
    return fPoints[size() - 1].isClockwise(fPoints[size() - 2], aPoint);
}
// Load 2D points from file
void Point2DSet::populate(const std::string& aFileName)
{
    ifstream inFile(aFileName);
    if (!inFile)
    {
        cout << "Error opening file " << aFileName << endl;
        return;
    }
    Point2D point;
    // number of points in file
    int n;
    inFile >> n;
    for (int i = 0; i < n; i++)
    {
        inFile >> point;
        add(point);
    }
    inFile.close();
}

bool orderByCoordinates(const Point2D& aLeft, const Point2D& aRight)
{
    return aLeft < aRight;
}
bool orderByPolarAngle(const Point2D& aLHS, const Point2D& aRHS)
{
    if (aLHS.isCollinear(aRHS)) {
        return aLHS.magnitude() < aRHS.magnitude() - 1e-4;
    }
    return aLHS.direction() < aRHS.direction() - 1e-4;
}

// Sort set using stable_sort on vectors
void Point2DSet::sort(Comparator aComparator)
{
    stable_sort(fPoints.begin(), fPoints.end(), aComparator);
}
// Returns numner of elements in set
size_t Point2DSet::size() const
{
    return fPoints.size();
}
// Clears set
void Point2DSet::clear()
{
    fPoints.clear();
}
// Run Graham's scan using out parameter aConvexHull
void Point2DSet::buildConvexHull(Point2DSet& aConvexHull)
{
    aConvexHull.clear();

    sort(orderByCoordinates);
    for (auto& point : fPoints)
    {
        point.setOrigin(fPoints[0]);
    }
    sort(orderByPolarAngle);
    aConvexHull.add(fPoints[0]);
    aConvexHull.add(fPoints[1]);
    aConvexHull.add(fPoints[2]);
    for (size_t i = 3; i < size(); i++)
    {
        while (aConvexHull.size() >= 2 && aConvexHull.doesNotTurnLeft(fPoints[i]))
        {
            aConvexHull.removeLast();
        }
        aConvexHull.add(fPoints[i]);
    }
}
// Indexer for set
const Point2D& Point2DSet::operator[](size_t aIndex) const
{
    return fPoints[aIndex];
}
// Iterator methods
Point2DSet::Iterator Point2DSet::begin() const
{
    return fPoints.begin();
}
Point2DSet::Iterator Point2DSet::end() const
{
    return fPoints.end();
}
