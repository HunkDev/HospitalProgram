#include <iostream>
#include <fstream>
#include <typeinfo>
#include "division_database.h"
#include "database.h"
#include "Division.h"

bool flag = true;

void create_divisions(class Division** arr, int* n) {
    std::cout << "Enter number of divisions = ";
    std::cin >> *n;
    if (*n <= 0) return;

    *arr = new Division[*n];
    for (int i = 0;i < *n; i++) {
        std::cin >> (*arr)[i];
    }
}

void write_divisions(const class Division* arr, int n) {
    if (n <= 0) return;

    std::ofstream out;
    out.open("divisions.txt");
    if (!out) return;

    flag = false;
    out << n << std::endl;

    for (int i = 0; i < n; i++) out << arr[i];

    flag = true;
    out.close();
}

void read_divisions(class Division** arr, int* n) {
    std::ifstream in("divisions.txt");
    if (!in) return;

    flag = false;
    in >> *n;
    if (*n <= 0) return;

    *arr = new Division[*n];
    for (int i = 0;i < *n; i++)
        in >> (*arr)[i];

    flag = true;
    in.close();
}

void add_division(class Division** arr, int* n) {
    if (!*arr) {
        std::cout << "First create list of divisions with command 'create'" << std::endl;
        return;
    }

    Division* tempArr = new Division[*n + 1];
    for (int i = 0; i < *n; i++) {
        tempArr[i] = (*arr)[i];
    }

    Division c;
    std::cin >> c;
    tempArr[*n] = c;

    delete[] * arr;
    *arr = tempArr;
    (*n)++;
}

Division search_division(class Division* arr, int n, std::string division) {
    if (!arr) {
        std::cout << "First create list of divisions with command 'create'" << std::endl;
        return;
    }

    division = to_lower(division);
    bool flag = false;
    int id = -1;

    for (int i = 0; i < n; i++) {
        if (division == to_lower(arr[i].name)) {
            id = i;
            flag = true;
        }
    }
    if (flag) return arr[id];
    else {
        std::cout << "There are no matches" << std::endl;
        return;
    }
}

void delete_division(class Division** arr, int* n) {
    if (!*arr) {
        std::cout << "List of divisions doesnt exist" << std::endl;
        return;
    }

    std::cout << "Enter the name of division you want to delete: ";
    std::string division;
    int id;
    std::cin >> division;
    division = to_lower(division);

    if (typeid(search_division(*arr, *n, division)) == typeid(Division)) {
        for (int i = 0; i < *n; i++) {
            if (division == to_lower((*arr)[i].name)) {
                id = i;
            }
        }
        for (int i = id; i < *n - 1; i++) {
            (*arr)[i] = (*arr)[i + 1];
        }
        (*n)--;
    }
    else {
        std::cout << "This division doesn't exist" << std::endl;
        return;
    }
}
