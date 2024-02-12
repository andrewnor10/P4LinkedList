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
	int getCount();
	void resetIteration();
	ANString next();
	bool hasMore();
	bool push_Back(ANString str);

	bool testConnections();

	// member data

	Node* head;
	Node* tail;
	mutable Node* it;
	int count;

};
ostream& operator<<(ostream& ostrm, const DoubleLinkedList& dll);

#endif // !DoubleLinkedList

