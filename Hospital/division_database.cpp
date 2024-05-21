#include <iostream>
#include <string>
#include <fstream>
#include <typeinfo>
#include <vector>
#include "division_database.h"
#include "database.h"
#include "Division.h"

namespace division_db {
    void create_divisions(std::vector<Division> *arr) {
        int n;
        std::cout << "Enter number of divisions = ";
        std::cin >> n;
        if (n <= 0) return;

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

    void read_divisions(std::vector<Division> *arr) {
        std::ifstream in("divisions.txt");
        if (!in) return;

        int n;
        in >> n;
        if (n <= 0) return;


        *arr = {};
        Division division;
        for (int i = 0;i < n; i++) {
            in >> division;
            arr->push_back({division});
        }

        in.close();
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
}

