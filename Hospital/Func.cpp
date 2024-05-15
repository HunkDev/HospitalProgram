#include <stdio.h>
#include <string>
#include "Patient.h"
#include "Division.h"
#include "disease.h"
#include "doctor.h"
using namespace std;

istream operator >>(istream& in, Patient& pat) {
	cout << "Введите ФИО:";
	in >> pat._fio;
	cout << "Введите пол:";
	in >> pat._gender;
	cout << "Введите возраст:";
	in >> pat._age;
	cout << "Введите диагноз:";
	in >> pat._diagnosis;
	//cout << "Введите время поступления:";
	//in >> pat._time;
	cout << "Введите ФИО врача:";
	in >> pat._doctor;
	cout << "Введите статус:";
	in >> pat._status;
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

void Disease::setRecoveryTime(int time) {
	recoveryTime = time;
}

void Doctor::addSpecialty(const char* specialty) {
	specialties.push_back(specialty);
}

void Doctor::addPatient(const Patient& patient) {
	patients.push_back(patient);
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