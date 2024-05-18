#pragma once
#include <vector>
#include <fstream>

class Disease;

class Disease {
private:
    char name[100];
    int recoveryTime; 

public:
    Disease(const char* name, int recoveryTime);
    ~Disease();

    const char* getName() const;
    void setName(const char* name);

    int getRecoveryTime();
    void setRecoveryTime(int time);

    void saveToFile(std::ofstream& file) const;
    void loadFromFile(std::ifstream& file);
};