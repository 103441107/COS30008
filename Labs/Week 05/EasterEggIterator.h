
// COS30008, Tutorial 5, 2021

#pragma once

// include for size_t (unsigned integral type)
#include <cstddef>

// forward declaration for class EsterEgg
class EasterEgg;

class EasterEggIterator
{
private:
    
    const EasterEgg& fContainer;    // read-only container reference
    size_t fPosition;               // position of iterator
    size_t fValueIndex;             // index of value that corresponds to position
    
    void advance();                 // find value index that maps position
    
public:
    
    EasterEggIterator( const EasterEgg& aContainer, size_t aStart = 0 );
    
    const unsigned int& operator*() const;
    
    EasterEggIterator& operator++();
    EasterEggIterator operator++(int);
    
    bool operator==( const EasterEggIterator& aRHS ) const;
    bool operator!=( const EasterEggIterator& aRHS ) const;

    EasterEggIterator begin() const;
    EasterEggIterator end() const;
};
