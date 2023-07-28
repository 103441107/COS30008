# LZW Compression
URL: https://www.cs.cmu.edu/~cil/lzw.and.gif.txt

# C++
## Bitwise shift operators
**References:** 
- Lippman et al, Section 4.8: 
  - `<<` left shift: 
  - `>>` right shift: 

```
expr1 << | >> expr2
```
**Description:**  
- yields a value that is a copy of the (possibly promoted) LHS operand with the bits shifted as directed by the RHS operand. 
- The RHS operand must not be negative and must be a value that is strictly less than the number of bits in the result. 
- The bits are shifted left (<<) or right (>>)
- Bits that are shifted off the end are discarded: