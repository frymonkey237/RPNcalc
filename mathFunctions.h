#ifndef MATHFUNCTIONS_H
#define MATHFUNCTIONS_H

#include "MathStack.h"
#include <list>
using namespace std; 

//UNARY OPERATIONS
void negative(MathStack &);
void exponential(MathStack &);
void tenToPower(MathStack &);
void sine(MathStack &);
void cosine(MathStack &);
void tangent(MathStack &);
void secant(MathStack &);
void cosecant(MathStack &);
void cotangent(MathStack &);
void arcsine(MathStack &);
void arccosine(MathStack &);
void arctangent(MathStack &);
void hyperSin(MathStack &);
void hyperCos(MathStack &);
void hyperTan(MathStack &);
void arcHyperSin(MathStack &);
void arcHyperCos(MathStack &);
void naturalLog(MathStack &);
void logBase10(MathStack &); 
void squareRoot(MathStack &); 
void cubeRoot(MathStack &);
void square(MathStack &);
void cube(MathStack &); 
void radToDeg(MathStack &);
void degToRad(MathStack &); 


//BINARY OPERATIONS
void add(MathStack &, double);
void subtract(MathStack &, double);
void multiply(MathStack &, double);
void divide(MathStack &, double); 
void integerDivide(MathStack &, double);
void modFunction(MathStack &, double); 
void raise2power(MathStack &, double); 
void swapXY(MathStack &, double);
void magnitude2D(MathStack &, double);
void moveNtoTop(MathStack &, double);
void root(MathStack &, double); 


#endif
