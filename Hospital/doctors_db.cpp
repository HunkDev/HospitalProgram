#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void read_doc() {
    string line;
    ifstream in("doc_database.txt");
    if (in.is_open()){
        while (getline(in, line)){
            cout << line << endl;
        }
    }
    in.close();
}

void write_doc(fstream& db) {
    db.open("doc_database.txt", ios::out | ios::app);
    if (!db.is_open()) {
        cout << "Error opening file" << endl;
    } else {
        cout << "File is ready for editing" << endl;
    }
}

void create_doc(fstream& db) {
    int n;
    string name;
    if (db.is_open()) {
        db.close(); 
        db.open("doc_database.txt", ios::out | ios::trunc); 
        cout << "How many doctors you want to add? n= ";
        cin >> n;
        cin.ignore(); 

        if (n < 1) {
            cout << "Error: Invalid number of doctors" << endl;
            return;
        }

        for (int i = 1; i <= n; ++i) {
            cout << "Doctor's name: ";
            getline(cin, name);
            db << i << ". " << name << endl;
        }
        db.close();
    } else {
        cout << "File is not open" << endl;
    }
}

void add_doc(fstream& db) {
    string line;
    string last_line;
    int n;
    string name;

    if (db.is_open()) {
        db.close();
        db.open("doc_database.txt", ios::in); 
        if (!db) {
            cout << "No file to read from" << endl;
            return;
        }

        while (getline(db, line)) {
            last_line = line;
        }
        db.close();

        int last_id = 0;
        if (!last_line.empty()) {
            last_id = stoi(last_line.substr(0, last_line.find('.')));
        }

        db.open("doc_database.txt", ios::out | ios::app); 
        cout << "How many doctors you want to add? n= ";
        cin >> n;
        cin.ignore();

        if (n < 1) {
            cout << "Error: Invalid number of doctors" << endl;
            return;
        }

        for (int i = last_id + 1; i <= last_id + n; ++i) {
            cout << "Doctor's name: ";
            getline(cin, name);
            db << i << ". " << name << endl;
        }
        db.close();

    } else {
        cout << "File is not open" << endl;
    }
}

void search_doc(fstream& db) {
    int id;
    int current_id;
    string line;
    string line_0;

    cout << "Type in id of doctor to find, id= ";
    cin >> id;

    db.close(); 
    db.open("doc_database.txt", ios::in); 

    if (db.is_open()) {
        while (getline(db, line)) {
            line_0 = line.substr(0, line.find('.'));
            current_id = stoi(line_0);
            if (current_id == id) {
                cout << line << endl;
                break;
            }
        }
        db.close();
    } else {
        cout << "File is not open" << endl;
    }
}

void delete_doc(fstream& db) {
    int id;
    int current_id;
    int counter = 0;
    string line;
    string line_0;
    vector<string> lines;
    string data = "";

    cout << "Type in id of doctor to delete, id= ";
    cin >> id;

    db.close(); 
    db.open("doc_database.txt", ios::in); 

    if (db.is_open()) {
        while (getline(db, line)) {
            line_0 = line.substr(0, line.find('.'));
            current_id = stoi(line_0);
            if (current_id != id) {
                lines.push_back(line);
            }
        }
        db.close();

        db.open("doc_database.txt", ios::out | ios::trunc); 

        for (int i = 0; i < lines.size(); ++i) {
            lines[i].erase(0, lines[i].find(".") + 1);
            db << (i+1) << ". " << lines[i] << endl;
        }
        db.close();

    } else {
        cout << "File is not open" << endl;
    }
}
