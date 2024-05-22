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
	std::string _doctor;
	std::string _status;
	int _days;
public:
	 friend std::istream& operator >>(std::istream& in, Patient& pat);
	 friend std::ostream& operator <<(std::ostream& out, Patient& pat);

	 int getAge();
	 std::string getSurname();
	 std::string getName();
	 std::string getGender();
	 std::string getDia();
	 std::string getDoctor();
	 std::string getStatus();

	 void setName(std::string name);
	 void setSurname(std::string surname);
	 void setGender(std::string gender);
	 void setAge(int age);
	 void setDia(std::string diagnosis);
	 void setDoctor(std::string doctor);
	 void setStatus(std::string status);
	 void advance_day();

	 friend void search_patient(std::vector<Patient> arr);
	 friend void delete_patient(std::vector<Patient> arr);
};