#include<iostream>
#include <fstream>

using namespace std;

void write_time(time_t cur_time) {
    tm ct;
    localtime_s(&ct, &cur_time);
    int day = ct.tm_yday;
    ofstream out;
    out.open("time.txt");
    if (!out) return;
    out << day;
    out.close();
}

int read_time() {
    ifstream in;
    in.open("time.txt");
    if (!in)
        return;
    int day;
    in >> day;
    in.close();
    return day;
}