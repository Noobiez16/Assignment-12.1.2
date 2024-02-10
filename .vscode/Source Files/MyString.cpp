#include "MyString.h"
#include <cstring>

// Constructor by default
MyString::MyString() {
    char tmp[] = "";
    len = std::strlen(tmp);
    str = new char[len + 1];
    std::strcpy(str, tmp);
}

// Constructor with parameter char*
MyString::MyString(char* sptr) {
    if (sptr) {
        len = std::strlen(sptr);
        str = new char[len + 1];
        std::strcpy(str, sptr);
    } else {
        len = 0;
        str = new char[1];
        *str = '\0';
    }
}

// Copy constructor
MyString::MyString(const MyString& right) {
    len = right.len;
    str = new char[len + 1];
    std::strcpy(str, right.str);
}

// Destructor
MyString::~MyString() {
    delete[] str;
}

// Overloaded assignment operator
MyString& MyString::operator=(const MyString& right) {
    if (this != &right) {
        char* newStr = new char[right.len + 1];
        std::strcpy(newStr, right.str);
        delete[] str;
        str = newStr;
        len = right.len;
    }
    return *this;
}

// Overloaded += operator
MyString& MyString::operator+=(const MyString& right) {
    int newLen = len + right.len;
    char* newStr = new char[newLen + 1];
    std::strcpy(newStr, str);
    std::strcat(newStr, right.str);
    delete[] str;
    str = newStr;
    len = newLen;
    return *this;
}

// Overloaded comparison operators
bool operator==(const MyString& left, const MyString& right) {
    return std::strcmp(left.str, right.str) == 0;
}

bool operator!=(const MyString& left, const MyString& right) {
    return std::strcmp(left.str, right.str) != 0;
}

bool operator>(const MyString& left, const MyString& right) {
    return std::strcmp(left.str, right.str) > 0;
}

bool operator<(const MyString& left, const MyString& right) {
    return std::strcmp(left.str, right.str) < 0;
}

bool operator>=(const MyString& left, const MyString& right) {
    return std::strcmp(left.str, right.str) >= 0;
}

bool operator<=(const MyString& left, const MyString& right) {
    return std::strcmp(left.str, right.str) <= 0;
}

std::ostream& operator<<(std::ostream& strm, const MyString& obj) {
    strm << obj.str;
    return strm;
}

    // Read the MyString
    std::istream& operator>>(std::istream& strm, MyString& obj) {
    char buffer[256];
    strm.getline(buffer, 256);
    MyString temp(buffer);
    //Invoke the convert constructor and overloaded assignment
    obj = temp;
    return strm;
}
