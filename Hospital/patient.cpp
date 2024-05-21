#include <iostream>
#include <string>
#include "Patient.h"

std::string Patient::getFio() { return _fio; }
std::string Patient::getGender() { return _gender; }
int Patient::getAge() { return _age; }
std::string Patient::getDia() { return _diagnosis; }
std::string Patient::getDoctor() { return _doctor; }
std::string Patient::getStatus() { return _status; }

void Patient::setFio(std::string fio) { _fio = fio; }
void Patient::setGender(std::string gender) { _gender = gender; }
void Patient::setAge(int age) { _age = age; }
void Patient::setDia(std::string diagnosis) { _diagnosis = diagnosis; }
void Patient::setDoctor(std::string doctor) { _doctor = doctor; }
void Patient::setStatus(std::string status) { _status = status; }
void Patient::advance_day() {
	if (_status == "hospitalized") {
		_days--;
		if (_days <= 0) {
			_status = "discharged";
		}
	}
}