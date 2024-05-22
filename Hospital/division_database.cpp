#include <iostream>
#include <fstream>
#include <typeinfo>
#include <vector>
#include <string>
#include "division_database.h"
#include "database.h"
#include "Division.h"

namespace division_db {
    void create_divisions(std::vector<Division> *arr) {
        int n;
        std::cout << "Enter number of divisions = ";
        std::cin >> n;
        if (n <= 0) return;

        arr->clear();
        Division division;
        for (int i = 0;i < n; i++) {
            std::cin >> division;
            arr->push_back({division});
        }
    }

    void write_divisions(std::vector<Division> arr) {
        if (arr.empty()) return;

        std::ofstream out;
        out.open("divisions.txt");
        if (!out) return;
        
        int n = arr.size();
        out << n << std::endl;

        for (int i = 0; i < n; i++) {
            out << arr[i] << std::endl;
        }

        out.close();
    }

    

    void add_division(std::vector<Division> *arr) {
        if (arr->empty()) {
            std::cout << "First create list of divisions with command 'create'" << std::endl;
            return;
        }

        Division c;
        std::cin >> c;
        arr->push_back({c});
    }

    void search_division(std::vector<Division> arr) {
        if (arr.empty()) {
            std::cout << "First create list of divisions with command 'create'" << std::endl;
            return;
        }

        std::string division;
        std::cout << "What division you are looking for?: ";
        std::cin >> division;

        division = to_lower(division);
        bool flag = false;
        int id = -1;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            if (division == to_lower(arr[i].get_name())) {
                id = i;
                flag = true;
            }
        }
        if (flag) std::cout << arr[id];
        else {
            std::cout << "There are no matches" << std::endl;
            return;
        }
    }

    void delete_division(std::vector<Division> *arr) {
        if (arr->empty()) {
            std::cout << "List of divisions doesnt exist" << std::endl;
            return;
        }

        std::cout << "Enter the name of division you want to delete: ";
        std::string division;
        int id;
        int n = arr->size();
        std::cin >> division;
        division = to_lower(division);
        bool flag = false;

        for (int i = 0; i < n; i++) {
            if (division == to_lower((*arr)[i].get_name())) {
                id = i;
                flag = true;
            }
        }
        if (flag){
            arr->erase(arr->begin() + id);
        }
        else {
            std::cout << "This division doesn't exist" << std::endl;
            return;
        }
    }

    void print_divisions(std::vector<Division> arr) {
        if (arr.empty()) {
            std::cout << "List of divisions doesnt exist" << std::endl;
            return;
        }

        int n = arr.size();
        for (int i = 0;i < n; i++) {
            std::cout << arr[i] << std::endl;
        }
    }

    void add_patient(std::vector<Division>* arr, std::vector<Patient> patients) {
        if (arr->empty()) {
            std::cout << "List of divisions doesnt exist" << std::endl;
            return;
        }
        if (patients.empty()) {
            std::cout << "List of patients doesnt exist" << std::endl;
            return;
        }

        std::string patient;
        std::string division;
        std::cout << "Enter surname of patient which you want to add: ";
        std::cin >> patient;

        patient = to_lower(patient);
        bool flag = false;
        int id = -1;
        int n = patients.size();

        for (int i = 0; i < n; i++) {
            if (patient == to_lower(patients[i].getSurname())) {
                id = i;
                flag = true;
            }
        }
        if (!flag) {
            std::cout << "There are no matches" << std::endl;
            return;
        }

        std::cout << "Enter name of division: ";
        std::cin >> division;

        division = to_lower(division);
        flag = false;
        int d_id = -1;
        n = arr->size();

        for (int i = 0; i < n; i++) {
            if (division == to_lower((*arr)[i].get_name())) {
                d_id = i;
                flag = true;
            }
        }
        if (!flag) {
            std::cout << "There are no matches" << std::endl;
            return;
        }

        std::cout << (*arr)[d_id].get_patients().size();
        std::cout << (*arr)[d_id].getPlace();
        if ((*arr)[d_id].getPlace() == 0) {
            std::cout << "There are no places in this division" << std::endl;
            return;
        }

        (*arr)[d_id].attachPat(patients[id]);
        return;

    }
}

void read_divisions(std::vector<Division>* arr) {
    std::ifstream in("divisions.txt");
    if (!in) return;

    int n;
    int m;
    int k;
    in >> n;
    if (n <= 0) return;


    *arr = {};
    Division division;
    Doctor doctor;
    Patient patient;
    for (int i = 0;i < n; i++) {
        in >> division.name;

        in >> division.places;

        in >> m;
        std::cout << m;
        division.doctors.clear();
        if (m > 0) {           
            for (int j = 0; j < m; j++) {
                in >> doctor;              
                division.doctors.push_back(doctor);
            }
        }

        in >> k;
        std::cout << k;     
        division.patients.clear();
        if (k > 0) {           
            for (int j = 0; j < k; j++) {
                in >> patient;              
                division.patients.push_back(patient);
            }
        }

        arr->push_back({ division });
    }

    in.close();
}

