#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
#include <cstdlib> // For exit() function
#include<string>
using namespace::std;
class MyString {
private:
	char* str;
	int len;
public:
	// Constructors
	MyString(); // { str = ""; len = 0; }
	MyString(char*);
	MyString(const MyString&);
	// Destructor
	~MyString() { if (len != 0) delete[] str; }
	// Various member functions and operators
	int length() { return len; }
	const char* data() const { return str; };
    MyString& operator=(const MyString &right);
    MyString& operator+=(const MyString &right);
    // Various overloaded operators
    friend bool operator==(const MyString&, const MyString&);
    friend bool operator!=(const MyString&, const MyString&);
    friend bool operator>(const MyString&, const MyString&);
    friend bool operator<(const MyString&, const MyString&);
    friend bool operator>=(const MyString&, const MyString&);
    friend bool operator<=(const MyString&, const MyString&);
    friend ostream& operator<<(ostream&, const MyString&);
    friend istream& operator>>(istream&, MyString&);
};
#endif
