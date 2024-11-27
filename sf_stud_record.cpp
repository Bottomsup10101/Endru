#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks;
};

void createFile() {
    ofstream file("students.txt", ios::out);

    int n;
    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Student s;
        cout << "Enter Roll No: ";
        cin >> s.rollNo;
        cout << "Enter Name: ";
        cin >> ws; // Clear input buffer
        getline(cin, s.name);
        cout << "Enter Marks: ";
        cin >> s.marks;

        file << s.rollNo << " " << s.name << " " << s.marks << endl;
    }

    file.close();
    cout << "File created successfully.\n";
}

void searchStudent(int rollNo) {
    ifstream file("students.txt", ios::in);
    Student s;
    bool found = false;

    while (file >> s.rollNo) {
        file.ignore(); // Ignore space
        getline(file, s.name, ' ');
        file >> s.marks;

        if (s.rollNo == rollNo) {
            cout << "Record Found:\n";
            cout << "Roll No: " << s.rollNo << "\nName: " << s.name << "\nMarks: " << s.marks << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student with Roll No " << rollNo << " not found.\n";
    }

    file.close();
}

int main() {
    createFile();

    int rollNo;
    cout << "Enter Roll No to search: ";
    cin >> rollNo;
    searchStudent(rollNo);

    return 0;
}
