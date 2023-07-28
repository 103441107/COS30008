
// COS30008, Tutorial 4, 2021

#include "ResistorBase.h"

using namespace std;

void ResistorBase::setBaseValue( double aBaseValue )
{
    fBaseValue = aBaseValue;
}
    
ResistorBase::ResistorBase( double aBaseValue )
{
    setBaseValue( aBaseValue );
}

double ResistorBase::getBaseValue() const
{
    return fBaseValue;
}

double ResistorBase::getPotentialAt( double aCurrent, double aFrequency ) const
{
    // V = IR
    return aCurrent * getReactance( aFrequency );
}

double ResistorBase::getCurrentAt( double aVoltage, double aFrequency ) const
{
    // I = V/R
    return aVoltage / getReactance( aFrequency );
}

istream& operator>>( istream& aIStream, ResistorBase& aObject )
{
    double lValue;
    string lUnit;

    aIStream >> lValue >> lUnit;
    
    aObject.flatten( lValue, lUnit );
    
    return aIStream;
}

ostream& operator<<( ostream& aOStream, const ResistorBase& aObject )
{
    double lValue;
    string lUnit;

    aObject.normalize( lValue, lUnit );
        
    return aOStream << lValue << ' ' << lUnit;
}
