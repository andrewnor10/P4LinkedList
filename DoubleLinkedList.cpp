#include "DoubleLinkedList.h"
#include "Node.h"
#include "ANString.h"

DoubleLinkedList::DoubleLinkedList()
{
	head = nullptr;
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

DoubleLinkedList::~DoubleLinkedList()
{

}

DoubleLinkedList DoubleLinkedList::operator=(const DoubleLinkedList& dll)
{
	head = new Node(*dll.head);
	tail = new Node(*dll.tail);
	it = head;
	count = dll.count;
	return (*this);
}
bool DoubleLinkedList::insert(const ANString& str)
{
	Node* temp;
	temp = new Node(str);
	temp->next = nullptr;
	head = temp;
	tail = temp;
	return temp;
	
}
/*bool remove(const ANString& str)
{

}
int getCount()
{

}

ANString next()
{

}
bool hasMore()
{

} */
void DoubleLinkedList::resetIteration()
{
	it = head;
}

bool DoubleLinkedList::push_Back(ANString str)
{
	Node* temp;
	temp = new Node;
	temp->next = nullptr;
	temp->data = str;
	if (head == nullptr)
	{
		head = temp;
	}
	this->tail = temp;
	return true;
}

/*bool testConnections()
{

}*/

ostream& operator<<(ostream& ostrm, const DoubleLinkedList& dll)
{
	ostrm << dll.head->data;
	return ostrm;
}