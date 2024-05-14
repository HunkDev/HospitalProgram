#include <iostream>
#include <string>

class Patient {
	int _age;
	int _time;

	std::string _fio;
	std::string _gender;
	std::string _diagnoz;
	std::string _doctor;
	std::string _status;

private:
	// Getters
	std::string fio() {
		return _fio;
	}

	std::string gender() {
		return _gender;
	}

	std::string diagnoz() {
		return _diagnoz;
	}

	std::string doctor() {
		return _doctor;
	}

	std::string status() {
		return _status;
	}

	int age() {
		return _age;
	}

	int time() {
		return _time;
	}

	// Setters
	void set_fio(std::string fio) {
		_fio = fio;
	}

	void set_gender(std::string gender) {
		_gender = gender;
	}

	void set_diagnoz(std::string diagnoz) {
		_diagnoz = diagnoz;
	}

	void set_doctor(std::string doctor) {
		_doctor = doctor;
	}

	void set_status(std::string status) {
		_status = status;
	}

	void set_age(int age) {
		_age = age;
	}

	void set_time(int time) {
		_time = time;
	}
};