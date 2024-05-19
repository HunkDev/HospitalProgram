#pragma once

#include <iostream>


void create_divisions(class Division** arr, int* n);
void write_divisions(const class Division* arr, int n);
void read_divisions(class Division** arr, int* n);
void add_division(class Division** arr, int* n);
Division search_division(class Division* arr, int n, std::string division);
void delete_division(class Division** arr, int* n);
