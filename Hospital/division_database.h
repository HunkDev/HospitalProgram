#pragma once

#include <vector>
#include "Division.h"

namespace division_db {
	void create_divisions(std::vector<Division> *arr);
	void write_divisions(std::vector<Division> arr);
	void add_division(std::vector<Division> *arr);
	void search_division(std::vector<Division> arr);
	void delete_division(std::vector<Division> *arr);
	void print_divisions(std::vector<Division> arr);

	void add_patient(std::vector<Division>* arr, std::vector<Patient> patients);
	void add_doctor(std::vector<Division>* arr, std::fstream& db);
}
void read_divisions(std::vector<Division>* arr);
