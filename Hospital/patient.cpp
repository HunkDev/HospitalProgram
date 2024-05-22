#include <iostream>
#include <string>
#include "Patient.h"

std::string Patient::getName() { return _name; }
std::string Patient::getSurname() { return _surname; }
std::string Patient::getGender() { return _gender; }
int Patient::getAge() { return _age; }
std::string Patient::getDia() { return _diagnosis; }
std::string Patient::getStatus() { return _status; }

void Patient::setName(std::string name) { _name = name; }
void Patient::setSurname(std::string surname) { _surname = surname; }
void Patient::setGender(std::string gender) { _gender = gender; }
void Patient::setAge(int age) { _age = age; }
void Patient::setDia(std::string diagnosis) { _diagnosis = diagnosis; }
void Patient::setStatus(std::string status) { _status = status; }
void Patient::advance_day() {
	if (!(_status == "discharged")) {
		_days--;
		if (_days <= 0) {
			_status = "discharged";
		}
	}
}