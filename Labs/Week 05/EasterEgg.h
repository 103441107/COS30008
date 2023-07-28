
// COS30008, Tutorial 5, 2021

#pragma once

#include <string>

#include "EasterEggIterator.h"

/* this has compiler warning: "...has no linkage [-Wsubobject-linkage]"
using DataMap =
    struct
    {
        unsigned int fIndex;
        unsigned int fDatum;
    };
*/

/* alternative design (without 'using')*/
struct DataMap {  // represents a data point (index, val) in input file
  unsigned int fIndex;  // the data point's index (range: 0...size-1)
  unsigned int fDatum;  // corresponding data value
};

class EasterEgg
{
private:
    size_t fSize;   // number of data points (value pairs): 1st entry in the input file read by load()
    DataMap* fData; // pointer to DataMap[], created & populated by load()

public:
    EasterEgg();
    ~EasterEgg();
        
    bool load( const std::string& aFileName );

    size_t size() const;
    
    const DataMap& operator[]( size_t aIndex ) const;
    
    EasterEggIterator begin() const;
    EasterEggIterator end() const;
};
