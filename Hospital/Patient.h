#pragma once

#include <string>
#include <vector>
#include <cstring>

class Patient {
	std::string _name;
	std::string _surname;
	std::string _gender;
	int _age;
	std::string _diagnosis;
	//time_t?
	std::string _status;
	int _days;
public:
	/// Enter patient's paramethers
	 friend std::istream& operator >>(std::istream& in, Patient& pat); 
	 /// Output patient's paramethers
	 friend std::ostream& operator <<(std::ostream& out, Patient& pat); 

	 int getAge();
	 std::string getSurname();
	 std::string getName();
	 std::string getGender();
	 std::string getDia();
	 std::string getStatus();

	 /// Set name to patient
	 void setName(std::string name); 
	 /// Set surname to patient
	 void setSurname(std::string surname); 
	 /// Set gender to patient
	 void setGender(std::string gender); 
	 /// Set age to patient
	 void setAge(int age); 
	 /// Set diagnosis to patient
	 void setDia(std::string diagnosis); 
	 /// Set status to patient
	 void setStatus(std::string status); 
	 /// Skip day
	 void advance_day(); 

	 /// Search patient by name
	 friend void search_patient(std::vector<Patient> arr); 
	 /// Delete patient by name
	 friend void delete_patient(std::vector<Patient> arr); 
};