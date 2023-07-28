
// COS30008, Tutorial 5, 2021

#include "EasterEggIterator.h"
#include "EasterEgg.h"

#include <iostream>

using namespace std;

void EasterEggIterator::advance()
{
  if (fPosition < fContainer.size())
  {
    fValueIndex = fPosition;

    for (size_t i = 0; i < fContainer.size(); i++)
    {
      if (fContainer[i].fIndex == fPosition)  // the ith DataMap's index matches fPosition
      {
        fValueIndex = i;    // current position's value = i

        break;
      }
    }
  }
  else
  {
    fValueIndex = 0;
  }
}

EasterEggIterator::EasterEggIterator(const EasterEgg &aContainer, size_t aStart) : fContainer(aContainer),
                                                                                   fPosition(aStart),
                                                                                   fValueIndex(0)
{
  advance();
}

const unsigned int &EasterEggIterator::operator*() const
{
  return fContainer[fValueIndex].fDatum;
}

EasterEggIterator &EasterEggIterator::operator++()
{
  fPosition++;

  advance();

  return *this;
}

EasterEggIterator EasterEggIterator::operator++(int)
{
  EasterEggIterator old = *this;

  ++(*this);

  return old;
}

bool EasterEggIterator::operator==(const EasterEggIterator &aRHS) const
{
  return &fContainer == &aRHS.fContainer &&
         fPosition == aRHS.fPosition;
}

bool EasterEggIterator::operator!=(const EasterEggIterator &aRHS) const
{
  return !(*this == aRHS);
}

EasterEggIterator EasterEggIterator::begin() const
{
  EasterEggIterator iter = *this;

  iter.fPosition = 0;
  iter.advance();

  return iter;
}

EasterEggIterator EasterEggIterator::end() const
{
  EasterEggIterator iter = *this;

  iter.fPosition = iter.fContainer.size();

  return iter;
}
