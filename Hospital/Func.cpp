#include <stdio.h>
#include <string>
#include "Patient.h"
#include "Division.h"
#include "disease.h"
#include "doctor.h"
using namespace std;

istream operator >>(istream& in, Patient& pat) {
	cout << "Ââåäèòå ÔÈÎ:";
	in >> pat._fio;
	cout << "Ââåäèòå ïîë:";
	in >> pat._gender;
	cout << "Ââåäèòå âîçðàñò:";
	in >> pat._age;
	cout << "Ââåäèòå äèàãíîç:";
	in >> pat._diagnosis;
	//cout << "Ââåäèòå âðåìÿ ïîñòóïëåíèÿ:";
	//in >> pat._time;
	cout << "Ââåäèòå ÔÈÎ âðà÷à:";
	in >> pat._doctor;
	cout << "Ââåäèòå ñòàòóñ:";
	in >> pat._status;
}

ostream& operator <<(ostream& out, Patient& pat) {
	out << " ÔÈÎ: " << pat._fio << " Ïîë: " << pat._gender << " Âîçðàñò: " << pat._age << " Äèàãíîç: " << pat._diagnosis << " ÔÈÎ âðà÷à: " << pat._doctor << " Ñòàòóñ: " << pat._status << endl;
}

istream& operator >>(istream& in, Division& div) {
	cout << "Ââåäèòå êîë-âî ìåñò";
	in >> div.places;
}

ostream& operator <<(ostream& out, Division& div) {
	out << "×èñëî ìåñò:" << div.places << endl; 
	out << "Äîêòîðà:";
	for (Doc& doctor : div.doctors)
		out << doctor << endl;
	out << "Ïàöèåíòû:";
	for (Patient& patient : div.patients)
		out << patient << endl;
}

string Dis::getTime() {
	return time;
}

ostream& operator <<(ostream& out, Patient& pat) {
	out << " ÔÈÎ: " << pat._fio << " Ïîë: " << pat._gender << " Âîçðàñò: " << pat._age << " Äèàãíîç: " << pat._diagnosis << " ÔÈÎ âðà÷à: " << pat._doctor << " Ñòàòóñ: " << pat._status << endl;
}

istream& operator >>(istream& in, Division& div) {
	cout << "Ââåäèòå êîë-âî ìåñò";
	in >> div.places;
}

ostream& operator <<(ostream& out, Division& div) {
	out << "×èñëî ìåñò:" << div.places << endl; 
	out << "Äîêòîðà:";
	for (Doctor& doctor : div.doctors)
		out << doctor << endl;
	out << "Ïàöèåíòû:";
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