/*
 * Stack.h
 *
 *  Created on: Apr 29, 2017
 *      Author: julio
		Purpose: The purpose of this class is to create a stack.
 */

#ifndef STACK_H_
#define STACK_H_
#include "Node.h"

template<class T>
class Stack
{
private:
	Node<T>* stack;
	void copy(const Stack&);	//Copy a stack.
public:
	Stack();	//Constructor
	~Stack();  //Destructor.

	Stack(const Stack&);			//Copy constructor.
	void operator=(const Stack&);  //Copy  a Stack.

	void push(T);	//Store an item at the top of the stack.
	void pop();    //Delete Item at the top of the stack.
	T getTop();   //Return the information at the top of the stack.

	bool isEmpty(); //Return true if list is empty return false otherwise.
	bool isFull();  //Return True  if list is full otherwise return false.
};





#endif /* STACK_H_ */
