#include <iostream>
#include "Patient.h"
#include "doctor.h"
#include "Division.h"
#include "patient.cpp"
#include "Func.cpp"
#include "database.cpp"
#include "division_database.h"
#include "time.cpp"

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
	int key;
	Timing(key);
	if(key != 4)
		if (!(cin >> key).good()) {
			cout << "Error" << endl;
			return 0;
		}
	switch (key) {
	case 1:
	{
		bool w = true;
		vector<Division> divisions;
		while (w) {
			int key_div;
			cout << "1-Create, 2-read, 3-search, 4-add, 5-delete, 6-exit" << endl;
			cin >> key_div;
			if (!(cin >> key_div).good()) {
				cout << "Error" << endl;
				return;
			}
			switch (key_div) {
			case 1:
				division_db::create_divisions(divisions);
				break;
			case 2:
				division_db::read_divisions(divisions);
				break;
			case 3:
			{
				string str;
				if (!(cin >> str).good()) {
					cout << "Error" << endl;
					return;
				}
				division_db::search_division(divisions, str);
				break;
			}
			case 4:
				//no edit, add
				division_db::add_division(divisions);
				break;
			case 5:
				division_db::delete_division(divisions);
				break;
			case 6:
				w = false;
				break;
			}
		}
		break;
	}
	case 2:
		bool w = true;
		//Doctor* doctors;
		while (w) {
			int key_doc;
			cout << "1-Create, 2-read, 3-search, 4-add, 5-delete, 6-exit" << endl;
			cin >> key_doc;
			if (!(cin >> key_doc).good()) {
				cout << "Error" << endl;
				return;
			}
			switch (key_doc) {
				//Ìåòîäû áä äëÿ âðà÷à
			case 1:
				//create_doc(&doctors, &n);
				break;
			case 2:
				//read_doc(&doctors, &n);
				break;
			case 3:
				//search_doc(&doctors, &n);
				break;
			case 4:
				//add, no edit
				//add_doc(&doctors, &n);
				break;
			case 5:
				//delete_doc(&doctors, &n);
				break;
			case 6:
				w = false;
				break;
			}
		}
		break;
	case 3:
	{
		bool w = true;
		vector<Patient> temp;
		while (w) {
			int key_pat;
			cout << "1-Create, 2-Save, 3-read, 4-add, 5-delete, 6-exit" << endl;
			cin >> key_pat;
			if (!key_pat) {
				cout << "Error" << endl;
				return;
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
				if (!(cin >> str).good()) {
					cout << "Error" << endl;
					return;
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
				w = false;
				break;
			}
		}
		}
	case 4:
		vector<Patient> patients;
		patient_db::read_patients(patients);
		int s = (patients.size()-1);
		for (int i = 0; i < s; i++) {
			patients[i].advance_day();
		}
	}
}	