#include <iostream>
#include "Patient.h"
#include "doctor.h"
#include "Division.h"
#include "database.h"
#include "division_database.h"
#include "doctors_db.h"
#include "time.h"

using namespace std;

void Timing(vector<Division> *divisions) {
	time_t cur_time = time(nullptr);
	tm ct_cur;
	vector<Patient> patients;
	localtime_s(&ct_cur, &cur_time);
	int cur_day = ct_cur.tm_yday;
	int store_day = read_time();
	if ((cur_time - store_day) > 0) {
		for (int i = 0; i < divisions->size(); i++) {
			for (int j = 0; j < (*divisions)[i].get_patients().size(); j++) {
				patients.push_back((*divisions)[i].get_patients()[j]);
			}
		}
		int s = (patients.size() - 1);
		for (int i = 0; i < s; i++) {
			patients[i].advance_day();
		}
		write_time(cur_time);
	}
	else
		write_time(cur_time);
}

void DayMinus(vector<Division>* divisions, int s) {
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < (*divisions)[i].patients.size(); j++)
		(*divisions)[i].patients[j].advance_day();
	}
}

int main() {	
	int key = 0;
	bool w;
	bool moment = true;
	vector<Division> divisions;
	vector<Patient> temp;
	fstream db("doc_database.txt", ios::out | ios::in);
	string division;
	key = 0;
	while (moment) {
		cout << endl << "1-Division, 2-Doctor, 3-Patient 4-advance time 5-exit programm" << endl;
		if (!(std::cin >> key).good()) {
			cout << "Error" << endl;
			return 0;
		}
		switch (key) {
		case 1:
			w = true;
			while (w) {
				int key_div;
				cout <<  "1-Create, 2-write, 3-read, 4-add, 5-search, 6-delete, 7-print, 8-add patient 9-add doctor 10-delete patient 11-delete doctor 12-exit" << endl;
				if (!(std::cin >> key_div).good()) {
					cout << "Error #123-1242135" << endl;
					return 0;
				}
				switch (key_div) {
				case 1:
					if (!divisions.empty()) {
						int var;
						cout << "Divisions database will delete. Do you really want this?" << endl << "1 = yes, \t 2 = no" << endl;
						std::cin >> var;
						if (var == 2)
							break;
						if (var == 1) {
							division_db::create_divisions(&divisions);
							Timing(&divisions);
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
					read_divisions(&divisions);
					Timing(&divisions);
					break;
				case 5:
					division_db::search_division(divisions);
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
				case 8:
					division_db::add_patient(&divisions, temp);
					break;
				case 9:
					division_db::add_doctor(&divisions, db);
					break;
				case 10:
					delete_patient(&divisions);
					break;
				case 11:
					delete_doctor(&divisions);
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
				//if (!(db.peek() == EOF)) {
					//cerr << "Error opening file #131-3124132412" << endl;
					//break;
				//}
				while (w) {
					int key_doc;
					cout << "1-Create, 2-write, 3-read(print), 4-add, 5-search, 6-delete, 7-exit" << endl;
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
				while (w) {
					int key_pat;
					cout << "1 - Create, 2 - write, 3 - read, 4 - add, 5 - search, 6 - delete, 7 - print, 8 - exit" << endl;
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
						patient_db::write_patients(temp);
						break;
					case 3:
						patient_db::read_patients(&temp);
						break;
					case 5:
					{
						patient_db::search_patient(temp);
						break;
					}
					case 4:

						patient_db::add_patient(&temp);
						break;
					case 6:
						patient_db::delete_patient(&temp);
						break;
					case 7:
						patient_db::print_patients(temp);
						break;
					default:
						w = false;
						break;
					}
				}
			}
		case 4:
		{
			vector<Patient> patients;

			for (int i = 0; i < divisions.size(); i++) {
				for (int j = 0; j < divisions[i].get_patients().size(); j++) {
					patients.push_back(divisions[i].get_patients()[j]);
				}
			}
			int s = patients.size();
			DayMinus(&divisions, s);
			break;
		}
		default: {
			moment = false;
			break;

		}
		}
	}
}