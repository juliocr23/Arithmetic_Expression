/*
* ArithmeticExpression.h
*
*  Created on: Apr 29, 2017
*      Author: julio
*	Purpose: The purpose of this class is to implement an stack.
*/
#include "Stack.h"
#include <iostream>

template<class T>
Stack<T>:: Stack()
{
	stack = 0;
}

template<class T>
Stack<T>::~Stack()
{
	if(stack == 0)
		return;
	else
	{
		while(stack!=0)
		{
			pop();
		}
	}
}

template<class T>
Stack<T>::Stack(const Stack<T>& obj)
{
	copy(obj);
}

template<class T>
void Stack<T>::operator =(const Stack<T>& obj)
{
	copy(obj);
}

template<class T>
void Stack<T>::push(T item)
{
	if(isEmpty())
	{
		stack = new Node<T>;
		stack->data = item;
		stack->next = 0;
	}
	else
	{
		//Create newNode
		Node<T>* newNode = new Node<T>;
		newNode->data = item;

		newNode->next = stack;
		stack = newNode;

	}
}

template<class T>
void Stack<T>::pop()
{
	if(isEmpty())
		return;
	else
	{
		Node<T>* temp = stack->next;
		delete stack;
		stack = temp;
	}
}

template<class T>
T Stack<T>:: getTop()
{
	if (!isEmpty())
		return stack->data;
	else
		return 0;
}

template<class T>
bool Stack<T>:: isEmpty()
{
   return stack == 0;
}

template<class T>
bool Stack<T>:: isFull()
{
	return false;
}

template<class T>
void Stack<T>::copy(const Stack<T>& obj)
{
	Node<T>*other = obj.stack;
	Node<T>*traverse = 0;
	while(other != 0)
	{
		//Create the newNode.
		Node<T>*newNode = new Node<T>;
		newNode->data = other->data;
		newNode->next = 0;

		if(stack == 0)
		{
			stack = newNode;
			traverse = stack;
		}
		else
		{
			traverse->next = newNode;
			traverse = newNode;
		}
		other = other->next;
	}
}
