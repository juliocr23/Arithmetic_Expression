/*
 * Node.h
 *
 *  Created on: Apr 29, 2017
 *      Author: julio
 *	Purpose : The purpose of this class is to create a node for a LinkList.
 */

#ifndef NODE_H_
#define NODE_H_

template<class T>
struct Node
{
	T data;
	Node<T>*next;
};

#endif /* NODE_H_ */
