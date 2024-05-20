#pragma once
#include <iostream>
#include <list>

#include "Patient.h"
#include "doctor.h"

class Division {
private:
	std::string name;
	int places;
	std::list<Patient&> patients;
	std::list<Doctor&> doctors;
public:
	friend std::istream& operator >>(std::istream& in, Division& div);
	friend std::ostream& operator <<(std::ostream& out, Division& div);
	void attachDoc(Doctor& doctor);
	void attachPat(Patient& patient);
	void setPlaces(int place);
	int getPlace();

	friend Division search_division(class Division* arr, int n, std::string division);
	friend void delete_division(class Division** arr, int* n);
};