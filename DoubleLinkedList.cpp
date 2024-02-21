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
	if (head->next != nullptr)
		it = head->next;
	else
	{
		delete head;
		return;
	}
	while (hasMore())
	{
		delete it->prev;
		it = it->next;
		count--;
	}

}

DoubleLinkedList DoubleLinkedList::operator=(const DoubleLinkedList& dll)
{
	head = nullptr;
	tail = nullptr;
	count = 0;
	dll.resetIteration();
	while (dll.hasMore())
	{
		push_Back(dll.next());

	}
	it = head;
	return *this;
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
		else
		{
			delete tail;
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
				count--;
				return true;
				}
			next();


		}
		return false;
	}
	count--;
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
		temp->prev = tail;
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

/* Console Output
* 
List 1 size: 1104, List 2 size: 1040,
Modified list 1 size: 0, modified list 2 size: 0
List 1 size: 1104, List 2 size: 1040,
Modified list 1 size: 759, modified list 2 size: 695
Inside changer size is: 761

Inside changer size is: 697

List 1 size: 1104, List 2 size: 1040,
Modified list 1 size: 759, modified list 2 size: 695
Current number of ANString objects: 3603
Total number of ANString objects created: 7081664
*/