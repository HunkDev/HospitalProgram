#pragma once
#include <vector>
#include <fstream>
#include "Patient.h"
class Doctor {
private:
    std::string name; 

public:
    /// Enter doctor's paramethers
    friend std::istream& operator >>(std::istream& in, Doctor& doc); 
    /// Output doctor's paramethers
    friend std::ostream& operator <<(std::ostream& out, Doctor& doc); 

    /// Output doctor's name
    std::string getFullName(); 

};