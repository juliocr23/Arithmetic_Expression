/*
 * ArithmeticExpression.h
 *
 *  Created on: Apr 29, 2017
 *      Author: julio
 *	Purpose: The purpose of this class is to evaluate an arithmetic expression.
 */

#ifndef ARITHMETICEXPRESSION_H_
#define ARITHMETICEXPRESSION_H_
#include "Stack.h"
#include "Stack.cpp"
#include <iostream>
using namespace std;

class ArithmeticExpression
{
private:
	int value;		//The result.
	string input;	//User input.

public:
	friend ostream& operator<<(ostream& out,ArithmeticExpression&);	//Output Arithmetic expression
	friend istream& operator>>(istream& in,ArithmeticExpression&);  //Input Arithmetic expression
	
	ArithmeticExpression();	//Constructor.
	void evaluateExpression();	//Evaluate the expression.


	void calculate(Stack<char>&, Stack<int>&);	//Calculate char,val1 and val2 
	void hasPrecedence(Stack<char>&,Stack<int>&,char input); //Check for predence
	
};





#endif /* ARITHMETICEXPRESSION_H_ */
