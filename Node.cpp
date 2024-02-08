#include "Node.h"
#include "ANString.h"

Node::Node()
{
	next = nullptr;
	prev = nullptr;

}

Node::Node(const ANString str)
{
	data = str;
	next = nullptr;
}