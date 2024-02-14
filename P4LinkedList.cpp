// P4LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "DoubleLinkedList.h"
#include "Node.h"
#include "ANString.h"

int main()
{
    DoubleLinkedList dll;
    ANString string;
    ifstream fin("infile1.txt");
    
    while (fin >> string)
    {
        cout << string << " ";
        dll.insert(string);
        
        cout << dll.count << endl;
    }

   // dll.push_Back(string);
   

    return 0;
}

