////
// Name: Andrew Norton
// Section: CS 132 Winter 24
// Class Name: ANString
//
// Description: This class holds a C String, keeps count of
// its objects it creates, and uses overloaded operators for 
// functionality.
////

#ifndef ANSTRING_H
#define ANSTRING_H

#include <istream>

using namespace std;

class ANString {    
                    
public:
	ANString();						// default constructor
	ANString(const ANString& mstr); // Copy Constructor
	ANString(const char* cstr);		// cstring constructor
	~ANString();					// Destructor

	ANString operator= (const ANString& rvalue); // Assignment operator
	ANString operator+(const ANString& rvalue); // Plus operator
	char operator[] (int index);	// non const Index operator
	friend istream& operator>>(istream& istrm, ANString& string) { // write for operator (was write function)
		char inputWord[100];
		if (istrm >> inputWord) {
			for (string.end = 0; inputWord[string.end] != '\0'; ++string.end);  			//empty loop

			if (string.end >= string.cap)
			{
				string.cap = 20 * (string.end / 20 + 1);
				delete[] string.str;
				string.str = new char[string.cap];
			}

			//  if (end >= cap) cap = 20 * (end/20 + 1) possibly?
			for (int i = 0; i <= string.end; ++i) {
				string.str[i] = inputWord[i];
			}
			if (std::ispunct(string.str[string.end - 1]))
			{

				string.str[string.end - 1] = '\0';
				string.end -= 1;
			}
		}
		return istrm;
	}
	
	bool operator<(const ANString& argStr); // less than conditional operator
	bool operator>(const ANString& argStr); // greater than conditional operator
	bool operator==(const ANString& argStr); // equal to conditional operator
	bool operator!=(const ANString& argStr); // not equal to conditional operator
	
	int length();
	int capacity();
	static int getCurrentCount();
	static int getCreatedCount();

	const char* c_str() const;

private:
	char* str;
	int end;
	int cap;
	static int currentCount;
	static int createdCount;
};
ostream& operator<<(ostream& ostrm, const ANString& string);

#endif

