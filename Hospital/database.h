#pragma once

#include <iostream>

std::string to_lower(const std::string& str);

void create_patients(class Patient** arr, int* n);
void write_patients(const class Patient* arr, int n);
void read_patients(class Patient** arr, int* n);
void add_patient(class Patient** arr, int* n);
Patient search_patient(class Patient* arr, int n, std::string patient);
void delete_patient(class Patient** arr, int* n);