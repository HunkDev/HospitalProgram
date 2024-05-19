#include <iostream>
#include "Patient.h"
#include "disease.h"
#include "doctor.h"
#include "Division.h"
#include "patient.cpp"
#include "Func.cpp"
#include "database.cpp"

int main() {
	cout << "1-Division, 2-Doctor, 3-Patient, 4-Disease" << endl;
	int key;
	cin >> key;
	if (!key) {
		cout << "Error" << endl;
		return 0;
	}
	switch (key) {
	case 1:
		int key_div;
		cout << "1-Create, 2-Save, 3-read, 4-edit, 5-delete, 6-edit, 7-exit" << endl;
		cin >> key_div;
		if (!key_div) {
			cout << "Error" << endl;
			return 0;
		}
		switch(key_div){
			//Методы бд для отделения
		}
		break;

	case 2:
		int key_doc;
		cout << "1-Create, 2-Save, 3-read, 4-edit, 5-delete, 6-edit, 7-exit" << endl;
		cin >> key_doc;
		if (!key_doc) {
			cout << "Error" << endl;
			return 0;
		}
		switch (key_doc) {
			//Методы бд для врача
		}
		break;
	case 3:
		int key_pat;
		cout << "1-Create, 2-Save, 3-read, 4-edit, 5-delete, 6-edit, 7-exit" << endl;
		cin >> key_pat;
		if (!key_pat) {
			cout << "Error" << endl;
			return 0;
		}
		switch (key_pat) {
			//Методы бд для пациента
		}
		break;
	case 4:
		int key_dis;
		cout << "1-Create, 2-Save, 3-read, 4-edit, 5-delete, 6-edit, 7-exit" << endl;
		cin >> key_dis;
		if (!key_dis) {
			cout << "Error" << endl;
			return 0;
		}
		switch (key_dis) {
			//Методы бд для болезни
		}
		break;
	}
}	