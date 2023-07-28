
// COS30008, Tutorial 5, 2021

#include "EasterEgg.h"

#include <fstream>
#include <stdexcept>

using namespace std;

EasterEgg::EasterEgg() :
    fSize(0),
    fData(nullptr)
{}

EasterEgg::~EasterEgg()
{
    delete [] fData;
}
        
bool EasterEgg::load( const std::string& aFileName )
{
    ifstream lInput( aFileName );
    
    if ( lInput.good() )
    {
        lInput >> fSize;
        
        if ( fSize )
        {
            fData = new DataMap[fSize];
            
            for ( size_t i = 0; i < fSize; i++ )
            {
                lInput >> fData[i].fIndex >> fData[i].fDatum;
            }
        }
        
        lInput.close();
        
        return true;
    }
    
    return false;
}

size_t EasterEgg::size() const
{
    return fSize;
}
    
const DataMap& EasterEgg::operator[]( size_t aIndex ) const
{
    if ( aIndex < fSize )
    {
        return fData[aIndex];
    }

    throw out_of_range( "Invalid index." );
}
    
EasterEggIterator EasterEgg::begin() const
{
    return EasterEggIterator( *this );
}

EasterEggIterator EasterEgg::end() const
{
    return EasterEggIterator( *this, size() );
}
