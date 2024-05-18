#pragma once
#include <vector>
#include <fstream>
#include "Patient.h"
class Doctor {
private:
    char fullName[100];
    std::vector<Patient> patients;

public:
    friend std::istream& operator >>(std::istream& in, Doctor& doc);
    friend std::ostream& operator <<(std::ostream& out, Doctor& doc);
    Doctor(const char* name);
    ~Doctor();

    void addPatient(const Patient& patient);

    const char* getFullName();
    std::vector<Patient> getPatients();

    void saveToFile(std::ofstream& file);
    void loadFromFile(std::ifstream& file);
};