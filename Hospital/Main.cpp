#include <iostream>
#include "Patient.h"
#include "doctor.h"
#include "Division.h"
#include "database.h"
#include "division_database.h"
#include "time.h"
#include "doctors_db.h"

using namespace std;

int Timing(int key) {
	time_t cur_time = time(nullptr);
	tm ct_cur;
	localtime_s(&ct_cur, &cur_time);
	int cur_day = ct_cur.tm_yday;
	int store_day = read_time();
	if ((cur_time - store_day) >= 0) {
		key = 4;
		write_time(cur_time);
	}
	else
		write_time(cur_time);
	return key;
}

int main() {
	bool w_pr = true;
	int key = 0;
	key = Timing(key);
	while (w_pr) {
		if (key != 4)
		{
			cout << "1-Division, 2-Doctor, 3-Patient, 4-advance time, 5-exit" << endl;
			std::cin >> key;
		}
		vector<Division> divisions;
		fstream db("doc_database.txt", ios::out | ios::in);
		string division;
		switch (key) {
		case 1:
		{
			bool w_cs1 = true;
			vector<Division> divisions;
			while (w_cs1) {
				int key_div;
				cout << "1-Create, 2-read, 3-search, 4-add, 5-delete, 6-exit" << endl;
				std::cin >> key_div;
				switch (key_div) {
				case 1:
					if (!divisions.empty()) {
						int var;
						cout << "Divisions database will delete. Do you really want this?" << endl << "1 = yes, \t 2 = no" << endl;
						std::cin >> var;
						if (var == 2)
							break;
						if (var == 1) {
							division_db::create_divisions(divisions);
							break;
						}
						else {
							cout << "ERROR #12-43840812837531251425" << endl;
							break;
						}
					}
					else {
						division_db::create_divisions(divisions);
						break;
					}
				case 2:
					division_db::read_divisions(divisions);
					break;
				case 3:
					cout << "What division you are looking for?: ";
					std::cin >> division;
					division_db::search_division(divisions, division);
					break;
				case 4:
					//no edit, add
					division_db::add_division(divisions);
					break;
				case 5:
					division_db::delete_division(divisions);
					break;
				case 6:
					break;
					w_cs1 = false;
					break;
				}
			}
			break;
		}
		break;
		case 2:
		{
			bool w_cs2 = true;
			//int n;
			//Doctor* doctors;
			if (!db.is_open()) {
				cerr << "Error opening file #131-3124132412" << endl;
				break;
			}
			while (w_cs2) {
				int key_doc;
				cout << "1-Create, 2-read, 3-search, 4-add, 5-delete, 6-exit" << endl;
				std::cin >> key_doc;
				if (!(std::cin >> key_doc).good()) {
					cout << "Error #123-23415412" << endl;
					return 0;
				}
				switch (key_doc) {
				case 1:
					if (!db) {
						int var;
						cout << "Doctors database will delete. Do you really want this?" << endl << "1 = yes, \t 2 = no" << endl;
						std::cin >> var;
						if (var == 2)
							break;
						if (var == 1) {
							doctor_db::create_doc(db);
							break;
						}
						else {
							cout << "ERROR #12-43840812837531251426" << endl;
							break;
						}
					}
					else {
						doctor_db::create_doc(db);
						break;
					}
					break;
				case 2:
					//read_doc(&doctors, &n);
					doctor_db::read_doc();
					break;
				case 3:
					//search_doc(&doctors, &n);
					doctor_db::search_doc(db);
					break;
				case 4:
					//add, no edit
					//add_doc(&doctors, &n);
					doctor_db::add_doc(db);
					break;
				case 5:
					//delete_doc(&doctors, &n);
					doctor_db::delete_doc(db);
					break;
				case 6:
					w_cs2 = false;
					break;
				}
				db.close();
				break;
			}
		}
		break;
		case 3:
		{
			bool w_cs3 = true;
			vector<Patient> temp;
			while (w_cs3) {
				int key_pat;
				cout << "1-Create, 2-Save, 3-read, 4-add, 5-delete, 6-exit" << endl;
				std::cin >> key_pat;
				if (!key_pat) {
					cout << "Error" << endl;
					break;
				}
				switch (key_pat) {
				case 1:
					patient_db::create_patients(temp);
					break;
				case 2:
					patient_db::read_patients(temp);
					break;
				case 3:
				{
					string str;
					if (!(std::cin >> str).good()) {
						cout << "Error" << endl;
						break;
					}
					patient_db::search_patient(temp, str);
					break;
				}
				case 4:

					patient_db::add_patient(temp);
					break;
				case 5:
					patient_db::delete_patient(temp);
					break;
				case 6:
					w_cs3 = false;
					break;
				}
			}
		}
		break;
		case 4:
		{
			vector<Patient> patients;
			patient_db::read_patients(patients);
			int s = (patients.size() - 1);
			for (int i = 0; i < s; i++) {
				patients[i].advance_day();
			}
			key = 0;
		}
		break;
		case 5:
		{
			w_pr = false;
		}
		break;
		}
	}
}