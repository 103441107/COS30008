#include "IntVector.h"
#include "IntVectorIterator.h"

IntVectorIterator::IntVectorIterator(const IntVector &aContainer, size_t aStart) :
    fContainer(aContainer),
    fPosition(aStart)
{
}

const int IntVectorIterator::operator*() const
{
    return fContainer[fPosition];
}

IntVectorIterator &IntVectorIterator::operator++()
{
    ++fPosition;
    return *this;
}

IntVectorIterator IntVectorIterator::operator++(int) {
    IntVectorIterator lTemp(*this);
    ++fPosition;
    return lTemp;
}

bool IntVectorIterator::operator==(const IntVectorIterator &aRHS) const {
    return fPosition == aRHS.fPosition && &fContainer == &aRHS.fContainer;
}

bool IntVectorIterator::operator!=(const IntVectorIterator &aRHS) const {
    return !(*this == aRHS);
}

IntVectorIterator IntVectorIterator::begin() const {
    return IntVectorIterator(fContainer);
}

IntVectorIterator IntVectorIterator::end() const {
    return IntVectorIterator(fContainer, fContainer.size());
}