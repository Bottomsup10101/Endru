#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    char name[50];
    float marks;
};

// Function to create the file and index
void createIndexedFile() {
    ofstream dataFile("students.dat", ios::binary);
    ofstream indexFile("student_index.dat");

    if (!dataFile || !indexFile) {
        cout << "Error creating files.\n";
        return;
    }

    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Student s;
        cout << "Enter Roll Number: ";
        cin >> s.rollNo;
        cout << "Enter Name: ";
        cin >> ws; // Clear buffer before reading a line
        cin.getline(s.name, 50);
        cout << "Enter Marks: ";
        cin >> s.marks;

        // Record the position of this student in the data file
        streampos pos = dataFile.tellp();  // Get current position in the file
        dataFile.write(reinterpret_cast<char*>(&s), sizeof(Student));

        // Write roll number and position to the index file
        indexFile << s.rollNo << " " << pos << endl;
    }

    dataFile.close();
    indexFile.close();
    cout << "Indexed file created successfully.\n";
}

// Function to search for a student by roll number
void searchStudent(int rollNo) {
    ifstream dataFile("students.dat", ios::binary);
    ifstream indexFile("student_index.dat");

    if (!dataFile || !indexFile) {
        cout << "File not found.\n";
        return;
    }

    int key;
    streampos pos;
    bool found = false;

    // Read through the index file to find the roll number
    while (indexFile >> key >> pos) {
        if (key == rollNo) {
            dataFile.seekg(pos);  // Move the data file pointer to the correct position
            Student s;
            dataFile.read(reinterpret_cast<char*>(&s), sizeof(Student));  // Read the student record

            // Output the found student record
            cout << "Record Found:\n";
            cout << "Roll Number: " << s.rollNo << "\nName: " << s.name << "\nMarks: " << s.marks << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student with Roll Number " << rollNo << " not found.\n";
    }

    dataFile.close();
    indexFile.close();
}

int main() {
    createIndexedFile();

    int rollNo;
    cout << "Enter Roll Number to search: ";
    cin >> rollNo;
    searchStudent(rollNo);

    return 0;
}
