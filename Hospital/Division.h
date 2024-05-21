#pragma once
#include <list>

#include "Patient.h"
#include "doctor.h"

class Division {
private:
	std::string name;
	int places;
	std::list<Patient> patients;
	std::list<Doctor> doctors;
public:
	friend std::istream& operator >>(std::istream& in, Division& div);
	friend std::ostream& operator <<(std::ostream& out, Division& div);
	void attachDoc(const Doctor& doctor);
	void attachPat(const Patient& patient);
	void setPlaces(int place);
	int getPlace();
	std::string get_name();

	friend Division search_division(std::vector<Division> arr, std::string division);
	friend void delete_division(std::vector<Division> arr);
};