
// COS30008, Tutorial 2, 2021

#include "CharacterCounter.cpp"
#include <fstream>

using namespace std;

int main( int argc, char* argv[] )
{
  if ( argc < 2 )
  {
      cerr << "Arguments missing." << endl;
      cerr << "Usage: CharacterCounter <filename>" << endl;
      
      // return failure, not enough arguments
      return 1;
  }

  // create text input stream connected to file named in argv[1]
  ifstream lInput( argv[1], 
      //ifstream::binary 
      // ifstream::out  // supports ouputing to file 
      ifstream::in  // supports reading (input) 
      );

  // create character counter
	CharacterCounter lCounter;

  // local variable to read character (whitespaces are skipped)
	// 0-255: valid character 8-bit character
	unsigned char lChar;

  // clear skip whitespaces
  lInput.unsetf( ios::skipws );
  
  // read file character by character,
  // if no character can be read, then exit loop
	// lInput >> lChar evaluates to false on EOF
	while ( lInput >> lChar )
	{
    // count the character
		lCounter.count( lChar );
	}

  // print the table of counts
	cout << lCounter;

  // ducmle: close before exit
  lInput.close(); 

  // return success
	return 0;
}
