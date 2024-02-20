#include "DoubleLinkedList.h"
#include "Node.h"
#include "ANString.h"
#include <iostream>


DoubleLinkedList::DoubleLinkedList()
{
	head = nullptr;
	tail = nullptr;
	it = nullptr;
	count = 0;
}
DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& dll) // WIP
{
	head = nullptr;
	tail = nullptr;
	count = 0;
	dll.resetIteration();
	while (dll.hasMore())
	{
		push_Back(dll.next());
		
	}
}

DoubleLinkedList::~DoubleLinkedList()
{
	Node* trailer;
	resetIteration();
	while (hasMore())
	{
		trailer = it;
		it = it->next;
		delete trailer;
		count--;
	}

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
		it = head;
		while (hasMore())
		{
			
			if (temp->data < it->data)
			{
				temp->next = it;
				temp->prev = it->prev;
				it->prev = temp;
				temp->prev->next = temp;
				count++;
				
				return true;
			}
			else if (temp->data == it->data)
			{
				delete temp;
				return false;
			}
			next();
		}
	}

	count++;

	return true;
	
}
bool DoubleLinkedList::remove(const ANString& str)
{
	Node* temp;

	if (head == nullptr)
	{
		return false;
	}
	else if (head->data == str)
	{
		if (head->next != nullptr)
		{
			temp = head;
			head->next->prev = nullptr;
			head = head->next;
			delete temp;
		}
		else
		{
			delete head;
		}
	}
	else if (tail->data == str)
	{
		if (tail->prev != nullptr)
		{
			temp = tail;
			tail->prev->next = nullptr;
			tail = tail->prev;
			
			delete temp;
		}
	}
	else
	{
		it = head->next;
		while (hasMore())
		{
			if (it->data == str)
			{
				temp = it;
				it->prev->next = it->next;
				it->next->prev = it->prev;
				
				delete temp;
					
				}
			next();


		}
		return false;
	}

	return true;
}
int DoubleLinkedList::getCount()
{
	return count;
}

ANString DoubleLinkedList::next() const
{
	ANString str = it->data;
	it = it->next;
	return str;
}
bool DoubleLinkedList::hasMore() const
{
	return it != nullptr ? true : false;
} 
void DoubleLinkedList::resetIteration() const
{
	it = head;
}

bool DoubleLinkedList::push_Back(ANString str)
{
	Node* temp;
	temp = new Node(str);
	if (head == nullptr)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
	
	count++;
	return true;
}

bool DoubleLinkedList::testConnections()
{
	resetIteration();
	if (head == nullptr)
	{
		return false;
	}
	else while (hasMore())
	{
		
		if (it->next != nullptr)
		{
			if (it->next->prev != it)
			{
				return false;
			}
		}
	}
	return true;
}

ostream& operator<<(ostream& ostrm, const DoubleLinkedList& dll)
{
	ostrm << dll.head->data;
	return ostrm;
}