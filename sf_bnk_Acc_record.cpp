#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Account {
    int accNo;
    string name;
    float balance;
};

void createFile() {
    ofstream file("accounts.txt", ios::out);

    int n;
    cout << "Enter the number of accounts: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Account acc;
        cout << "Enter Account Number: ";
        cin >> acc.accNo;
        cout << "Enter Name: ";
        cin >> ws; // Clear input buffer
        getline(cin, acc.name);
        cout << "Enter Balance: ";
        cin >> acc.balance;

        file << acc.accNo << " " << acc.name << " " << acc.balance << endl;
    }

    file.close();
    cout << "File created successfully.\n";
}

void deleteAccount(int accNo) {
    ifstream file("accounts.txt", ios::in);
    ofstream tempFile("temp.txt", ios::out);

    Account acc;
    bool found = false;

    while (file >> acc.accNo) {
        file.ignore(); // Ignore space
        getline(file, acc.name, ' ');
        file >> acc.balance;

        if (acc.accNo == accNo) {
            found = true;
            cout << "Account with Account Number " << accNo << " deleted.\n";
        } else {
            tempFile << acc.accNo << " " << acc.name << " " << acc.balance << endl;
        }
    }

    file.close();
    tempFile.close();

    if (found) {
        remove("accounts.txt");
        rename("temp.txt", "accounts.txt");
    } else {
        cout << "Account with Account Number " << accNo << " not found.\n";
    }
}

void displayAccounts() {
    ifstream file("accounts.txt", ios::in);
    Account acc;

    cout << "Account Records:\n";
    while (file >> acc.accNo) {
        file.ignore(); // Ignore space
        getline(file, acc.name, ' ');
        file >> acc.balance;

        cout << "Account No: " << acc.accNo << ", Name: " << acc.name << ", Balance: " << acc.balance << endl;
    }

    file.close();
}

int main() {
    createFile();

    int accNo;
    cout << "Enter Account Number to delete: ";
    cin >> accNo;
    deleteAccount(accNo);

    cout << "Updated Account Records:\n";
    displayAccounts();

    return 0;
}
