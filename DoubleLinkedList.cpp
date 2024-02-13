#include "DoubleLinkedList.h"
#include "Node.h"
#include "ANString.h"

int DoubleLinkedList::count = 0;

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
	
	this->resetIteration();
	/*for (; it != nullptr; next())
	{

		if (temp->data > it->data)
		{

		}
	}*/
	if (head == nullptr)
	{
		head = temp;
	}
	if (temp->data > head->data)
	{
		head->prev = temp;
		temp->next = head;
		head = temp;
	}
	if (temp->data < tail->data)
	{
		(tail)->next = temp;
		temp->prev = tail;
		tail = temp;
	}

	count++;
	return temp;
	
}
/*bool remove(const ANString& str)
{

}
int getCount()
{

}*/

ANString DoubleLinkedList::next()
{
	it = it->next;
	return it->data;
}
bool DoubleLinkedList::hasMore()
{
	return it != nullptr ? true : false;
} 
void DoubleLinkedList::resetIteration()
{
	it = head;
}

bool DoubleLinkedList::push_Back(ANString str)
{
	Node* temp;
	temp = new Node;
	temp->data = str;
	if (head == nullptr)
	{
		head = temp;
	}

	this->tail = temp;
	count++;
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