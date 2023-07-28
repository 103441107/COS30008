COS30008 - Data Structures and Patterns
January 2022
==============
## Scope: Tutorial 4 (alternative): Shape Type Hierarchy

This document describes the requirements for an alternative problem domain for Tutorial 4. 

You are asked to design the `Shape` type hierarchy that is mentioned briefly in Lecture 4. You need to design the class `Shape` and its four subtypes: 
1. `Rectangle`
2. `Triangle`
3. `Circle`
4. `Parallelogram`

You must design this type hierarchy with inheritance to meet the following requirements:

1. Each shape knows enough details to be able to draw itself. Details must include at least coordinates of the neccessary point(s) and the filled color. Depending on the specific shape type, other details may be added (e.g. circles would need to know the radius as well).
2. Operation `draw()`: prints out the essential information needed to draw the shape. You are not required to design the actual the drawing logic.
3. Operation `area()`: computes and returns the area of a shape.
4. Operator `>>`: to initialise a shape from an input stream
5. Operator `<<`: to print the shape details out to an output stream
6. Operator `==`: to check two shapes for equality
7. Operator `+`: to create a new shape from the result of merging two shapes