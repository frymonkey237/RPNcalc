#ifndef MATHSTACK_H
#define MATHSTACK_H

#include <list>
using namespace std;

//Combines primary data stack with functions to manipulate the stack 
class MathStack {
private:
    list<double> realStack;
    list<double>::iterator stackIter; 

public:
    MathStack(int initialStackLength = 30) //Constructor
        { realStack.resize(initialStackLength, 0); } //fill initial stack with 0's   
    bool radianMode = true;               //radian mode by default 
    void addNum(double num)           //add a number to the numerical stack
        { realStack.push_front(num); }
    void replaceTop(double newTop)    //replace the top element of the stack
        { realStack.front() = newTop; }
    double & top()                      //access the top element of the stack
        { return realStack.front(); }
    void pop()                             //delete the top element of the stack
        { realStack.pop_front(); }   
    int size()                             //Get stack size 
        { return realStack.size(); }    
    void trimStack(int newLength)          //resize stack
        { realStack.resize(newLength); }
    double popTop();                  //remove and return the top element of the stack
    list<double> topNreversed(int);   //Return top n stack elements in reverse
    bool empty()                           //Check if the stack is empty 
        { return realStack.empty(); }      
    void reverseStack()                    //Reverse order of the stack. Used for saving. 
        { realStack.reverse(); }
    void insert(double, int);  //insert number at position
    void clearStack();                //Clear the stack   
}; //end mathStack

#endif
