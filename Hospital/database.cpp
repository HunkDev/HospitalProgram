#include <iostream>
#include <fstream>
#include <typeinfo>
#include "database.h"
#include "Patient.h"

bool flag = true;

std::string to_lower(const std::string& str) {
    std::string result = str;
    for (char& c : result) {
        c = std::tolower(c);
    }
    return result;
}

void create_patients(class Patient** arr, int* n) {
    std::cout << "Enter number of patients = ";
    std::cin >> *n;
    if (*n <= 0) return;

    *arr = new Patient[*n];
    for (int i = 0;i < *n; i++) {
        std::cin >> (*arr)[i];
    }
}

void write_patients(const class Patient* arr, int n) {
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

void read_patients(class Patient** arr, int* n) {
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

void add_patient(class Patient** arr, int* n) {
    if (!*arr) {
        std::cout << "First create list of patients with command 'create'" << std::endl;
        return;
    }

    Patient* tempArr = new Patient[*n + 1];
    for (int i = 0; i < *n; i++) {
        tempArr[i] = (*arr)[i];
    }

    Patient c;
    std::cin >> c;
    tempArr[*n] = c;

    delete[] * arr;
    *arr = tempArr;
    (*n)++;
}

Patient search_patient(class Patient* arr, int n, std::string patient) {
    if (!arr) {
        std::cout << "First create list of patients with command 'create'" << std::endl;
        return;
    }

    patient = to_lower(patient);
    bool flag = false;
    int id = -1;

    for (int i = 0; i < n; i++) {
        if (patient == to_lower(arr[i]._fio)) {
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

void delete_patient(class Patient** arr, int* n) {
    if (!*arr) {
        std::cout << "List of patients doesnt exist" << std::endl;
        return;
    }

    std::cout << "Enter the fio of patient you want to delete: ";
    std::string patient;
    int id;
    std::cin >> patient;
    patient = to_lower(patient);

    if (typeid(search_patient(*arr, *n, patient)) == typeid(Patient)) {
        for (int i = 0; i < *n; i++) {
            if (patient == to_lower((*arr)[i]._fio)) {
                id = i;
            }
        }
        for (int i = id; i < *n - 1; i++) {
            (*arr)[i] = (*arr)[i + 1];
        }
        (*n)--;
    }
    else{
        std::cout << "This patient doesn't exist" << std::endl;
        return;
    }
}
