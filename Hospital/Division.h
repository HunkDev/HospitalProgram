#pragma once
#include <iostream>
#include <list>
#include "patient.h"
#include "doctor.h"

class Division {
private:
	int places;
	std::list<Patient&> patients;
	std::list<Doctor&> doctors;
public:
	friend std::istream& operator >>(std::istream& in, Division div);
	friend std::ostream& operator <<(std::ostream& out, Division div);
	void attachDoc(Doctor& doctor);
	void attachPat(Patient& patient);
	void setPlaces(int place);
	int getPlace();
};