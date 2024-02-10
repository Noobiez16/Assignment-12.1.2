/* @file main.cpp_RUN_PROGRAM */
#include "DB.h"
#include <iostream>
#include <string>

const std::string DATA_FILE = "people_data.txt"; // Nombre del archivo donde se guardarán los datos

void displayMenu() {
    std::cout << "\nOptions Menu:" << std::endl;
    std::cout << "1. Enter person's data" << std::endl;
    std::cout << "2. Remove person's data" << std::endl;
    std::cout << "3. Show the list of birthdays" << std::endl;
    std::cout << "4. Save data in file" << std::endl;
    std::cout << "5. Read data from file" << std::endl;
    std::cout << "6. Quit program" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    DB database;
    char choice;
    std::string name;
    Date birthday;
    int day, month, year;

    do {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer

        switch (choice) {
            case '1': {
                std::cout << "Enter name: ";
                std::getline(std::cin, name);
                std::cout << "Enter birthday (day month year): ";
                std::cin >> day >> month >> year;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
                birthday = Date(month, day, year);
                // Convert std::string to char* before using MyString constructor
                char* writableName = new char[name.length() + 1];
                std::copy(name.begin(), name.end(), writableName);
                writableName[name.length()] = '\0'; // null-terminate the string
                database.addPerson(PersonInfo(MyString(writableName), birthday));
                delete[] writableName; // clean up the dynamic memory
                break;
            }
            case '2': {
                std::cout << "Enter name to remove: ";
                std::getline(std::cin, name);
                // Convert std::string to char* before using MyString constructor
                char* writableName = new char[name.length() + 1];
                std::copy(name.begin(), name.end(), writableName);
                writableName[name.length()] = '\0'; // null-terminate the string
                if (database.removePerson(MyString(writableName))) {
                    std::cout << "Person removed successfully." << std::endl;
                } else {
                    std::cout << "Person not found." << std::endl;
                }
                delete[] writableName; // clean up the dynamic memory
                break;
            }
            case '3': {
                std::cout << "List of birthdays:" << std::endl;
                database.viewAllFriends();
                break;
            }
            case '4': {
                std::cout << "Saving data to file..." << std::endl;
                database.saveToFile(DATA_FILE);
                std::cout << "Data successfully saved to " << DATA_FILE << std::endl;
                break;
            }
            case '5': {
                std::cout << "Loading data from file..." << std::endl;
                database.loadFromFile(DATA_FILE);
                std::cout << "Data successfully loaded from " << DATA_FILE << std::endl;
                break;
            }
            case '6': {
                std::cout << "Exiting program. Goodbye!" << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
            }
        }
    } while (choice != '6');

    return 0;
}