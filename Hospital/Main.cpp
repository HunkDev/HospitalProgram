#include <iostream>
#include "Patient.h"
#include "disease.h"
#include "doctor.h"
#include "Division.h"
#include "patient.cpp"
#include "Func.cpp"
#include "database.cpp"
using namespace std;

int main() {
	cout << "1-Division, 2-Doctor, 3-Patient, 4-Disease" << endl;
	int key;
	if (!(cin >> key).good()) {
		cout << "Error" << endl;
		return 0;
	}
	switch (key) {
	case 1:
		int key_div;
		cout << "1-Create, 2-read, 3-search, 4-edit, 5-delete, 6-edit, 7-exit" << endl;
		if (!(cin >> key_div).good()) {
			cout << "Error" << endl;
			return 0;
		}
		switch(key_div){
			//Ìåòîäû áä äëÿ îòäåëåíèÿ
		}
		break;

	case 2:
		int key_doc;
		cout << "1-Create, 2-read, 3-search, 4-edit, 5-delete, 6-edit, 7-exit" << endl;
		if (!(cin >> key_doc).good()) {
			cout << "Error" << endl;
			return 0;
		}
		switch (key_doc) {
			//Ìåòîäû áä äëÿ âðà÷à
		}
		break;
	case 3:
    bool w = true;
		Patient* temp;
		int n;
		switch (key_pat) {
		while (w) {
      int key_pat;
		  cout << "1-Create, 2-Save, 3-read, 4-edit, 5-delete, 6-edit, 7-exit" << endl;
		  cin >> key_pat;
		  if (!key_pat) {
			  cout << "Error" << endl;
			  return 0;
		  }
			switch (key_pat) {
			case 1:
				cout « "n=";
				if (!(cin » n).good()) {
					cout « "Error" « endl;
					return 0;
				}
				create_patients(&temp, &n);
				break;
			case 2:
				read_patients(&temp, &n);
				break;
			case 3:
			{
				string str;
				if (!(cin » str).good()) {
					cout « "Error" « endl;
					return 0;
				}
				cout « "n=";
				if (!(cin » n).good()) {
					cout « "Error" « endl;
					return 0;
				}
				search_patient(temp, n, str);
				break;
			}
			case 4:
				cout « "n=";
				if (!(cin » n).good()) {
					cout « "Error" « endl;
					return 0;
				}
				add_patient(&temp, &n);
				break;
			case 5:
				delete_patient(&temp, &n);
				break;
			case 6:

				break;
			case 7:
				w = false;
				break;
			}
		}
	case 4:
		int key_dis;
		cout << "1-Create, 2-read, 3-search, 4-edit, 5-delete, 6-edit, 7-exit" << endl;
		if (!(cin >> key_dis).good()) {
			cout << "Error" << endl;
			return 0;
		}
		switch (key_dis) {
			//Ìåòîäû áä äëÿ áîëåçíè
		}
		break;
	}
}	