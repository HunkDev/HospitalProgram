#pragma once

#include <vector>
#include "Division.h"

namespace division_db {
	void create_divisions(std::vector<Division> arr);
	void write_divisions(std::vector<Division> arr);
	void read_divisions(std::vector<Division> arr);
	void add_division(std::vector<Division> arr);
	Division search_division(std::vector<Division> arr, std::string division);
	void delete_division(std::vector<Division> arr);
	void print_divisions(std::vector<Division> arr);
}

