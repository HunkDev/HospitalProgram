#include <stdio.h>
#include <string>
#include "Patient.h"
#include "Division.h"
using namespace std;

istream& operator >>(istream& in, Division& div) {
	cout << "Введите кол-во мест";
	in >> div.places;
}

ostream& operator <<(ostream& out, Division& div) {
	out << "Число мест:" << div.places << endl; 
	out << "Доктора:";
	for (Doc& doctor : div.doctors)
		out << doctor << endl;
	out << "Пациенты:";
	for (Patient& patient : div.patients)
		out << patient << endl;
}

string Dis::getTime() {
	return time;
}

void Dis::setTime(string _time) {
	time = _time;
}

string Doc::getDisease() {
	return disease;
}

string Doc::getPatient() {
	return patient;
}

void Doc::setDisease(string _disease) {
	disease = _disease;
}

void Doc::setPatient(string _patient) {
	patient = _patient;
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