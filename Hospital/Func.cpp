#include <stdio.h>
#include <string>
#include "Patient.h"
#include "Division.h"
#include "doctor.h"
#include <list>
#include <iostream>
#include <vector>
using namespace std;

istream& operator >>(istream& in, Patient &pat) {
	cout << "Enter name:";
	in >> pat._name;
	cout << "Enter surname:";
	in >> pat._surname;
	cout << "Enter gender:";
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
	out << " Name: " << pat._name << "Surname: " << pat._surname << " Gender: " << pat._gender << " Age: " << pat._age << " Diagnosis: " << pat._diagnosis << " Doctor`s name: " << pat._doctor << " Status: " << pat._status << endl;
	return out;
}

istream& operator >>(istream& in, Doctor &doc) {
	cout << "Doctor`s name:";
	string str;
	in >> str;
	return in;
}

ostream& operator <<(ostream& out, Doctor& doc) {
	out << "Name:" << doc.name << endl;
	out << "Patients:";
	for (Patient& pat : doc.patients) {
		out << pat << endl;
	}
	return out;
}

istream& operator >>(istream& in, Division& div) {
	cout << "Name of division: ";
	in >> div.name;
	cout << "Free places: ";
	in >> div.places;

	return in;
}

ostream& operator <<(ostream& out, Division& div) {
	out << "Free places:" << div.places << endl; 
	out << "Doctors:";
	for (Doctor& doctor : div.doctors)
		out << doctor << endl;
	out << "Patients:";
	for (Patient& patient : div.patients)
		out << patient << endl;

	return out;
}

string Doctor::getFullName() {
	return name;
}

vector<Patient> Doctor::getPatients() {
	return patients;
}

void Doctor::addPatient(const Patient _patient) {
	patients.push_back(_patient);
}

void Division::attachPat(Patient patient) {
	patients.push_back(patient);
	places -= 1;
}

void Division::attachDoc(Doctor doctor) {
	doctors.push_back(doctor);
	//places_doctors -= 1;
}

void Division::setPlaces(int place) {
	places = place;
}

int Division::getPlace() {
	return places;
}

std::string Division::get_name() {
	return name;
}