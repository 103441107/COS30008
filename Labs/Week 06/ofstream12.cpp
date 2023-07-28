
// COS30008, Tutorial 6, 2021

#include "ofstream12.h"

using namespace std;

void ofstream12::init()
{
  for (size_t i = 0; i < fBufferSize; i++)
    fBuffer[i] = 0;

  fByteIndex = 0;
  fBitIndex = 7;
}

void ofstream12::writeBit0()
{
  completeWriteBit();
}

void ofstream12::writeBit1()
{
  // sets the bit at the fBitIndex in the current byte
  // 1 << fBitIndex: "left-shift" 1 by fBitIndex bits ==> 10...0 (0...0 has fBitIndex 0s)
  fBuffer[fByteIndex] += 1 << fBitIndex;
  completeWriteBit();
}

void ofstream12::completeWriteBit()
{
  fBitIndex--;

  if (fBitIndex < 0)  // run out of bits in the current byte
  {
    fByteIndex++;
    fBitIndex = 7;    // bit addressing in the byte starts from 7 down to 0

    if (fByteIndex == fBufferSize)
    {
      flush();
    }
  }
}

ofstream12::ofstream12(const char *aFileName, size_t aBufferSize)
{
  // set up buffer
  fBufferSize = aBufferSize;
  fBuffer = new byte[fBufferSize];

  // clear buffer
  init();

  // open associated output file, if specified
  open(aFileName);
}

ofstream12::~ofstream12()
{
  close();

  delete[] fBuffer;
}

void ofstream12::open(const char *aFileName)
{
  if (aFileName)
    fOStream.open(aFileName, ofstream::binary);
}

bool ofstream12::good() const
{
  return fOStream.good();
}

bool ofstream12::isOpen() const
{
  return fOStream.is_open();
}

void ofstream12::close()
{
  flush();
  fOStream.close();
}

void ofstream12::flush()
{
  // flush pending output.
  // Note: 4-bits of the last byte may be filled (because we are writing 12-bits instead of the
  //  the regular 8-bit operation). Therefore, we may need to + 1 more byte...
  fOStream.write((char *)fBuffer, fByteIndex + (fBitIndex % 7 ? 1 : 0));
  init();
}

ofstream12 &ofstream12::operator<<(size_t aValue)
{
  const int wordSize = 12;
  for (size_t i = 0; i < wordSize; i++) // write 12 Bits
  {
    if (aValue & 0x01) // The current lowest bit is set (i.e. 1 in binary).
      writeBit1();
    else
      writeBit0();
    aValue >>= 1; // aValue := aValue / 2 (right-shift by 1 bit)
  }

  return *this; // return updated output stream
}
