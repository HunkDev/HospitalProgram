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
	/// Enter division's paramethers
	friend std::istream& operator >>(std::istream& in, Division& div);
	/// Output division's paramethers
	friend std::ostream& operator <<(std::ostream& out, Division& div); 
	/// Appoint doctor to the division
	void attachDoc(std::string& doctor); 
	/// Appoint pacient to the division
	void attachPat(const Patient& patient); 
	/// Change the number of places in the division
	void setPlaces(int place); 
	/// Change division name
	void setName(std::string str); 
	/// Output division's places
	int getPlace(); 
	/// Output patients in divisions
	std::vector<Patient> get_patients(); 
	/// Output name of division
	std::string get_name(); 

	/// Search division by name
	friend void search_division(std::vector<Division> arr); 
	/// Delete division by name
	friend void delete_division(std::vector<Division> arr); 
	/// Add patient in division
	friend void add_patient(std::vector<Division>* arr, std::vector<Patient> patients); 
	/// Read divisions from a file
	friend void read_divisions(std::vector<Division>* arr); 
	/// Delete patient from division
	friend void delete_patient(std::vector<Division>* arr); 
	/// Delete doctor from division
	friend void delete_doctor(std::vector<Division>* arr); 
	/// Skip day
	friend void DayMinus(std::vector<Division>* divisions, int s); 
};