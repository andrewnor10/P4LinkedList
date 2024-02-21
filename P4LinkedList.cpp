////
// Name: Andrew Norton
// Section: CS 132
// Program Name: Linked List
//
// Description: A linked list data structure, using ANStrings. List is doubley linked and contains 
// no duplicates. The list is alphabetically sorted. This program outputs 4 different lists
// counts at different points to show where in the program it is to console, 
// as well as the total numberof strings and current # of strings at the end of the program.
// 
// Modified list 1 & 2 also output their lists into their own respective output files.
////


#include <iostream>
#include <fstream>
#include "DoubleLinkedList.h"
#include "Node.h"
#include "ANString.h"

void changer(DoubleLinkedList list);


int main()
{
    DoubleLinkedList list1, list2, mod1, mod2;
    ANString string;
    ifstream fin("infile1.txt");
    ifstream fin2;
    ofstream fout("outfile1.txt");
    ofstream fout2("outfile2.txt");

    while (fin >> string)
    {
        list1.insert(string);
    }
    fin.close();

    fin2.open("infile2.txt");
    while (fin2 >> string)
    {
        list2.insert(string);
    }
  // Cout 4 lists size with explanation
    cout << "List 1 size: " << list1.getCount() << ", List 2 size: " << list2.getCount()
        << ",\n" << "Modified list 1 size: " << mod1.getCount() << ", modified list 2 size: " << mod2.getCount();

    // Start of modified list related code
    mod1 = list1;
    mod2 = list2;
    
 
    list2.resetIteration();
    while (list2.hasMore())
    {
        mod1.remove(list2.it->data);
        list2.next();
    }
    list1.resetIteration();
    while (list1.hasMore())
    {
        mod2.remove(list1.it->data);
        list1.next();
    }

    // Next size check
    cout << "\nList 1 size: " << list1.getCount() << ", List 2 size: " << list2.getCount()
        << ",\n" << "Modified list 1 size: " << mod1.getCount() << ", modified list 2 size: " << mod2.getCount();

/*mod1.resetIteration();
while (mod1.hasMore())
{
    cout << mod1.next() << " ";
} // Debug code to output all the strings as ordered in list */

    changer(mod1);
    changer(mod2);
   
    // Next size check
    cout << "\nList 1 size: " << list1.getCount() << ", List 2 size: " << list2.getCount()
        << ",\n" << "Modified list 1 size: " << mod1.getCount() << ", modified list 2 size: " << mod2.getCount();

    // cout ANString object counts
    cout << "\nCurrent number of ANString objects: " << ANString::getCurrentCount();
    cout << "\nTotal number of ANString objects created: " << ANString::getCreatedCount();

    mod1.resetIteration();
    while (mod1.hasMore())
    {
        fout << mod1.next() << " ";
    }
    mod2.resetIteration();
    while (mod2.hasMore())
    {
        fout2 << mod2.next() << " ";
    }
    fout.close();
    fout2.close();

    return 0;
}
void changer(DoubleLinkedList list)
{
    ANString str = "ZIP";
    ANString str1 = "Zap";

    list.insert(str);
    list.insert(str1);
    cout << "\nInside changer size is: " << list.getCount() << endl;
}

