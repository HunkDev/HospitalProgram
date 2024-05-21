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

void create_patients(std::vector<Patient> arr) {
    int n;
    std::cout << "Enter number of patients = ";
    std::cin >> n;
    if (n <= 0) return;

    Patient patient;
    for (int i = 0;i < n; i++) {
        std::cin >> patient;
        arr.push_back({ patient });
    }
}

void write_patients(std::vector<Patient> arr) {
    if (arr.empty()) return;

    std::ofstream out;
    out.open("patients.txt");
    if (!out) return;

    int n = arr.size();
    out << n << std::endl;

    for (int i = 0; i < n; i++) {
        out << arr[i] << std::endl;
    }

    out.close();
}

void read_patients(std::vector<Patient> arr) {
    std::ifstream in("patients.txt");
    if (!in) return;

    int n;
    in >> n;
    if (n <= 0) return;

    arr = {};
    Patient patient;
    for (int i = 0;i < n; i++) {
        in >> patient;
        arr.push_back({ patient });
    }

    in.close();
}

void add_patient(std::vector<Patient> arr) {
    if (arr.empty()) {
        std::cout << "First create list of patient with command 'create'" << std::endl;
        return;
    }

    Patient c;
    std::cin >> c;
    arr.push_back({ c });
}

Patient search_patient(std::vector<Patient> arr, std::string patient) {
    if (arr.empty()) {
        std::cout << "First create list of patients with command 'create'" << std::endl;
        return;
    }

    patient = to_lower(patient);
    bool flag = false;
    int id = -1;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        if (patient == to_lower(arr[i].getFio())) {
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

void delete_patient(std::vector<Patient> arr) {
    if (arr.empty()) {
        std::cout << "List of patients doesnt exist" << std::endl;
        return;
    }

    std::cout << "Enter the name of patient you want to delete: ";
    std::string patient;
    int id;
    int n = arr.size();
    std::cin >> patient;
    patient = to_lower(patient);

    if (typeid(search_patient(arr, patient)) == typeid(Patient)) {
        for (int i = 0; i < n; i++) {
            if (patient == to_lower(arr[i].getFio())) {
                id = i;
            }
        }
        for (int i = id; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
    }
    else {
        std::cout << "This patient doesn't exist" << std::endl;
        return;
    }
}
void advance_time(std::vector<Patient> arr, int days) {
    for (int i = 0; i < days; i++) {
        arr[i].advance_day();
    }
}