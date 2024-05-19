#include <stdio.h>
#include <string>
#include "Patient.h"
#include "Division.h"
#include "disease.h"
#include "doctor.h"
#include <list>
using namespace std;

istream& operator >>(istream& in, Patient& pat) {
	cout << "Enter name:";
	in >> pat._fio;
	cout << "Enter sex:";
	in >> pat._gender;
	cout << "Enter age:";
	in >> pat._age;
	cout << "Enter diagnosis:";
	in >> pat._diagnosis;
	//cout << "Enter time of arrival:";
	//in >> pat._time;
	cout << "Enter doctor`s name:";
	in >> pat._doctor;
	cout << "Enter status:";
	in >> pat._status;
	return in;
}

ostream& operator <<(ostream& out, Patient& pat) {
	out << " Name: " << pat._fio << " Sex: " << pat._gender << " Age: " << pat._age << " Diagnosis: " << pat._diagnosis << " Doctor`s name: " << pat._doctor << " Status: " << pat._status << endl;
}

istream& operator >>(istream& in, Doctor& doc) {
	cout << "Doctor`s name:";
	string str;
	in >> str;
	int len = str.length();
	if (len < 100) {
		for (int i = 0; i < len; i++) {
			doc.fullName[i] = str[i];
		}
		for (int i = 0; i < 100; i++) {
			doc.fullName[i] = str[i];
		}
	}
	else
		for (int i = 0; i < 100; i++) {
			doc.fullName[i] = str[i];
		}
	return in;
}

ostream& operator <<(ostream& out, Doctor& doc) {
	out << "Name:" << doc.fullName << endl;
	out << "Patients:";
	for (Patient& pat : doc.patients) {
		out << pat << endl;
	}
	return out;
}

istream& operator >>(istream& in, Division& div) {
	cout << "Free places:";
	in >> div.places;
}

ostream& operator <<(ostream& out, Division& div) {
	out << "Free places:" << div.places << endl; 
	out << "Doctors:";
	for (Doctor& doctor : div.doctors)
		out << doctor << endl;
	out << "Patients:";
	for (Patient& patient : div.patients)
		out << patient << endl;
}

int Disease::getRecoveryTime() {
	return recoveryTime;
}

const char* Doctor::getFullName() {
	return fullName;
}

vector<Patient> Doctor::getPatients() {
	return patients;
}

void Doctor::addPatient(const Patient& _patient) {
	patients.push_back(_patient);
}

void Division::attachPat(Patient& patient) {
	patients.push_back(patient);
	places -= 1;
}

void Division::setPlaces(int place) {
	places = place;
}

int Division::getPlace() {
	return places;
}