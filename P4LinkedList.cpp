////
// Name: Andrew Norton
// Section: CS 132
// Program Name: Hello World
//
// Description: A brief description of the program.  What does the 
//  program do (not how it does it: for example, it uses loops)?  Does 
//  the program get input?  What kind?  What information is output 
//  from the program and to where (screen or file)
////


#include <iostream>
#include <fstream>
#include "DoubleLinkedList.h"
#include "Node.h"
#include "ANString.h"

void changer(DoubleLinkedList list);


int main()
{
    DoubleLinkedList list1;
    DoubleLinkedList list2;
    ANString string;
    ifstream fin("infile1.txt");
    ifstream fin2;


    while (fin >> string)
    {
        // cout << string << " ";
        list1.insert(string);
        
       // cout << dll.getCount() << endl;
    }
    fin.close();

    fin2.open("infile2.txt");
    while (fin2 >> string)
    {
        list2.insert(string);
    }
  
    list2.resetIteration();
    while (list2.hasMore())
    {
        cout << list2.next() << " ";
    } // Output all the strings in the ordered list */

    cout << endl << list2.getCount();
   
   /* changer(list1);
    cout << list1.getCount(); */
    return 0;
}
void changer(DoubleLinkedList list)
{
    ANString str = "ZIP";
    ANString str1 = "Zap";

    list.insert(str);
    list.insert(str1);
    cout << "Inside changer size is: " << list.getCount() << endl;
}

