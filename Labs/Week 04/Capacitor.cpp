
// COS30008, Tutorial 4, 2021

#include "Capacitor.h"

#include <cmath>

using namespace std;

bool Capacitor::mustScale( double aValue ) const
{
	return aValue < 1.0;
}

const double Capacitor::getMultiplier() const
{
	return 1000.0;
}

const std::string Capacitor::getMajorUnit() const
{
	return "F";
}

const std::string Capacitor::getMinorUnits() const
{
	return "Fmunp";
}

Capacitor::Capacitor( double aBaseValue ) :
	ResistorBase( aBaseValue )
{}

double Capacitor::getReactance( double aFrequency ) const
{
	// PI = 4.0 * atan( 1.0 )
	// w = 2PIf
	// 1/wC

	return 1.0 / ((8.0 * atan( 1.0 ) * aFrequency) * getBaseValue());
}
