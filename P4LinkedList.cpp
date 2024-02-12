// P4LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "DoubleLinkedList.h"
#include "Node.h"
#include "ANString.h"

int main()
{
    DoubleLinkedList dll;
    ANString string;
    cin >> string;

    dll.push_Back(string);
    cout << dll;

    return 0;
}

