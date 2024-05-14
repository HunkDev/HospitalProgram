#include <iostream>
#include <fstream>
#include "database.h"
#include "pacient.h"

bool flag = true;

void create(class Patient** arr, int* n) {
    std::cout << "n = ";
    std::cin >> *n;
    if (*n <= 0) return;

    *arr = new Patient[*n];
    for (int i = 0;i < *n; i++) {
        std::cin >> (*arr)[i];
    }
}

void write(const class Patient* arr, int n) {
    if (n <= 0) return;

    std::ofstream out;
    out.open("patients.txt");
    if (!out) return;

    flag = false;
    out << n << std::endl;

    for (int i = 0; i < n; i++) out << arr[i];

    flag = true;
    out.close();
}

void read(class Patient** arr, int* n) {
    std::ifstream in("patients.txt");
    if (!in) return;

    flag = false;
    in >> *n;
    if (*n <= 0) return;

    *arr = new Patient[*n];
    for (int i = 0;i < *n; i++)
        in >> (*arr)[i];

    flag = true;
    in.close();
}