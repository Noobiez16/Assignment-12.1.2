#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date {
private:
    int month;
    int day;
    int year;

    bool isLeapYear() const {
        return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    }

public:
    // Constructores
    Date() : month(1), day(1), year(1900) {}
    Date(int m, int d, int y) : month(m), day(d), year(y) {}
    Date(const Date& other) : month(other.month), day(other.day), year(other.year) {}

    // Métodos de acceso
    int getMonth() const { return month; }
    int getDay() const { return day; }
    int getYear() const { return year; }

    // Método para comprobar la validez de la fecha
    bool isValidDate() const {
        // Comprobaciones básicas
        if (year < 0 || month < 1 || month > 12 || day < 1) {
            return false;
        }

        // Comprobaciones de días por mes, incluyendo años bisiestos
        switch (month) {
            case 4: case 6: case 9: case 11: // Meses con 30 días
                return day <= 30;
            case 2: // Febrero
                return isLeapYear() ? day <= 29 : day <= 28;
            default: // Meses con 31 días
                return day <= 31;
        }
    }

    // Operador de comparación
    bool operator==(const Date& other) const {
        return day == other.day && month == other.month && year == other.year;
    }

    // Operador de desigualdad
    bool operator!=(const Date& other) const {
        return !(*this == other);
    }

    // Sobrecarga del operador de inserción
    friend std::ostream& operator<<(std::ostream& os, const Date& date) {
        os << date.day << "/" << date.month << "/" << date.year;
        return os;
    }

    // Sobrecarga del operador de extracción
    friend std::istream& operator>>(std::istream& is, Date& date) {
        is >> date.day >> date.month >> date.year;
        if (!date.isValidDate()) {
            is.setstate(std::ios::failbit); // Marcar el flujo como fallido si la fecha no es válida
        }
        return is;
    }
};

#endif // DATE_H



