# RPNcalc

RPNcalc is a terminal based reverse polish notation calculator that utilizes a 
stack to hold added and computed values. 

Reverse polish notation, or RPN, is a postfix mathematical notation, which means
that the operators, such as '+' and '-', follow the operands rather than being 
placed in between them. For example, the infix operation '2 + 2' would translate
to '2 2 +' in RPN. The benefit of using RPN notation is that it eliminates the
need for operator precedence and parenthesis. In standard mathematical notation
'2 + 2 * 10' is equivalent to '2 + (2 * 10)', so parenthesis will have to be 
used if '(2 + 2) * 10' is desired. In RPN notation, however, the order of the 
operators and operands is all that is necessary to differentiate the two:   
'2 + (2 * 10)' is equivalent to '2 10 * 2 +' or '2 2 10 * +' and 
'(2 + 2) * 10' is equivalent to '2 2 + 10 *' or '10 2 2 + *'. Notice, operators
are applied one at a time, from left to right, on the previous operands, using
the result of any previous operations in place of the original operands.

In RPNcalc, All values and commands are entered at the prompt. The user may 
enter as many commands and/or values, separated by spaces, as will fit on the 
input line. Press [return] to send the input to the calculator. If the input is
empty and enter is pressed, the top element of the stack is doubled. Numbers in
the input line are added to the stack and operators act on either the top 
element of the stack if a unary operator, or the top two elements of the stack 
if a binary operator. For non-commutative operations, such as subtraction and 
division, operands are ordered as they would be in the infix equivalent. For 
example, '2 3 /' is equivalent to '2 / 3' and '2 3 -' is equivalent to '2 - 3'.

 
By default, the top ten stack elements will be displayed above the input prompt.  

Mathematical and program commands are case-insensitive. User variable names,
program variable names, and units are case-sensitive. 

