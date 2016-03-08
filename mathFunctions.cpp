#include "MathStack.h"   
#include <cmath>
#include <list>
#include <string>
using namespace std;

//Mathematical Constants
const double PI = 3.1415926535897932384626433832795028841;
const double EULERS_NUM = 2.7182818284590452353602874713526624977;

//*****************************************************************************************
//***|  Math Functions   |*****************************************************************
//*****************************************************************************************

    
    //UNARY OPERATIONS----

void negative(MathStack &stack) 
    { stack.top() = 0 - stack.top(); }

void exponential(MathStack &stack)
    { stack.top() = pow(EULERS_NUM, stack.top()); } 

void tenToPower(MathStack &stack)
    { stack.top() = pow(10, stack.top()); } 

void sine(MathStack &stack)
    { stack.top() = sin(stack.top()); } 

void cosine(MathStack &stack)
    { stack.top() = cos(stack.top()); } 

void tangent(MathStack &stack)
    { stack.top() = tan(stack.top()); } 
    
void secant(MathStack &stack)
    { stack.top() = 1 / cos(stack.top()); } 
    
void cosecant(MathStack &stack)
    { stack.top() = 1 / sin(stack.top()); } 
    
void cotangent(MathStack &stack)
    { stack.top() = 1 / tan(stack.top()); } 

void arcsine(MathStack &stack)
    { stack.top() = asin(stack.top()); } 

void arccosine(MathStack &stack)
    { stack.top() = acos(stack.top()); } 

void arctangent(MathStack &stack)
    { stack.top() = atan(stack.top()); } 
    
void hyperSin(MathStack &stack)
    { stack.top() = sinh(stack.top()); } 
    
void hyperCos(MathStack &stack)
    { stack.top() = cosh(stack.top()); } 
    
void hyperTan(MathStack &stack)
    { stack.top() = tanh(stack.top()); } 

void arcHyperSin(MathStack &stack)
    { stack.top() = asinh(stack.top()); } 
    
void arcHyperCos(MathStack &stack)
    { stack.top() = acosh(stack.top()); } 
    
void naturalLog(MathStack &stack)
    { stack.top() = log(stack.top()); } 
    
void logBase10(MathStack &stack)
    { stack.top() = log10(stack.top()); } 
    
void squareRoot(MathStack &stack)
    { stack.top() = sqrt(stack.top()); } 
    
void cubeRoot(MathStack &stack)
    { stack.top() = cbrt(stack.top()); } 
    
void square(MathStack &stack)
    { stack.top() = pow(stack.top(),2); } 

void cube(MathStack &stack)
    { stack.top() = pow(stack.top(),3); } 
   
void radToDeg(MathStack &stack)
    { stack.top() = stack.top() * 180 / PI; }

void degToRad(MathStack &stack)
    { stack.top() = stack.top() * PI / 180; }



    //BINARY OPERATIONS----

void add(MathStack &stack, double lastIn) 
    { stack.top() = stack.top() + lastIn; }

void subtract(MathStack &stack, double lastIn)     
    { stack.top() = stack.top() - lastIn; }

void multiply(MathStack &stack, double lastIn) 
    { stack.top() = stack.top() * lastIn; }

void divide(MathStack &stack, double lastIn) 
    { stack.top() = stack.top() / lastIn; }

void integerDivide(MathStack &stack, double lastIn) 
    { stack.top() = lround(stack.top()) / lround(lastIn); }

void raise2power(MathStack &stack, double lastIn) 
    { stack.top() = pow(stack.top(), lastIn); }

void modFunction(MathStack &stack, double lastIn) 
    { stack.top() = remainder(stack.top(), lastIn); }

void swapXY(MathStack &stack, double lastIn) {
    double firstIn = stack.popTop();
    stack.addNum(lastIn);
    stack.addNum(firstIn);
} //end swapXY

void magnitude2D(MathStack &stack, double lastIn)
    { stack.top() = sqrt( pow(stack.top(), 2)  +  pow(lastIn, 2) ); }

void root(MathStack &stack, double lastIn)
    { stack.top() = pow(stack.top(), 1 / lastIn); } 

void moveNtoTop(MathStack &stack, double lastIn) {
    list<double> topN; 
    double numAtN;
    int n = trunc(abs(lastIn));
    for (int i = 0; i < n - 1; i++) 
        topN.push_front(stack.popTop());
    numAtN = stack.popTop(); 
    for (int i = 0; i < n - 1; i++) {
        stack.addNum(topN.front());
        topN.pop_front();
    } //end for
    stack.addNum(numAtN);  
} //end moveNtoTop


