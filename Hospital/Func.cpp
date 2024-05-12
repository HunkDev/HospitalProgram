#include <stdio.h>
#include <string>
using namespace std;

string Dis::getTime() {
	return time;
}

void Dis::setTime(string _time) {
	time = _time;
}

string Doc::getDisease() {
	return disease;
}

string Doc::getPatient() {
	return patient;
}

void Doc::setDisease(string _disease) {
	disease = _disease;
}

void Doc::setPatient(string _patient) {
	patient = _patient;
}