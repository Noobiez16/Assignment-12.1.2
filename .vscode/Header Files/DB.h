#ifndef DB_H
#define DB_H

#include "BinarySearchTree.h"
#include "PersonInfo.h"
#include <fstream>
#include <iostream>
#include <sstream>

// Declaraciones previas de las funciones de envoltura
void printPersonWrapper(PersonInfo& person);
void savePersonWrapper(PersonInfo& person, std::ofstream& outFile);

class DB {
private:
    BinarySearchTree<PersonInfo> bst;
    int numberOfPersons;

public:
    DB() : numberOfPersons(0) {}

    DB(const DB& other) : bst(other.bst), numberOfPersons(other.numberOfPersons) {}

    ~DB() {
        clear();
    }

    DB& operator=(const DB& other) {
        if (this != &other) {
            bst = other.bst;
            numberOfPersons = other.numberOfPersons;
        }
        return *this;
    }

    void addPerson(const PersonInfo& person) {
        if (bst.add(person)) {
            numberOfPersons++;
        }
    }

    bool removePerson(const MyString& name) {
        // Asume que PersonInfo tiene un constructor que acepta solo un nombre.
        PersonInfo personToRemove(name, Date()); // Date() crea una fecha por defecto.
        bool removedSuccessfully = bst.remove(personToRemove);
        if (removedSuccessfully) {
            numberOfPersons--;
        }
        return removedSuccessfully;
    }

    void viewAllFriends() const {
        bst.inorderTraverse(printPersonWrapper);
    }

    void saveToFile(const std::string& filename) const {
        std::ofstream outFile(filename);
        if (!outFile) {
            std::cerr << "No se pudo abrir el archivo para escribir: " << filename << std::endl;
            return;
        }
        static std::ofstream* staticOutFile = &outFile;
        static auto staticFunctionWrapper = [](PersonInfo& person) {
            savePersonWrapper(person, *staticOutFile);
        };
        bst.inorderTraverse(staticFunctionWrapper);
    }

    void loadFromFile(const std::string& filename) {
        std::ifstream inFile(filename);
        if (!inFile) {
            std::cerr << "No se pudo abrir el archivo para leer: " << filename << std::endl;
            return;
        }
        MyString name;
        Date birthday;
        while (inFile >> name >> birthday) {
            addPerson(PersonInfo(name, birthday));
        }
    }

    int getNumberOfPersons() const {
        return numberOfPersons;
    }

    void clear() {
        bst.clear();
        numberOfPersons = 0;
    }
};

// Implementación de las funciones de envoltura fuera de la clase DB
void printPersonWrapper(PersonInfo& person) {
    std::cout << person << std::endl;
}

void savePersonWrapper(PersonInfo& person, std::ofstream& outFile) {
    outFile << person.getName().data() << "," << person.getBirthday() << std::endl;
}

#endif // DB_H








