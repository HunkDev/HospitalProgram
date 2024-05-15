#pragma once

#include <iostream>
#include <cstring>

class Patient {
	char _fio[100];
	char _gender[100];
	int _age;
	char _diagnosis[200];
	//time_t?
	char _doctor[100];
	char _status[100];
public:
	 friend std::istream operator >>(std::istream& in, Patient& pat);
	 friend std::ostream& operator <<(std::ostream& out, Patient& pat);
	 const char* getFio() {
		return _fio;
	}
	 void setFio(const char* fio) {
		 strncpy(_fio, fio, 100);
	 }

	 const char* getGender() {
		 return _gender;
	 }
	 void setGender(const char gender) {
		 strncpy(_gender, gender, 100);
	 }

	 int getAge() {
		 return _age;
	 }

	 void setAge(int age) {
		 _age = age;
	 }

	 const char* getDia() {
		 return _diagnosis;
	 }
	 void setDia(char* diagnosis) {
		 strncpy(_diagnosis, diagnosis, 200);
	 }

	 const char* getDoctor() {
		 return _doctor;
	 }
	 void setDoctor(char* doctor) {
		 strncpy(_doctor, doctor, 100);
	 }

	 const char* getStatus() {
		 return _status;
	 }
	 void setStatus(const char status) {
		 strncpy(_status, status, 100);
	 }
};