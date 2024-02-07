#ifndef DoubleLinkedList_H
#define DoubleLinkedList_H

#include "ANString.h"

class DoubleLinkedList {
public:
	DoubleLinkedList();
	DoubleLinkedList(const DoubleLinkedList& dll);
	~DoubleLinkedList();

	DoubleLinkedList operator=(const DoubleLinkedList& dll);
	

};
ostream& operator<<(ostream& ostrm, const ANString& string);

#endif // !DoubleLinkedList

