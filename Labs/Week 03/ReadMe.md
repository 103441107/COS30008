## Resources

## Polynomial operations

### Multiplication

  f(x) = ax^2 + bx^1 + cx^0
  g(x) = a'x + b'x^0

  f(x) * g(x) = (ax^2 + bx^1 + cx^0) * (ax + bx^0)
  
  Polynomial p = f(x) * g(x)

  p.fDegree = f.fDegree + g.fDegree = 3

  i = 0: ax^2 * ( 
    k = 0: a'x +     => p.fcoeffs[ f.fdegree-i + g.fdegree] += a * a'     // (a*a') x^(2+1)
    k = 1: b'x^0     => p.fcoeffs[ f.fdegree-i + g.fdegree-k ] += a * b'   // (a*b') x^(2+0)
    )
  i = 1:  bx^1 * (
    k = 0: a'x +
    k = 1: b'x^0 
  )
  i = 2:  cx^0 * (
    k = 0: a'x +
    k = 1: b'x^0 
  )

## Basics of integration
- [What is integration?](https://youtu.be/FsC3do74UIo)
- [Relationship between differentiation and integration](https://youtu.be/NLU9U8-wJrM)
  - anti-derivative

## Application of integration to volume computation
- [Calculating the volume of a 3D shape by integration: Explained](https://youtu.be/QLHJl2_aM5Q)

## Extra exercises
1. Read the tutorial slides about "The Mathematics of Polynomials". 
2. Extend the design of Polynomial class to support two operations that compute the derivative (page 3) and definite integral (page 5).