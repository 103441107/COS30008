
// COS30008, Tutorial 2, 2021

#include "CharacterCounter.h"

using namespace std;
/* IMPLEMENTATION  */
CharacterCounter::CharacterCounter()
{
  for (size_t i = 0; i < 256; i++)
  {
    fCharacterCounts[i] = 0;
  }

  fTotalNumberOfCharacters = 0;
}

void CharacterCounter::count(unsigned char aCharacter)
{
  fCharacterCounts[aCharacter]++;
  fTotalNumberOfCharacters++;
}

ostream& operator<<(ostream &aOStream, const CharacterCounter &aCharacterCounter)
{
  aOStream << "Character counts for "
           << aCharacterCounter.fTotalNumberOfCharacters << " characters:" << endl;

  for (size_t i = 0; i < 256; i++)
  {
    if (aCharacterCounter.fCharacterCounts[i] != 0)
    {
      aOStream << static_cast<char>(i) << ":\t"
               << aCharacterCounter.fCharacterCounts[i] << endl;
    }
  }

  return aOStream;
}
