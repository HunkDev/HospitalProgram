#pragma once

#include <fstream>

namespace doctor_db {
	void read_doc();
	void write_doc(std::fstream& db);
	void create_doc(std::fstream& db);
	void add_doc(std::fstream& db);
	void search_doc(std::fstream& db);
	void delete_doc(std::fstream& db);
}