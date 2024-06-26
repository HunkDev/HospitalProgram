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
	int age;
	in >> age;
	while (age < 0 || age > 120) {
		std::cout << "Incorrect Age!" << std::endl;
		cout << "Enter age:";
		in >> age;
	}
	pat._age = age;
	cout << "Enter diagnosis:";
	in >> pat._diagnosis;
	//cout << "Enter time of arrival:";
	//in >> pat._time;
	cout << "Enter status:";
	in >> pat._status;
	cout << "Remaining days: ";
	int days;
	in >> days;
	while (days < 0 || days > 365) {
		std::cout << "Incorrect days!" << std::endl;
		cout << "Remaining days: ";
		in >> days;
	}
	pat._days = days;
	return in;
}

ostream& operator <<(ostream& out, Patient& pat) {
	cout << " Name: ";
	out << pat._name << endl;
	cout << " Surname: ";
	out << pat._surname << endl;
	cout << " Gender: ";
	out << pat._gender << endl;
	cout << " Age: ";
	out << pat._age << endl;
	cout << " Diagnosis: ";
	out << pat._diagnosis << endl;
	cout << " Status: ";
	out << pat._status << endl;
	cout << "Days:";
	out << pat._days << endl;
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
	//out << "Patients:";
	//for (Patient& pat : doc.patients) {
		//out << pat << endl;
	//}
	return out;
}

istream& operator >>(istream& in, Division& div) {
		cout << "Name of division: ";
	in >> div.name;

		cout << "Free places: ";
		int places;
		in >> places;
		while (places < 1 || places > 200) {
			std::cout << "Incorrect places!" << std::endl;
			cout << "Free places: ";
			in >> places;
		}
	div.places = places;

	return in;
}

ostream& operator <<(ostream& out, Division& div) {

		std::cout << "Name: "; 
	out << div.name << endl;

		std::cout << "Free places:";
	out << div.places << endl; 

	std::cout << "Count of doctors: ";
	out << div.doctors.size() << endl;
		std::cout << "Doctors:" << std::endl;
	for (std::string& doctor : div.doctors)
		out << doctor << endl;
	out << endl;

	std::cout << "Count of patients: ";
	out << div.patients.size() << endl;
		std::cout << "Patients:" << std::endl;
	for (Patient& patient : div.patients)
		out << patient << endl;
	out << endl;


	return out;
}

string Doctor::getFullName() {
	return name;
}

void Division::attachPat(const Patient& patient) {
	patients.push_back(patient);
	places -= 1;
}

void Division::attachDoc(std::string& doctor) {
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

std::vector<Patient> Division::get_patients() {
	return patients;
}

void Division::setName(std::string str) {
	name = str;
}