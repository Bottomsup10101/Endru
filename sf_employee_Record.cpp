#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Employee {
    int empNo;
    string name;
    float salary;
};

void createFile() {
    ofstream file("employees.txt", ios::out);

    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Employee e;
        cout << "Enter Employee No: ";
        cin >> e.empNo;
        cout << "Enter Name: ";
        cin >> ws; // Clear input buffer
        getline(cin, e.name);
        cout << "Enter Salary: ";
        cin >> e.salary;

        file << e.empNo << " " << e.name << " " << e.salary << endl;
    }

    file.close();
    cout << "File created successfully.\n";
}

void searchEmployee(int empNo) {
    ifstream file("employees.txt", ios::in);
    Employee e;
    bool found = false;

    while (file >> e.empNo) {
        file.ignore(); // Ignore space
        getline(file, e.name, ' ');
        file >> e.salary;

        if (e.empNo == empNo) {
            cout << "Record Found:\n";
            cout << "Employee No: " << e.empNo << "\nName: " << e.name << "\nSalary: " << e.salary << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Employee with Employee No " << empNo << " not found.\n";
    }

    file.close();
}

int main() {
    createFile();

    int empNo;
    cout << "Enter Employee No to search: ";
    cin >> empNo;
    searchEmployee(empNo);

    return 0;
}
