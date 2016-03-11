/* TO DO
 *  > TO DO: 
 *      > remove the extra indent on the to do list. 
 *      > switch over to the "> Subject:" format which seems like it would more
 *        easily translate into program documentation. In addition, try to write
 *        notes in such a way that they will easily translate into
 *        documentation. That way, instead of deleting this stuff once it's
 *        complete, it can be repurposed into documentation, killing two birds
 *        with one stone. 
 *
 *  > FileHandler:
 *      > Create a file handler class and move file related functions to it. 
 *      > Create methods for saving/loading program variables (profiles), user
 *        defined content, and unit conversion ratios. 
 *      
 *  > Named:
 *      > Create a "named" command that always follows a save or load command
 *        pair and precedes a filename to save to or load from. 
 *          > If no "named" command follows a save or load command pair, then 
 *            whatever is being saved or loaded will use the associated default
 *            file which is called default.<ext> where ext is the associated 
 *            extension.
 *              > Saving/loading with the name "default" will have the same
 *                effect. For example, "save stack" is equivalent to 
 *                "save stack named default".
 *      > Things that can be saved or loaded: 
 *        Note: command is what would follow "save" or "load"
 *          > the stack 
 *              > extension: ".stack"
 *              > command: "stack"
 *              > default file: "default.stack"
 *          > user defined variables, functions, and conversion ratios 
 *              > extension: ".def"
 *              > command: "defined"
 *              > default file: "default.def"
 *          > program variables/settings 
 *              > extension: ".profile"
 *              > command: "profile" 
 *              > default: "default.profile"
 *          > all three of the above 
 *              > command: "all" 
 *      > If saving and file with given name already exists, then overwrite the  
 *        file. If file with name does not exist, create it.   
 *      > Examples: 
 *          > To save the stack to default file:
 *                  "save stack" or "save stack default" 
 *          > To save user defined variables with name "myVar":
 *                  "save defined named myVar"
 *          > Load a profile with the name "fullscreen":
 *                  "load profile named fullscreen"
 *
 *  > Rationals: 
 *      > look into ratio library for fractions
 *          > identify fractions using either regex or cstring methods
 *          > maybe make the RationalNumber class polymorphically inherit from
 *            both SingletonElement and ratio
 *  
 *  > Command Naming:
 *      > Add more abbreviated forms of commands which consist of a dash, '-',
 *        followed by a single letter. Also, add more full names for
 *        trigonometric operations, like "arcsecant" or "hyperbolictangent".
 *
 *  > Help:
 *      > list all the commands in the help file. 
 *      > Create help command and help file reader. Look into how man pages are
 *        normally handled on linux and in ncurses programs.  
 *          > Can get help for specific commands with: "help <cmd>"  
 *          > help is an infix command, requiring look-ahead, like set, store,
 *            save, etc. 
 *          > if help isn't followed by a command, then display main help page
 *          > help info stored in RPNcalc.help
 *          > How will the user scroll through help page? 
 *          > help files also should be accessible from the command line using
 *            the man command. 
 *
 *  > Undo: 
 *      > undo returns the stack to it's state prior to the last input, or
 *        prior to the last undo if undo is called multiple times. 
 *      > undo mode can be disabled by the user with "unset undo" in order
 *        to improve performance.
 *          > Create flag in ProgramVariables for undo. 
 *      > number of past stacks to save is user definable with 
 *        "<num> set undosteps"
 *          > will have to add undoSteps variable to ProgramVariables. 
 *      > If undo flag is set, a file is kept open and stack is appended to
 *        the file during each iteration, after the input is entered, but 
 *        before it is processed. 
 *      > 
 *
 *      > Set:
 *          > For numeric program variables the existing syntax for set is: 
 *                      "<value> set <variable>"
 *          > Need a system for using set with boolean program variables. 
 *              > The syntax for boolean variables is: 
 *                      "set <variable>" or "unset <variable>" 
 *              > "set" sets the proceeding variable to true, and "unset" sets
 *                the proceeding variable to false, regardless of the variable's
 *                previous value. 
 *              > both "set" and "unset" call the setProgramVariable function. 
 *                  > After look ahead is performed to get the variable to set,
 *                    the setProgramVariable function branches depending on if
 *                    the variable is a bool or an int. 
 *                      > If variable is an int, the top of the stack is popped
 *                        and stored to the variable  
 *                      > If variable is a bool, the first letter of the current
 *                        term, which would have to be either "set" or "unset",
 *                        is checked. 
 *                          > ProgramVariables method setVar is called using
 *                            ternary conditional operator: 
 *                            progVar.setVar(<variable>, tolowercase(
 *                                    progVar.inputTerms[index].front()) == 's'?
 *                                    true : false);
 *                          > Note: Boolean variables that represent a "this or
 *                            that" relationship rather than a "yes or no"
 *                            relationship, may have variable names which aren't
 *                            really a variable, but rather an alias for a 
 *                            for inverse of another variable, eg. "set degrees"
 *                            is really an alias for "unset radians". 
 *                            
 *
 *      > Radian mode: 
 *          > move radian mode back to ProgramVariables, and then add a bool
 *            parameter to unary operations for the radian variable. 
 *
 *      > ProgramVariables:
 *          > make ProgramVariables a class so that it can have member
 *            functions.
 *          > create an overloaded method called something like "setVar" with
 *            two variations. 
 *              > One sets integer variables and takes a string containing the 
 *                name of the intended variable along with the new integer value 
 *                for the variable. 
 *              > The other sets boolean variables and takes the variable name 
 *                along with a boolean value. 
 *
 *      > Save/Load: 
 *          > could even create profiles 
 *              > user would specify profile names which would be appended on to the 
 *                filename for the profile data. 
 *                  ".RPNstack.someProfileName.profile"
 *              > profiles would be useful for running the calculator on different 
 *                terminals.
 *
 *      > Units: 
 *          > units a specified with a unit initials preceded by an underscore
 *              > examples: kelvin - "_k" , millimeter - "_mm"
 *          > units are stored in stack element data structure 
 *          > user can basically enter anything they want to as a unit as long as its made 
 *            up of alphanumeric characters and preceded by an underscore. 
 *          > multiplying mixed units creates a new unit that is the product of the two 
 *            units, eg. "_mm*Hg".
 *          > Dividing mixed units creates a new unit that is the ratio of the two units, 
 *            eg. "_m/hr" 
 *          > each stack element contains an array for numerator units, an array for 
 *            denominator units and a flag for has units.
 *              > If has units is raised, command functions will search an abridged array
 *                of only operations where units are defined, and will then call overloaded
 *                versions of the associated functions that also take the unit arrays as 
 *                parameters. 
 *              > for binary commands some operations will only be defined when units of 
 *                operands match, ie addition and subtraction, while others work 
 *                regardless of units 
 *                  > to complicate things further, units with known conversions should 
 *                    be converted if possible to facilitate things like addition and 
 *                    subtraction. 
 *      > think about algebraic variables 
 *      > Another way to handle multiple data types on the stack is to create a stack 
 *        element structure which would hold a stack element, its datatype, units, and any
 *        other relevant information. 
 *          > This would require somehow defining how to perform binary operations on 
 *            mixed data types, and when operations can't be performed on mixed data 
 *            types.
 *      > Look into using the gnu scientific library , atlas, and or boost 
 *          > <boost/numeric/interval.hpp> for arithmetic on intervals. 
 *              > Could be useful for computing the result of integration over a range. 
 *              > will need to link the boost library when compiling. 
 *          > Gnu mpfr library for arbitrary precision floating point
 *            calculations.
 *      > For mixed type oprations, look into overloading the math functions and using 
*         try-catch statements to catch when a operation is undefined for given types.
*       > save command that is like set and store in that what is to be saved follows the
*         command.
*           > valid forms are "save variables", "save profile", "save stack", and 
*             "save all"
*       > Use regex to determine input types 
*           > Possible types:
*               > real number
*                   > 0 or more + or - followed by 0 or more digits or commas
*                     followed by zero to one decimal points followed by one
*                     or more digits followed by 0 to one scientific notation
*                     stuff. 
*                   > (+|-)*(\\d|,)*.*\\d+(e( 
*               > complex number 
*               > vector
*               > rational 
*               > unit 
*               > command
*               > interval
*                   > using boost interval package 
*       > change realStack back to a stack rather than a list 
*           > Or maybe a dynamically allocated array with my own implementation
*             of container functions, like push_back(num) and size(). 
*       > add "set scientific" command to put in scientific notation
*           > "set standard" to change back to standard notation
*       > look into using a package for arbitrary floating point calculations 
*           > Gnu mpfr
*           > allow user to set precision of calculations and significant
*             figures to display.
*       > for set command map try and create a struct that has a pointer to a
*         member of program variables of type T.
*       > Create a new ncurses mode that is accessed with the command line
*         argument "-n". That way the currently functioning mode will continue
*         to be operational while the ncurses interface is implemented. 
*           > Once ncurses is fully operational, make ncurses mode the default
*             and the original mode accessed with a command line argument.
*           > Make each of the 3 modes into separate functions so that the main
*             function is basically just a decision tree between the three
*             modes.
*       > Create an empty class "StackElement" that classes "RealNumber",
*         "RealVector", "ComplexNumber", and "RationalNumber" inherit from
*           > The stack will be an array of "StackElement"s, which will allow
*             holding real numbers, complex numbers, rationals, and vectors on
*             the same stack. 
*           > A "RealVector" will hold an array of real numbers, complex 
*             numbers or rationals. 
*               > Create class "SingletonElement" that inherits from 
*                 "StackElement" and is inherited by "RealNumber",
*                 "ComplexNumber", and "RationalNumber". This is so the 
*                 vector class can hold an array of SingletonElements. 
*           > Rational class holds two integer values: "numerator" and 
*             "denominator". 
*       >                             StackElement
*                                     /          \
*                     SingletonElement            SetElement      
*                    /       |       \           |         \
* Unit RationalNumber RealNumber ComplexNumber RealVector RealMatrix 
*  +---------+-------------+-----------+
*            |             |           |          
*       RationalUnit   RealUnit    ComplexUnit      
*         
*              
*           > Units are a class that contains an array of unit numerators and
*             unit denominators. An empty numerator or denominator array is
*             assumed to be equivalent to 1. 
*               > RationalUnit, RealUnit, and ComplexUnit are polymorphic
*                 classes that inherit from both the unit class and their 
*                 respective SingletonElement class. These are empty classes 
*                 which inherit the their respective element variable and the
*                 unit variables. 
*               > Allowed Mixed unit operations are limited to multiplication 
*                 and division and some derived operations derived from them 
*                 like raising to exponent. For example, the unit km+s is not
*                 allowed, but km*s or km/s is.
*               > Units are demarcated with an underscore, so 50 miles per hour
*                 would be entered as "50 _mi/hr".
*                   > No spaces in units. 
*                   > Multiplication and division must be explicit. 
*               > Units do not have to be predefined, a unit is just two arrays
*                 of cstrings. The cstrings themselves can be anything, but the
*                 naming must be consistent, ie. "miles" and "mi" would not be 
*                 considered equivalent. 
*               > Units "_d" is a way of specifying degree mode for a specific
*                 operand as well as a way to prevent invalid mixed unit 
*                 operations on a degree. Radians don't need a unit so there
*                 isn't a analogous "_r" for radians.  
*               > Conversions do have to be predefined
*                   > There are two types of conversions: linear and non-linear.
*                       > Linear conversions are something like miles to 
*                         kilometers, which can be expressed by conversion ratio,
*                         while non-linear conversions are something like 
*                         Fahrenheit to Celsius, that requires adding some
*                         constant.
*                       > Linear and non-linear are separated because of the
*                         difference in how dimensional analysis is executed and
*                         how the conversions are represented by the program. 
*                       > Linear conversions are represented by a
*                         "ConversionRatio" data structure which contains two 
*                         equivalent RealUnit types with different units which
*                         ideally should only contain a single unit numerator.  
*                           > For example, the ConversionRatio data structure 
*                             for converting between miles and kilometers might
*                             contain one RealUnit with a value of 1 and a unit
*                             of "mi", and another RealUnit with a value of
*                             1.60932 and a unit of "km" since 1 mile == 1.60932
*                             kilometers. 
*                           > Compound linear conversions are handled with 
*                             dimensional analysis. 
*                               > For dimensional analysis, a path must be found
*                                 between the input numerator and denominator 
*                                 and the desired numerator and denominator.
*                                   > Maybe solving from either end and working
*                                     towards the middle would be more efficient
*                                     than the brute force method 
*                               > Alternatively, instead of finding a path at
*                                 conversion time, all possible linear
*                                 conversions of between two units could be
*                                 created every time a new conversion ratio is
*                                 added. Essentially, this would still be the
*                                 brute force strategy except most of the work
*                                 has been done ahead of time. At conversion
*                                 time, all that is left is to seach for the
*                                 appropriate conversion, or conversions, if
*                                 performing dimensional analysis.  
*                                   > This is probably the better option of the
*                                     two.
*                                   > Because new conversion ratios will need to
*                                     created whether the conversion ratio was
*                                     added by the programmer or the user, all
*                                     conversion ratios should be stored in a
*                                     file loaded at 
*                   > "to" operator handles conversions. It is an infix operator
*                     where the left operand is the value with units that you 
*                     wish to convert, while the right operand is the unit you 
*                     wish to convert to. For example, number of kilometers in
*                     50 miles would be written as "50 _mi to _km
*                   > Once function definitions are implemented, user defined
*                     non-linear unit conversions can be implemented as a 
*                     special case of a function definition where the only 
*                     parameter is a unit and the result is a unit (which 
*                     includes classes inheriting from unit). 
  
*  
*/             
#include <iostream>
#include <iomanip> 
#include <string>
#include <cstring> 
#include <cmath>
#include <stdexcept>
#include <list>
#include <fstream> 
#include <stack>
#include <vector>
#include <map>

//for timing program execution (debugging) 
#include <ctime>
#include <ratio>
#include <chrono>

//RPNcalc header files 
#include "MathStack.h"
#include "mathFunctions.h"

//No longer using 
//#include <array>
//#include <algorithm>
//#include <regex>
using namespace std;


//    +---------------------------------+
//    |  Class and Struct Declarations  |  
//----+---------------------------------+---------------------------------------

//Data structure for holding user modifiable program variables. Passed by reference to 
//  program command function. Stack is not included and is passed separately.  
struct ProgramVariables {
    bool exit,                      //program exits when true  
         error;                     //Terminate current input process if error
    vector<string> inputTerms;      //The list of user input terms 
    int index;                      //The index of the current input term
                                        //needed for infix commands (set,store)
                                        //and repeat commands (repeat,sum,etc)
    list<string> userMessages;      //Messages to display on next output
                                        //Format:
                                            //Execution Time, 
                                            //last input,  
                                            //Error messages, if any
    map<int,int> repeatCount;       //Map of remaining repeats to repeat indices
                                        //Could also use 2D array 
    map<string,double> userVariables; //Used with store command 

    //User-modifiable program variables 
    string prompt;                  //prompt preceding user input
    int displayWidth,               //Width of display  window 
        outputLength,               //Number of stack elements to display
        maxStackLength;             //Maximum length of stack 

    //For timing main thread (debugging)
    chrono::steady_clock::time_point time1;
    chrono::steady_clock::time_point time2; 
    chrono::duration<double> timeSpan;
}; //end programVariables 


//Data structures for mapping user command to functions or variables
struct UnCommandMap {
   string inputCommand; 
   void (*functionPtr)(MathStack &);
   bool convertTrigInput,
        convertTrigOutput;    
}; //end UnCommandMap

struct BinCommandMap {
   string inputCommand; 
   void (*functionPtr)(MathStack &, double);
}; //end BinCommandMap

struct ConstantMap {
   string inputCommand;
   double constantValue;
}; //end ConstantMap

struct ProgCmdMap {
   string inputCommand;
   void (*functionPtr)(MathStack &, ProgramVariables &);
}; //end ProgCmdMap


//*****************************************************************************************
//**|  Constant Definitions  |*************************************************************
//*****************************************************************************************

//Command counts need for commandMap array sizing
const int CONST_CMD_COUNT = 2; 
const int UN_CMD_COUNT = 25;
const int BIN_CMD_COUNT = 19; 
const int PROG_CMD_COUNT = 19; 
const int TOTAL_CMD_COUNT = CONST_CMD_COUNT + UN_CMD_COUNT + BIN_CMD_COUNT
                            + PROG_CMD_COUNT; 

const string GREETING = "+-RPNcalc----------------------------+\n"
                        "|   ___   ___ __   __ _  __   _  __  | \n"
                        "|  / O ) / O )  \\ / /__\\/   \\| |/__\\ |\n" 
                        "| / . \\ / / / /\\ v / |__ ()  \\ | |__ |\n"
                        "|/_/ \\_\\_/ /_/  \\_/ \\__/\\__/\\_\\|\\__/ |\n"
                        "+------------------------------------+\n"
                        "         type 'help' for help        ";          
/*
 +-RPNcalc----------------------------+
 |   ___   ___ __   __ _  __   _  __  |
 |  / O ) / O )  \ / /__\/   \| |/__\ |
 | / . \ / / / /\ v / |__ ()  \ | |__ |
 |/_/ \_\_/ /_/  \_/ \__/\__/\_\|\__/ |
 +------------------------------------+
        type 'help' for for help 
 */ 
const char CLEAR_TERMINAL[] = { 0x1b, '[', '2', 'J', 0};  //ANSI clear screen escape seq.

//Mathematical Constants
const double PI = acos(-1); 
const double EULERS_NUM = 2.7182818284590452353602874713526624977;

const string RESERVED_WORDS[TOTAL_CMD_COUNT] = { "pi", "e", "-*", "neg", "e^x",
        "exp", "10^-", "sin", "cos", "tan", "sec", "csc", "cot", "asin", "acos",
        "atan", "sinh", "cosh", "tanh", "asinh", "acosh", "ln", "log", "sqrt",
        "cbrt", "sq", "cb", "+", "add", "-", "sub", "subtract", "*", "multiply",
        "/", "divide", "//", "div", "mod","%", "^", "swap", "mag2", "pyth",
        "take", "root", "quit", "set", "width", "length", "stackLength",
        "clear", "save", "sum", "load", "repeat", "sequence", "sum", "product",  
        "radians", "degrees", "store", "sto", "-l", "-s"
         }; //end RESERVED_WORDS

//*****************************************************************************************
//**|  Function Prototypes  |**************************************************************
//*****************************************************************************************


//input processing
vector<string> extractInputTerms(); 
void processInput(MathStack &, ProgramVariables &);
bool performUnaryOperation(string, MathStack &);
bool performBinaryOperation(string, MathStack &);
bool addConstant(string, MathStack &);
bool executeProgCmd(string, MathStack &, ProgramVariables &);
bool addNumber(string, MathStack &, ProgramVariables &); 
bool recallVariable(string, MathStack &, ProgramVariables &); 
string toLowercase(string); 

//Display functions
void displayOutput(MathStack &, ProgramVariables &);
void drawLine(int);

//other
void startupProcedure(MathStack &);
void exitProcedure(MathStack &); 
bool writeStackToFile(MathStack);   //A copy is desired rather than a reference here
bool loadStackFromFile(MathStack &);
void initializeRepeatCount(string,ProgramVariables &);

//program functions
void quitProgram(MathStack &, ProgramVariables &); 
void widthCmd(MathStack &, ProgramVariables &);
void displayLengthCmd(MathStack &, ProgramVariables &);
void stackLengthCmd(MathStack &, ProgramVariables &); 
void setPrompt(MathStack &, ProgramVariables &); //(incomplete)
void clearStack(MathStack &, ProgramVariables &);
void saveStack(MathStack &, ProgramVariables &); 
void loadStack(MathStack &, ProgramVariables &); 
void repeatInput(MathStack &, ProgramVariables &);
void setProgVariable(MathStack &, ProgramVariables &);
void trigMode(MathStack &, ProgramVariables &); 
void storeVar(MathStack &, ProgramVariables &); 

//    +----------------+                                                                 
//    |  Command Maps  |                                                  
//----+----------------+--------------------------------------------------------
//Remember, when adding new commands, command count constant must be adjusted
//and new command should be added to RESERVED_WORDS. 

const ConstantMap CONSTANT_MAP[CONST_CMD_COUNT] = {{"pi", PI}, {"e", EULERS_NUM}};

const UnCommandMap UNARY_OP_MAP[UN_CMD_COUNT] = { 
        {"-*", negative, 0, 0}, {"neg", negative, 0, 0}, 
        {"e^x", exponential, 0, 0}, {"exp", exponential, 0, 0},
        {"10^-", tenToPower, 0, 0}, {"sin", sine, 1, 0}, {"cos", cosine, 1, 0},
        {"tan", tangent, 1, 0}, {"sec", secant, 1, 0}, {"csc", cosecant, 1, 0},
        {"cot", cotangent, 1, 0}, {"asin", arcsine, 0, 1}, 
        {"acos", arccosine, 0, 1}, {"atan", arctangent, 0, 1}, 
        {"sinh", hyperSin, 0, 0}, {"cosh", hyperCos, 0, 0}, 
        {"tanh", hyperTan, 0, 0}, {"asinh", arcHyperSin, 0, 0},
        {"acosh", arcHyperCos, 0, 0}, {"ln", naturalLog, 0, 0}, 
        {"log", logBase10, 0, 0}, {"sqrt", squareRoot, 0, 0}, 
        {"cbrt", cubeRoot, 0, 0}, {"sq", square, 0, 0},{"cb", cube, 0, 0}
        }; //end UNARY_OP_MAP
            

const BinCommandMap BINARY_OP_MAP[BIN_CMD_COUNT] = {
        {"+", add}, {"add", add}, {"-", subtract}, {"sub", subtract},
        {"subtract", subtract}, {"*", multiply}, {"multiply", multiply}, {"/", divide},
        {"divide",divide}, {"//", integerDivide}, {"div", integerDivide},
        {"mod", modFunction}, {"%", modFunction}, {"^", raise2power}, {"swap", swapXY}, 
        {"mag2", magnitude2D}, {"pyth", magnitude2D}, {"take", moveNtoTop}, 
        {"root", root}  
        }; //end BINARY_OP_MAP 


const ProgCmdMap PROGRAM_CMD_MAP[PROG_CMD_COUNT] = {
        {"quit", quitProgram}, {"set", setProgVariable}, {"width", widthCmd},
        {"length", displayLengthCmd}, {"stackLength", stackLengthCmd},
        {"clear", clearStack}, {"save", saveStack}, {"sum", repeatInput},
        {"load", loadStack}, {"repeat", repeatInput}, {"sequence", repeatInput},
        {"sum", repeatInput}, {"product", repeatInput}, {"radians", trigMode}, 
        {"degrees", trigMode}, {"store", storeVar}, {"sto", storeVar},
        {"-l", loadStack}, {"-s", saveStack}
        }; //end PROGRAM_CMD_MAP


//     +-----------------+                                                         
//     |  Main function  |                                                        
//-----+-----------------+------------------------------------------------------

int main(int argc, char *argv[]) { 
    //Variables used in both argument mode and interface mode 
	MathStack mainStack;                //primary stack
    ProgramVariables progVar;           //contains user modifiable variables 

    //Variables used in interface mode only 
    progVar.exit = false;               //exit program when true
    progVar.prompt = " >>> ";           //User may modify 
    progVar.displayWidth = 36;          //Width of terminal display
    progVar.outputLength = 10;          //Number of stack elements to display
    progVar.maxStackLength = 100;       //Maximum length of stack 
  
    //Variables used in argument mode only 
    string term;                        //Used for parsing arguments 


    //argument mode - performs single RPN calculation and outputs the stack top
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {      //skip over program name at i = 0
            term = argv[i];
            progVar.inputTerms.push_back(term); 
        } //end for
        progVar.error = false;                //assume no errors 
        processInput(mainStack, progVar); 
        if (!progVar.error)                   //display result if no errors
            cout << mainStack.top() << endl; 
        else                                  //if error, display error msg
            cout << progVar.userMessages.back() << endl; 
    } //end if 

    //Interface mode - terminal calculator interface for multiple calculations
    else { 

        
        //Ask user if they'd like to load a previously saved stack
        startupProcedure(mainStack); 

        //Initial time (debugging)
        progVar.time1 = chrono::steady_clock::now();
                               
        do {

            //Display  
            displayOutput(mainStack, progVar);     //display program output
            cout << progVar.prompt;                //display input prompt

            //flush program variables 
            progVar.userMessages.clear();          //flush user messages 
            progVar.error = false;                 //error assumed false 
            progVar.repeatCount.clear();           //flush repeat counts       

            //Extract user input 
            progVar.inputTerms = extractInputTerms(); 

            //start timer (debugging)
            progVar.time1 = chrono::steady_clock::now();

            //process input terms
            processInput(mainStack, progVar); 

        } while(!progVar.exit); 
        exitProcedure(mainStack);
    } //end else 
    return 0;
} //end main



//*****************************************************************************************
//**|  Function Definitions  |*************************************************************
//*****************************************************************************************

void startupProcedure(MathStack &stack) {
    char loadChoice; 
    bool loadSuccessful; 
    cout << "\nWould you like to load a previously saved stack? [Y/n]: ";
    cin >> loadChoice;
    if (loadChoice == 'y' || loadChoice == 'Y') {
        cout << "Loading stack..." << endl; 
        loadSuccessful = loadStackFromFile(stack);
        cout << (loadSuccessful ? "Stack loaded" : "Error loading stack") << endl << endl; 
    } //end if 
} //end startupProcedure

void exitProcedure(MathStack &stack) { 
    char saveChoice; 
    bool saveSuccessful;
    cout << CLEAR_TERMINAL << endl << "Would you like to save the current stack? [Y/n]: ";
    cin >> saveChoice;
    if (saveChoice == 'y' || saveChoice == 'Y') {
        cout << "Saving stack..." << endl;
        stack.reverseStack();
        saveSuccessful = writeStackToFile(stack);  
        cout << (saveSuccessful? "stack saved" : "Error opening stack file") << endl;    
    } //end if 
} //end exitProcedure


bool loadStackFromFile(MathStack &stack) { 
    ifstream stackFile;
    double currentNum; 
    stackFile.open("RPNcalc.stack");
    if (stackFile) { 
        while (stackFile >> currentNum)
            stack.addNum(currentNum);
        stackFile.close();  
        return true;
    } //end if 
    else 
        return false; 
} //end loadStackFromFile

bool writeStackToFile(MathStack stack) {
    ofstream stackFile;
    stackFile.open("RPNcalc.stack", ofstream::out | ofstream::trunc);
    if (stackFile) {
        while (!stack.empty()) 
            stackFile << stack.popTop() << endl; 
         stackFile.close();
    } //end if 
    else 
       return false;  
} //end writeStackToFile



    //*****************************
    //***|  Input Processing   |***
    //*****************************

vector<string> extractInputTerms() {
    string term; 
    vector<string> inputTerms;
    char currentChar,
         lastChar = ' '; //set initially to space to capture first term 

    //Extract input terms 
    do {                   //terminate loop at end of line 
        cin.get(currentChar);                       //extract next char
           
        //if character isn't whitespace, add it to back of term as lowerspace character. 
        if (!isspace(currentChar)) 
            term.push_back(currentChar);  

        //Terms end when current char is space and last char is not. 
        //After terms end, they're added to the term list, and term is flushed. 
        if (isspace(currentChar) && !isspace(lastChar)) {
            inputTerms.push_back(term); 
            term.clear();                             
        } //end if

        lastChar = currentChar; 
    } while (currentChar != '\n'); 
    return inputTerms; 
} //end extractInputTerms


void processInput(MathStack &stack, ProgramVariables &progVar) {
    bool opSuccess;          //indicates that attempted operation was successful 
    string term;
    if (progVar.inputTerms.empty()) 
        stack.addNum(stack.top());
    else {
        progVar.index = 0;                        //flush index 
        while (progVar.index < progVar.inputTerms.size() && !progVar.error) { 
            term = progVar.inputTerms[progVar.index];

            opSuccess = addNumber(term, stack, progVar);
            if (!opSuccess) 
                opSuccess = performBinaryOperation(toLowercase(term), stack); 
            if (!opSuccess) 
                opSuccess = performUnaryOperation(toLowercase(term), stack); 
            if (!opSuccess) 
                opSuccess = addConstant(term, stack); //case sensitive  
            if (!opSuccess) 
                opSuccess = executeProgCmd(toLowercase(term), stack, progVar);
            if (!opSuccess) 
                opSuccess = recallVariable(toLowercase(term), stack, progVar);

            if (!opSuccess) {
                progVar.userMessages.push_front("Error! Invalid input: " + term);
                progVar.error = true;
            } //end if (!opSuccess)
            else
                progVar.index++;
        } //end while 
    } //end else 
} //end process input


bool addNumber(string input, MathStack &stack, ProgramVariables &progVar) { 
    bool operationSuccess; 
    try {                           
        stack.addNum(stod(input));
        operationSuccess = true; 
        if (stack.size() > progVar.maxStackLength)
            stack.trimStack(progVar.maxStackLength);
    } //end try
    catch (out_of_range& e) {         //In case number is out of range 
        progVar.userMessages.push_front("Error! Out of range: " + input);
        progVar.error = true;
        operationSuccess = true;
    } //end catch 
    catch (invalid_argument& r) {
        operationSuccess = false; 
    } //Go on if number conversion unsuccessful 
    return operationSuccess; 
} //end addNumber


bool executeProgCmd(string input, MathStack &stack, ProgramVariables &progVar) {
    bool operationSuccess = false;         //assume operation is unsuccessful until it is 
    int i = 0;                             //for array iteration 
    while (!operationSuccess && i < PROG_CMD_COUNT) {
        if (input == PROGRAM_CMD_MAP[i].inputCommand) {
            PROGRAM_CMD_MAP[i].functionPtr(stack, progVar);
            operationSuccess = true;
	    } //end if
	    i++;
    } //end while
    return operationSuccess;
} //end executeProgCmd


bool addConstant(string input, MathStack &stack) {
    bool operationSuccess = false;         //assume operation is unsuccessful until it is 
    int i = 0;                             //for array iteration 
    while (!operationSuccess && i < CONST_CMD_COUNT) {
        if (input == CONSTANT_MAP[i].inputCommand) {
            stack.addNum(CONSTANT_MAP[i].constantValue);
	        operationSuccess = true;
	    } //end if
	    i++;
    } //end while
    return operationSuccess;
} //end addConstant 


bool performUnaryOperation(string input, MathStack &stack) {
    bool operationSuccess = false;         //assume operation is unsuccessful until it is 
    int i = 0;                             //for array iteration 
    while (!operationSuccess && i < UN_CMD_COUNT) {
        if (input == UNARY_OP_MAP[i].inputCommand) {
            if (UNARY_OP_MAP[i].convertTrigInput && !stack.radianMode) {
                degToRad(stack);
                UNARY_OP_MAP[i].functionPtr(stack);
            } //end if 
            else if (UNARY_OP_MAP[i].convertTrigOutput 
                     && !stack.radianMode) {
                UNARY_OP_MAP[i].functionPtr(stack);
                radToDeg(stack); 
            } //end else if 
            else 
                UNARY_OP_MAP[i].functionPtr(stack);
            operationSuccess = true;
	    } //end if
	    i++;
    } //end while
    return operationSuccess;
} //end performUnaryOperation   


bool performBinaryOperation(string input, MathStack &stack) {
    bool operationSuccess = false;         //assume operation is unsuccessful until it is 
    int i = 0;                             //for array iteration 
    double lastIn;
    while (!operationSuccess && i < BIN_CMD_COUNT) {
        if (input == BINARY_OP_MAP[i].inputCommand) {
            lastIn = stack.popTop();
            BINARY_OP_MAP[i].functionPtr(stack, lastIn);
            operationSuccess = true;
	    } //end if
	    i++;
    } //end while
    return operationSuccess;
} //end performBinaryOperation


bool recallVariable(string input, MathStack &stack, ProgramVariables &progVar) {
    bool operationSuccess;
    try {
        stack.addNum(progVar.userVariables.at(input));
        operationSuccess = true; 
    }
    catch (out_of_range& e) {
        operationSuccess = false;
    } //end catch
    return operationSuccess; 
} //end recallVariable

string toLowercase(string str) { 
    for (int i = 0; i < str.size(); i++) 
        str[i] += (str[i] > 64 && str[i] < 91) * 32; 
    return str; 
} //end toLowercase
   

//       +----------------------+
//       |  Output Generating   |     
//-------+----------------------+----------------------------------------------



void displayOutput(MathStack &stack, ProgramVariables &progVar) {
    list<double> outputList = stack.topNreversed(progVar.outputLength);
    string lastInput; 

    //stop timer, record difference, and add execution time to user messages 
    progVar.time2 = chrono::steady_clock::now();
    progVar.timeSpan = chrono::duration_cast<chrono::duration<double>>
                                               (progVar.time2  - progVar.time1);
    //Add user messages
    lastInput = "Last Input:";
    for (string term : progVar.inputTerms)
        lastInput += " " + term; 
    progVar.userMessages.push_front(lastInput); 
    progVar.userMessages.push_front("Execution time: "   
                                    + to_string(progVar.timeSpan.count()) + 's');

    //display output 
    cout << CLEAR_TERMINAL << endl << GREETING <<  endl;
    drawLine(progVar.displayWidth);
    cout << setprecision(16);       //some operations seem to break down past 16 digits
    for (int i = progVar.outputLength; i > 0; i--) {
        cout << " |" << setw(2) << right << i << ": " 
             << left << setw(progVar.displayWidth - 6) 
             << outputList.front() << "| ";
        if (!progVar.userMessages.empty()) {
            cout << (i != 1? "-> " + progVar.userMessages.front() : "..."); 
            progVar.userMessages.pop_front();
        } //end if 
        cout << endl; 
        outputList.pop_front(); 
    } //end for
    drawLine(progVar.displayWidth); 
} //end displayOutput


void drawLine(int lineWidth) {
    string line (lineWidth - 2, '-');
    cout << " +" << line << '+' << endl;
} //end drawLine


    //*************************************
    //***|  Program Command Functions  |***
    //*************************************

void quitProgram(MathStack &stack, ProgramVariables &progVar) 
    { progVar.exit = true; } 
    
void clearStack(MathStack &stack, ProgramVariables &progVar) 
    { stack.clearStack(); }

void saveStack(MathStack &stack, ProgramVariables &progVar) 
    { writeStackToFile(stack); }

void loadStack(MathStack &stack, ProgramVariables &progVar) 
    { loadStackFromFile(stack); }

void widthCmd(MathStack &stack, ProgramVariables &progVar) {
    progVar.userMessages.push_front("Display width: " 
                                    + to_string(progVar.displayWidth) 
                                    +" characters"); 
} //end showWidth

void displayLengthCmd(MathStack &stack, ProgramVariables &progVar) {
    progVar.userMessages.push_front("Display Length: " 
                                    + to_string(progVar.outputLength)
                                    + " stack elements");
} //end showDisplayLength

void stackLengthCmd(MathStack &stack, ProgramVariables &progVar) {
    progVar.userMessages.push_front("Max stack length: " 
                                    + to_string(progVar.maxStackLength)
                                    + " stack elements");
} //end showStackLength

void trigMode(MathStack &stack, ProgramVariables &progVar) { 
   string mode = stack.radianMode? "radians" : "degrees";
   progVar.userMessages.push_front("Trig Mode: " + mode);
} //end trigMode 

void setProgVariable(MathStack &stack, ProgramVariables &progVar) {
    string nextTerm = progVar.inputTerms[progVar.index + 1];

    //look ahead to next term to see what to set 
    if (nextTerm == "length") 
        progVar.outputLength = stack.popTop();
    else if (nextTerm == "width") 
        progVar.displayWidth = stack.popTop();
    else if (nextTerm == "stackLength")
        progVar.maxStackLength = stack.popTop();
    else if (nextTerm == "radians") {
        stack.radianMode = true;
    } //end else if 
    else if (nextTerm == "degrees") {
        stack.radianMode = false; 
    } //end else if 
    else {
        progVar.error = true; 
        progVar.userMessages.push_front("Error! Invalid set: " + nextTerm);
    } //end else 
} //end setProgVariable 

void repeatInput(MathStack &stack, ProgramVariables &progVar) {
    int index = progVar.index;
    string term = progVar.inputTerms[index];

    //remove the last repeat number from the stack every time repeat is called 
    stack.pop(); 
    
    //initialize progVar.repeatCount if not already. 
    if (progVar.repeatCount.empty()) {
        initializeRepeatCount(term, progVar); 
    } //end if 

    //Behavior for specific repeat commands 
    //Switch to command -> function pointer map if list grows larger 
    if (term == "sum") 
        add(stack, stack.popTop());
    else if (term == "product") 
        multiply(stack, stack.popTop()); 
    else if (term == "sequence" && progVar.repeatCount[index] > 1)
        stack.addNum(stack.top());

    //If more repeats needed 
    if (progVar.repeatCount[index] > 1) { 
        progVar.repeatCount[index]--;
        progVar.index = -1;   //will be incremented up to 0 in processInput 
    } //end if 
    //if on last repeat, reset count  and move on with line 
    else if (progVar.repeatCount[index] == 1 
             && progVar.repeatCount.upper_bound(index) 
             != progVar.repeatCount.end()) {
        progVar.repeatCount[index] = abs(stoi(progVar.inputTerms[index-1])); 
    } //end else if  
} //end repeatInput

void initializeRepeatCount(string term, ProgramVariables &progVar) { 
    for (int i = 0; i < progVar.inputTerms.size(); i++) {
        term = progVar.inputTerms[i];
        if (term == "repeat" || term == "sequence" || term == "sum"
            || term == "product") {
            try { 
                progVar.repeatCount.insert(pair<int,int>(i, 
                                           abs(stoi(progVar.inputTerms[i-1]))));
            } //end try
            catch (invalid_argument& r) {
                progVar.error = true; 
                progVar.userMessages.push_front("Error! Invalid repeat times: " 
                                                + progVar.inputTerms[i-1]);
            } //end catch

            //If count initially set to 0, infinite loop will result
            if (progVar.repeatCount[i] == 0) {
                progVar.error = true; 
                progVar.userMessages.push_front("Error! Cannot repeat 0 times"); 
            } //end if (progVar.repeatCount[i] == 0)     
        } //end if  
    }//end for 
} //end initializeRepeatCount

void storeVar(MathStack &stack, ProgramVariables &progVar) {
    string varName = progVar.inputTerms[progVar.index + 1];
    for (int i = 0; i < TOTAL_CMD_COUNT; i++) {
        if (varName == RESERVED_WORDS[i]) { 
            progVar.error = true;
            progVar.userMessages.push_front("Error! Invalid Variable Name: "
                                            + varName); 
        } //end if
    } //end for  
    if (!progVar.error) { 
        double value = stack.top();
        //if variable already exists, update it, else create new variable
        try {
            progVar.userVariables.at(varName) = value;
        } //end try 
        catch (out_of_range &e) {
            progVar.userVariables.insert(pair<string,double>(varName, value)); 
        } //end catch
        progVar.index++; 
    } //end if 
} //end storeVar





//THE GRAVEYARD_______________________________________________________________



/*
void setProgVariable(MathStack &stack, ProgramVariables &progVar) {
    int i = 0; 
    bool found = false;                          
    progVar.set = true;         
    string nextTerm = progVar.inputTerms[progVar.index + 1];   //look-ahead at next term
  
    while (!found && i < SET_CMD_COUNT) {
        if (nextTerm == SET_CMD_MAP[i].inputCommand) {
            SET_CMD_MAP[i].functionPtr(stack, progVar);
            found = true;
	    } //end if
	    i++;
    } //end while 
    if (!found) {
        progVar.error = true; 
        progVar.userMessages.push_front("Error! Invalid set: " + nextTerm);
    } //end if
} //end setProgVariable 
*/

