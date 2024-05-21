#pragma once
#include <vector>
#include <fstream>
#include "Patient.h"
class Doctor {
private:
    std::string name;
    std::vector<Patient> patients;

public:
    friend std::istream& operator >>(std::istream& in, Doctor& doc);
    friend std::ostream& operator <<(std::ostream& out, Doctor& doc);

    void addPatient(const Patient& patient);

    std::string getFullName();
    const std::vector<Patient> getPatients() const;

    void saveToFile(std::ofstream& file);
    void loadFromFile(std::ifstream& file);
};