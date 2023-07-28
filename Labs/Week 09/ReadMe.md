# Code update
In `Main.cpp`'s header, change:
```
#include "SimpleString.h"
```
to 
```
#include "SimpleString.cpp"
``` 

# Usage
1. In `Test.h`, set the suitable value for `TEST` by uncommenting the suitable `#define TEST n` line.
2. Execute `Main.cpp` to observe the output
  
# Test 0
**Goal**: demonstrates the need for copy constructor

A **run-time exception** occurs in the deconstructor:

```
S1: 
S2: AB
free(): double free detected in tcache 2
```

**Reason**: 
- `s2 = s1`: is a shallow copy, `fCharacter`s are pointing to the same object
- the deconstructor thus frees `fCharacter` twice!!

The call stack confirms with the following output (break point is set at the `delete` instruction):
```
s1(0x7fffffffd4b0)
  -> fCharacters: 0x55555556b2e0 ""

s2(0x7fffffffd4c0)
  -> fCharacters: 0x55555556b2c0 "AB"
```

# Test 1
**Goal**: enables copy constructor to resolve the problem reported in Test 0

# Test 2
**Goal**: demonstrates the need for assignment operator

Run-time exception:
```
free(): double free detected in tcache 2
```

# Test 3
**Goal**: enables assignment operator to resolve the problem reported in Test 2

# Test 4
**Goal**: demonstrates the need for clone()

Run-time exception: 

```
Segmentation fault (core dumped)
```

# Test 5
**Goal**: enables clone() to resolve the problem reported in Test 4

# Test 6
**Goal**: test reference counting (`Handle` class)

Requires:

```
#include "HandleImpl.h"
```