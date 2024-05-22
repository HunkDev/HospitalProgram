#pragma once
#include <vector>

#include "Patient.h"
#include "doctor.h"

class Division {
private:
	std::string name;
	int places;
	std::vector<Patient> patients;
	std::vector<std::string> doctors;
public:	
	friend std::istream& operator >>(std::istream& in, Division& div);
	friend std::ostream& operator <<(std::ostream& out, Division& div);
	void attachDoc(std::string& doctor);
	void attachPat(const Patient& patient);
	void setPlaces(int place);
	void setName(std::string str);
	int getPlace();
	std::vector<Patient> get_patients();
	std::string get_name();

	friend void search_division(std::vector<Division> arr);
	friend void delete_division(std::vector<Division> arr);
	friend void add_patient(std::vector<Division>* arr, std::vector<Patient> patients);
	friend void read_divisions(std::vector<Division>* arr);
	friend void delete_patient(std::vector<Division>* arr);
	friend void delete_doctor(std::vector<Division>* arr);
	friend void DayMinus(std::vector<Division>* divisions, int s);
};