////
// Name: Andrew Norton
// Section: CS 132 Winter 24
// Program Name: Double Linked List
//
// Description: This is the header for a double linked list
// class, to create a double linked list data structure.
// Inserts into the structure is sorted alphabetically
////

#ifndef DoubleLinkedList_H
#define DoubleLinkedList_H

#include "ANString.h"
#include "Node.h"

class DoubleLinkedList {
public:
	DoubleLinkedList();
	DoubleLinkedList(const DoubleLinkedList& dll);
	~DoubleLinkedList();

	DoubleLinkedList operator=(const DoubleLinkedList& dll);
	bool insert(const ANString& str);
	bool remove(const ANString& str);
	void resetIteration() const;
	ANString next() const;
	bool hasMore() const;
	bool push_Back(ANString str);

	bool testConnections();
	int getCount();

	// member data

	Node* head;
	Node* tail;
	mutable Node* it;
	int count;

};
ostream& operator<<(ostream& ostrm, const DoubleLinkedList& dll);

#endif // !DoubleLinkedList

