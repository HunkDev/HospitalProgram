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
	out << " ���: " << pat._fio << " ���: " << pat._gender << " �������: " << pat._age << " �������: " << pat._diagnosis << " ��� �����: " << pat._doctor << " ������: " << pat._status << endl;
}

istream& operator >>(istream& in, Division& div) {
	cout << "������� ���-�� ����";
	in >> div.places;
}

ostream& operator <<(ostream& out, Division& div) {
	out << "����� ����:" << div.places << endl; 
	out << "�������:";
	for (Doctor& doctor : div.doctors)
		out << doctor << endl;
	out << "��������:";
	for (Patient& patient : div.patients)
		out << patient << endl;
}

int Disease::getRecoveryTime() {
	return recoveryTime;

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