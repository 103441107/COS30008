
// COS30008, Tutorial 9, 2021

#pragma once

#include "Test.h"

class SimpleString
{
private:
	char * fCharacters;

public:
	SimpleString();
	virtual ~SimpleString();

#if TEST >= 1

  // enable copy-constructor (deep copying)
	SimpleString( const SimpleString& aOtherString );

#endif

#if TEST >= 3

    // enable assignment operator (deep copying)
    SimpleString& operator=( const SimpleString& aOtherString );

#endif

#if TEST >= 5

  // enable cloning (deep copying, using copy constructor)
	virtual SimpleString* clone();

#endif
	
	SimpleString& operator+( const char aCharacter );
	const char* operator*() const;
};
