////
// Name: Nancy Programmer
// Section: A, B, or S
// Program Name: MYString Tester 
//
// Description: A brief description of the program.  What does the 
//  program do (not how it does it: for example, it uses loops)?  Does 
//  the program get input?  What kind?  What information is output 
//  from the program and to where (screen or file)
////

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "ANString.h"

using namespace std;
void output(vector<ANString>& vect);
void BubbleSort(vector <ANString>& vect);

int main() {

    vector<ANString> words(100);        // calls default constructor 100 times
    ifstream fin("infile2.txt");

    // READ
    if (fin.fail()) {
        cout << "Couldn't open infile2.txt" << endl;
        system("pause");
        exit(1);
    }

    int wordCnt = 0;
    for (; words[wordCnt].read(fin); ++wordCnt) {       // empty loop
        // cout << words[wordCnt].c_str() << '\t';      // for verifying input
    }
    words.resize(wordCnt);            //shrink vector to size used

    // You need to write the rest

    // SORT
}
    void BubbleSort(vector <ANString>&vect)
    {

        bool change = true;
        while (change == true)
        {
            change = false;
            for (int i = 0; i < vect.size() - 1; i++)
            {
                // [debug statements] cout << (vect.at(i).c_str()) << " " << (vect.at(i + 1).c_str()) << endl;
                if (vect[i].greaterThan( vect[i + 1]))
                {
                    change = true;
                    swap(vect[i], vect[i + 1]);
                    // cout << (vect.at(i).c_str()) << " " << (vect.at(i + 1).c_str()) << endl;
                }
            }

        }
    }
    
    // OUTPUT
    void output(vector<ANString>& vect)
    {

        ofstream fout("outfile.txt");

        for (int i = 0; i < vect.size() - 1; i++)
        {    // += 6 needed so it doesn't repeat one of the 6 values on each line
          //  fout << left << setw(13) << vect.at(i).c_str() << vect.at(i).length() << ":" << vect.at(i).capacity() << endl;

              for (int j = 0; j < 6; j++) // nested loop to only output 6 words per line
              {
                   fout << left << setw(13) << vect.at(i+j).c_str();
              }
              fout << endl;
        }
 
        fout.close();
        fout.clear();
    }
       



