#include <iostream>
#include "Patient.h"
#include "doctor.h"
#include "Division.h"
#include "database.h"
#include "division_database.h"
#include "doctors_db.h"
#include "time.h"

using namespace std;

int Timing(int key) {
	time_t cur_time = time(nullptr);
	tm ct_cur;
	localtime_s(&ct_cur, &cur_time);
	int cur_day = ct_cur.tm_yday;
	time_t stored_time = read_time();
	tm ct_store;
	localtime_s(&ct_store, &stored_time);
	int store_day = ct_store.tm_yday;
	if ((cur_time - stored_time) != 0) {
		key = 4;
		write_time(cur_time);
	}
	else
		write_time(cur_time);
	return key;
}

int main() {
	cout << "1-Division, 2-Doctor, 3-Patient 4-advance time" << endl;
	int key = 0;
	bool w;	
	key = Timing(key);

	key = 0;

	if(key != 4)
		if (!(std::cin >> key).good()) {
			cout << "Error" << endl;
			return 0;
		}
	vector<Division> divisions;
	fstream db("doc_database.txt", ios::out | ios::in);
	string division;

	switch (key) {
	case 1:
		w = true;
		while (w) {
			int key_div;
			cout << "1-Create, 2-write, 3-read, 4-add, 5-search, 6-delete, 7-print, 8-exit" << endl;
			if (!(std::cin >> key_div).good()) {
				cout << "Error #123-1242135" << endl;
				return 0;
			}
			switch (key_div) {
				//Ìåòîäû áä äëÿ îòäåëåíèÿ
			case 1:
				if (!divisions.empty()) {
					int var;
					cout << "Divisions database will delete. Do you really want this?" << endl << "1 = yes, \t 2 = no" << endl;
					std::cin >> var;
					if (var == 2)
						break;
					if (var == 1) {
						division_db::create_divisions(&divisions);
						break;
					}
					else {
						cout << "ERROR #12-43840812837531251425" << endl;
						break;
					}
				}
				else {
					division_db::create_divisions(&divisions);
					break;
				}
			case 2:
				division_db::write_divisions(divisions);
				break;
			case 3:
				division_db::read_divisions(&divisions);
				break;
			case 5:
				cout << "What division you are looking for?: ";
				std::cin >> division;
				division_db::search_division(divisions, division);
				break;
			case 4:
				//no edit, add
				division_db::add_division(&divisions);
				break;
			case 6:
				division_db::delete_division(&divisions);
				break;
			case 7:
				division_db::print_divisions(divisions);
				break;
			default:					
				w = false;
				break;
			}
		}
		break;

	case 2:
		w = true;
		//int n;
		//Doctor* doctors;
		if (!db.is_open()) {
			cerr << "Error opening file #131-3124132412" << endl;
			break;
		}
		while (w) {
			int key_doc;
			cout << "1-Create, 2-write, 3-read, 4-add, 5-search, 6-delete, 7-exit" << endl;
			if (!(std::cin >> key_doc).good()) {
				cout << "Error #123-23415412" << endl;
				return 0;
			}
			switch (key_doc) {
				//Ìåòîäû áä äëÿ âðà÷à
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
			case 2:
				//read_doc(&doctors, &n);
				doctor_db::write_doc(db);
				break;
			case 3:
				//search_doc(&doctors, &n);
				doctor_db::read_doc();
				break;
			case 4:
				//add, no edit
				//add_doc(&doctors, &n);
				doctor_db::add_doc(db);
				break;
			case 5:
				//delete_doc(&doctors, &n);
				doctor_db::search_doc(db);
				break;
			case 6:
				doctor_db::delete_doc(db);
				break;
			default:
				w = false;
				break;
			}
		}
		db.close();
		break;
	case 3:
	{
		w = true;
		vector<Patient> temp;
		while (w) {
			int key_pat;
			cout << "1-Create, 2-Save, 3-read, 4-add, 5-delete, 6-exit" << endl;
			std::cin >> key_pat;
			if (!key_pat) {
				cout << "Error" << endl;
				break;
			}
			switch (key_pat) {
			case 1:
				patient_db::create_patients(&temp);
				break;
			case 2:
				patient_db::read_patients(&temp);
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

				patient_db::add_patient(&temp);
				break;
			case 5:
				patient_db::delete_patient(&temp);
				break;
			case 6:
				w = false;
				break;
			}
		}
		}
	case 4:
		vector<Patient> patients;
		patient_db::read_patients(&patients);
		int s = (patients.size()-1);
		for (int i = 0; i < s; i++) {
			patients[i].advance_day();
		}
	}
}	