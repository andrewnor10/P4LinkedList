#include "DoubleLinkedList.h"
#include "Node.h"
#include "ANString.h"

DoubleLinkedList::DoubleLinkedList()
{
	head = new Node()
	tail = nullptr;
	it = nullptr;

}
DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& dll)
{
	head = new Node (*dll.head);
	tail = new Node(*dll.tail);
	it = head;
	count = dll.count;
}

DoubleLinkedList