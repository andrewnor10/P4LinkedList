////
// Name: Andrew Norton
// Section: CS 132 Winter 24
// Program Name: Double Linked List
//
// Description: This is the header for a node class
// in a doubley linked list. Each node can only hold
// a ANString piece of data, as well as a pointer to the next
// or previous node in the list.
////

#ifndef Node_H
#define Node_H
#include "ANString.h"

class Node {
public:
	// Constructors
	Node();
	Node(ANString str);

	// Data
	ANString data;
	Node* next;
	Node* prev;

};
#endif Node_H