#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

void insertLinearProbingWithReplacement(int hashTable[], int key) {
    int index = key % TABLE_SIZE;

    // If collision occurs, check if current position is replaceable
    if (hashTable[index] != -1) {
        int existingKeyIndex = hashTable[index] % TABLE_SIZE;

        // If the existing key belongs elsewhere, replace and rehash
        if (existingKeyIndex != index) {
            int temp = hashTable[index];
            hashTable[index] = key;
            key = temp; // Rehash the replaced key
        }
    }

    int originalIndex = index;

    // Handle collision by probing
    while (hashTable[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) {
            cout << "Hash table is full. Cannot insert " << key << endl;
            return;
        }
    }

    hashTable[index] = key;
}

void displayHashTable(int hashTable[]) {
    cout << "Hash Table: ";
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != -1)
            cout << hashTable[i] << " ";
        else
            cout << "- ";
    }
    cout << endl;
}

int main() {
    int hashTable[TABLE_SIZE];

    // Initialize hash table to -1
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }

    int n;
    cout << "Enter number of elements (max 10): ";
    cin >> n;

    if (n > 10) {
        cout << "Error: Maximum 10 elements allowed." << endl;
        return 0;
    }

    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        insertLinearProbingWithReplacement(hashTable, key);
    }

    displayHashTable(hashTable);
    return 0;
}
