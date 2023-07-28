#include "IntVector.h"
#include "IntSorter.h"
#include "IntVectorIterator.h"

#include <cstddef>
#include <iostream>
#include <stdexcept>


using namespace std;

IntVector::IntVector(const int aArrayOfIntegers[], size_t aNumberOfElements)
{
    fNumberOfElements = aNumberOfElements;
    fElements = new int[fNumberOfElements];
    for (size_t i = 0; i < fNumberOfElements; i++)
    {
        fElements[i] = aArrayOfIntegers[i];
    }
}

IntVector::~IntVector()
{
    delete[] fElements;
}

size_t IntVector::size() const
{
    return fNumberOfElements;
}

void IntVector::swap(size_t aSourceIndex, size_t aTargetIndex)
{
    if (aSourceIndex < fNumberOfElements && aTargetIndex < fNumberOfElements && aSourceIndex >= 0 && aTargetIndex >= 0)
    {
        int lTemp = fElements[aSourceIndex];
        fElements[aSourceIndex] = fElements[aTargetIndex];
        fElements[aTargetIndex] = lTemp;
    }
    else
    {
        throw out_of_range("Index out of range!");
    }
}

void IntVector::sort(const IntSorter &aSorter)
{
    aSorter(*this);
}

const int IntVector::operator[](size_t aIndex) const
{
    if (aIndex < fNumberOfElements && aIndex >= 0)
    {
        return fElements[aIndex];
    }
    else
    {
        throw out_of_range("Index out of range!");
    }
}

IntVectorIterator IntVector::begin() const
{
    return IntVectorIterator(*this);
}

IntVectorIterator IntVector::end() const
{
    return IntVectorIterator(*this, fNumberOfElements);
}
