#include <stdio.h>
#include <string>
#include "Patient.h"
#include "Division.h"
#include "disease.h"
#include "doctor.h"
using namespace std;

istream operator >>(istream& in, Patient& pat) {
	cout << "������� ���:";
	in >> pat._fio;
	cout << "������� ���:";
	in >> pat._gender;
	cout << "������� �������:";
	in >> pat._age;
	cout << "������� �������:";
	in >> pat._diagnosis;
	//cout << "������� ����� �����������:";
	//in >> pat._time;
	cout << "������� ��� �����:";
	in >> pat._doctor;
	cout << "������� ������:";
	in >> pat._status;
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