#include <stdio.h>
#include <string>
#include "Patient.h"
#include "Division.h"
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
	out << " ФИО: " << pat._fio << " Пол: " << pat._gender << " Возраст: " << pat._age << " Диагноз: " << pat._diagnosis << " ФИО врача: " << pat._doctor << " Статус: " << pat._status << endl;
}

istream& operator >>(istream& in, Division& div) {
	cout << "Введите кол-во мест";
	in >> div.places;
}

ostream& operator <<(ostream& out, Division& div) {
	out << "Число мест:" << div.places << endl; 
	out << "Доктора:";
	for (Doctor& doctor : div.doctors)
		out << doctor << endl;
	out << "Пациенты:";
	for (Patient& patient : div.patients)
		out << patient << endl;
}

int Disease::getRecoveryTime() {
	return recoveryTime;
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