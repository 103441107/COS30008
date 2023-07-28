
// COS30008, Tutorial 2, 2021

#pragma once
#include <iostream>

/* DESIGN SPECIFICATION */
/* Represents a class that record character counts  */
class CharacterCounter
{
private:
  // total number of characters
  size_t fTotalNumberOfCharacters;
  // character count array: a slot holds the count for one character
	size_t fCharacterCounts[256];           // We count all 256 byte values

public:
  // default constructor: initialise this to empty
  CharacterCounter();

  // increment the count of aCharacter in this
  void count( unsigned char aCharacter );

  // implements put-out operator: prints to ostream the content of this 
  friend std::ostream& operator<<( std::ostream& aOStream, 
	                               const CharacterCounter& aCharacterCounter );
};
