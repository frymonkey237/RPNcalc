#include "MathStack.h"
#include <list>
using namespace std;

//******************************************************************************
//***|  MathStack Member Functions  |*******************************************
//******************************************************************************

double MathStack::popTop() {
    double topNum = this->realStack.front();
    this->realStack.pop_front();
    return topNum; 
} //end popTop


list<double> MathStack::topNreversed(int n) { 
    list<double> topNrev = this->realStack;
    topNrev.resize(n);
    topNrev.reverse();
    return topNrev;
} //end topNreversed

void MathStack::insert(double num, int position) {
    list<double>::iterator stackIter = this->realStack.begin();
    for (int i = 0; i < position; i++)
        stackIter++;
    this->realStack.insert(stackIter, num);
} //end iterator

void MathStack::clearStack() {
    this->realStack.clear();
    this->realStack.resize(30, 0); 
} //end clearStack
