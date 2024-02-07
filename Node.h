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