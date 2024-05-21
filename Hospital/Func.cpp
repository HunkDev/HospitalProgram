#include <string>
#include "Patient.h"
#include "Division.h"
#include "doctor.h"
#include <list>
#include <iostream>
#include <vector>
#include "division_database.h"
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

		std::cout << "Name: "; 
	out << div.name << endl;

		std::cout << "Free places:";
	out << div.places << endl; 

		std::cout << "Doctors:";
	for (Doctor& doctor : div.doctors)
		out << doctor << endl;
	out << endl;
		std::cout << "Patients:";
	for (Patient& patient : div.patients)
		out << patient << endl;
	out << endl;


	return out;
}

string Doctor::getFullName() {
	return name;
}

const vector<Patient> Doctor::getPatients() const {
	return patients;
}

void Doctor::addPatient(const Patient& _patient) {
	patients.push_back(_patient);
}

void Division::attachPat(const Patient& patient) {
	patients.push_back(patient);
	places -= 1;
}

void Division::attachDoc(const Doctor& doctor) {
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