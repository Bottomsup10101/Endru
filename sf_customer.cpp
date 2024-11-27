#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Customer {
    int custID;
    string name;
    float dueAmount;
};

void createFile() {
    ofstream file("customers.txt", ios::out);

    int n;
    cout << "Enter the number of customers: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Customer cust;
        cout << "Enter Customer ID: ";
        cin >> cust.custID;
        cout << "Enter Name: ";
        cin >> ws; // Clear input buffer
        getline(cin, cust.name);
        cout << "Enter Due Amount: ";
        cin >> cust.dueAmount;

        file << cust.custID << " " << cust.name << " " << cust.dueAmount << endl;
    }

    file.close();
    cout << "File created successfully.\n";
}

void calculateTotalDue() {
    ifstream file("customers.txt", ios::in);
    Customer cust;
    float totalDue = 0;

    cout << "Customer Records:\n";
    while (file >> cust.custID) {
        file.ignore(); // Ignore space
        getline(file, cust.name, ' ');
        file >> cust.dueAmount;

        cout << "Customer ID: " << cust.custID << ", Name: " << cust.name << ", Due Amount: " << cust.dueAmount << endl;
        totalDue += cust.dueAmount;
    }

    cout << "Total Due Amount to be Collected: " << totalDue << endl;
    file.close();
}

int main() {
    createFile();
    calculateTotalDue();

    return 0;
}
