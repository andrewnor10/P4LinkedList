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

	if (head == nullptr) // Do we have any nodes yet?
	{
		head = tail = temp;
	}
	else if (temp->data < head->data) // Does our new data go at the head?
	{
		head->prev = temp;
		temp->next = head;
		head = temp;
	}
	else if (temp->data > tail->data) // Does it go at the tail?
	{
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}

	else // Ok, where do I go?
	{
		it = head->next;
		while (hasMore())
		{
			
			if (temp->data < it->data)
			{
				temp->next = it;
				temp->prev = it->prev;
				it->prev = temp;
				temp->prev->next = temp;
			}
			else if (temp->data == it->data)
			{
				return false;
			}
			next();
		}
	}

	count++;
	return true;
	
}
/*bool remove(const ANString& str)
{

}
int getCount()
{

}*/

ANString DoubleLinkedList::next()
{
	ANString str = it->data;
	it = it->next;
	return str;
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