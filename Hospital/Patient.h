#pragma once

#include <iostream>
#include <string>
#include <cstring>

class Patient {
	std::string _fio;
	std::string _gender;
	int _age;
	std::string _diagnosis;
	//time_t?
	std::string _doctor;
	std::string _status;
public:
	 friend std::istream& operator >>(std::istream& in, Patient& pat);
	 friend std::ostream& operator <<(std::ostream& out, Patient& pat);

	 int getAge();
	 std::string getFio();
	 std::string getGender();
	 std::string getDia();
	 std::string getDoctor();
	 std::string getStatus();

	 void setFio(std::string fio);
	 void setGender(std::string gender);
	 void setAge(int age);
	 void setDia(std::string diagnosis);
	 void setDoctor(std::string doctor);
	 void setStatus(std::string status);
};