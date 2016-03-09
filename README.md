# RPNcalc

RPNcalc is a terminal based reverse polish notation calculator that utilizes a stack to hold added and computed values. The aim is to create a terminal based RPN calculator that is not only fast and lightweight, but also feature-rich and powerful.  


In RPNcalc, All values and commands are entered at the prompt. The user may enter as many commands and/or values, separated by spaces, as will fit on the input line. Pressing [return] will send the input to the calculator. If the input is empty and enter is pressed, the top element of the stack will be copied and added back to the stack. Numbers in the input line are added to the stack and operators act on either the top element of the stack if a unary operator, or the top two elements of the stack if a binary operator. For non-commutative operations, such as subtraction and division, operands are ordered as they would be in the equivalent infix operation. For example, '2 3 /' is equivalent to '2 / 3' and '2 3 -' is equivalent to '2 - 3'.

 
By default, the top ten stack elements will be displayed above the input prompt. However, this can be changed by the user, along with several other program variables, by using the 'set' command.  

Mathematical and program commands are case-insensitive. User variable names, program variable names, and units are case-sensitive. 


## Features:
* An arbitrary number of operators and operands can be input simultaneously. 
* Many common arithmetical and trigonometric  functions.
* Ability to store values into a user defined variable name with 'sto' command. 
* Ability to change some program variables using the 'set' command, such as the width of the display and the number of stack elements to display.
* Ability to repeat the preceding input line with 'repeat' command and variants such as 'sequence', 'sum', and 'product'. 
* Ability to save the current stack or load a previously saved stack.
* A single input line can be calculated without opening the entire program by adding the input line after the program name when launching from the command line.


## Planed Features 
* Use ncurses library for a more interactive interface.
* Add the ability to use different types of numeric values on the stack such as
  rationals, complex numbers, and vectors with automatic checks for validity of
mixed unit operations. 
* Add functionality for attaching units to values with the ability to combine units algebraically with mixed unit operations. 
* Fully detailed help pages on usage of the program and the usage of individual
  commands which can be opened with the 'help' command. 
