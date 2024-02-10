#ifndef PERSONINFO_H
#define PERSONINFO_H

#include "MyString.h"
#include "Date.h"
#include <iostream>
#include <cstring> 

class PersonInfo {
private:
    MyString name;
    Date birthday;

public:
    // Constructores
    PersonInfo() = default;  // Constructor por defecto
    PersonInfo(const MyString& n, const Date& b) : name(n), birthday(b) {}  // Constructor parametrizado

    // Métodos de acceso para el nombre y la fecha de nacimiento
    MyString getName() const { return name; }
    Date getBirthday() const { return birthday; }

    // Métodos modificadores para el nombre y la fecha de nacimiento
    void setName(const MyString& n) { name = n; }
    void setBirthday(const Date& b) { birthday = b; }

    // Sobrecarga del operador < para comparar PersonInfo basado en el nombre
    friend bool operator<(const PersonInfo& lhs, const PersonInfo& rhs) {
        return std::strcmp(lhs.name.data(), rhs.name.data()) < 0;  
    }

    // Sobrecarga del operador de inserción para imprimir PersonInfo
    friend std::ostream& operator<<(std::ostream& os, const PersonInfo& info) {
        os << "Name: " << info.name << ", Birthday: " << info.birthday;
        return os;
    }
};

#endif // PERSONINFO_H





