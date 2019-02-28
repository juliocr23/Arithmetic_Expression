/*
* ArithmeticExpression.h
*
*  Created on: Apr 29, 2017
*      Author: julio
*	Purpose: The purpose of this class is to implement the header file.
*/

#include "ArithmeticExpression.h"
#include "Stack.h"
#include "string"
#include <iostream>
using namespace std;
istream& operator>>(istream& in,ArithmeticExpression& expression)
{
	getline(in, expression.input);
	return in;
}

/*
__________________________________________________
					To Test 
Cases:

{x,/,+,-} {x,/,-,+} {x,+,/,-} {x,+,-,/} {x,-,/,+} 
{x,-,+,/} {/,x,+,-} {/,x,-,+} {/,+,x,-} {/,+,-,x}
{/,-,x,+} {/,-,+,x} {+,x,/,-} {+,x,-,/} {+,/,x,-}
{+,/,-,x} {+,-,x,/} {+,-,/,x} {-,x,/,+} {-,x,+,/}
{-,/,x,+} {-,/,+,x} {-,+,x,/} {-,+,/,x}
  */
void ArithmeticExpression::evaluateExpression()
{
	string temp;
	Stack<int> integers;    //Hold the integers
	Stack<char> operators;  //Hold the operators.
	char isNegative = 'N'; //To tell whether there is a negative number.

	/*
		Note:
		    N = no operators.
			Y = operators.
			T = a negative.
	*/

	for (int i = 0; i < input.length(); i++)
	{
		if (isdigit(input[i])){	//Get integer if it is a digit.

			//There Could be more than one digit.
			while (isdigit(input[i]))
			{
				temp += input[i];
				i++;
			}

			//If it is negative convert, multiply integer by -1 and push.
			if (isNegative == 'T')	
				integers.push(stoi(temp)*-1);	

			else	//otherwise convert and push integer.
				integers.push(stoi(temp));	
			
			isNegative = 'N';
			temp = "";
			i--;

			//There could be only one * or / left in the operators stack.
			if (operators.getTop() == '*' || operators.getTop() == '/')
				calculate(operators, integers);
		}
		else if(input[i] != ' '){	//Otherwise, if it is not white space, it is an operator.

			if (input[i] == '(')
				operators.push(input[i]);
			else if (input[i] == ')')
			{
				//Do what's inside the parentheses.
				while (!operators.isEmpty() && operators.getTop() != '(')
				{
					hasPrecedence(operators, integers, input[i]);
				}
				operators.pop(); //Remove (
			}
			else if (isNegative == 'N') {	//As long as it is not negative it is an operator.

				isNegative = 'Y';	   //Signal that we just had an operator.

				hasPrecedence(operators, integers, input[i]);	//Determine if it has Precedence
																// and if does caculate char,val1,val2
				operators.push(input[i]);	//Push new operator.
			}
			else
				isNegative = 'T';
		}
	}

	//There could be + or - left.
	while (!operators.isEmpty())
	{
		calculate(operators, integers);
	}
	value = integers.getTop();
}

void ArithmeticExpression::calculate(Stack<char>& operators,Stack<int>& integers)
{
	char symbol = operators.getTop();
	operators.pop();

	int val2 = integers.getTop();
	integers.pop();

	int val1 = integers.getTop();
	integers.pop();

	switch (symbol)
	{
		case '+': 
			integers.push(val1+val2);
			break;
		case '-':
			integers.push(val1 - val2);
			break;
		case '*':
			integers.push(val1 * val2);
			break;

		case '/':
			if (val2 != 0)
			{
				integers.push(val1/val2);
				break;
			}
			else
				std::cout << "\nSorry, Can't divive by Zero\n";
	}
}

void ArithmeticExpression::hasPrecedence(Stack<char>& operators, Stack<int>& integers,char input)
{
	//Calculate char,val1,val2 if it is * or /
	if (operators.getTop() == '*' || operators.getTop() == '/')
		calculate(operators, integers);

	//Calculate + or - if the next input is not * or /
	else if ((operators.getTop() == '+' || operators.getTop() == '-') &&
			(input != '*' && input != '/'))
		calculate(operators, integers);
}

ostream& operator<<(ostream& out, ArithmeticExpression& expression)
{
	expression.evaluateExpression();
	return out << expression.value;
}

ArithmeticExpression:: ArithmeticExpression()
{value = 0;}






