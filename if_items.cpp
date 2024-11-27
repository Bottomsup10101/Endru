#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Item {
    int itemNo;
    char name[50];
    float price;
};

// Function to create the file and index
void createIndexedFile() {
    ofstream dataFile("items.dat", ios::binary);
    ofstream indexFile("item_index.dat");

    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Item it;
        cout << "Enter Item Number: ";
        cin >> it.itemNo;
        cout << "Enter Name: ";
        cin >> ws; // Clear buffer
        cin.getline(it.name, 50);
        cout << "Enter Price: ";
        cin >> it.price;

        // Record the position of this item in the data file
        streampos pos = dataFile.tellp();
        dataFile.write(reinterpret_cast<char*>(&it), sizeof(Item));

        // Write item number and position to the index file
        indexFile << it.itemNo << " " << pos << endl;
    }

    dataFile.close();
    indexFile.close();
    cout << "Indexed file created successfully.\n";
}

// Function to list items with price below 100
void listItemsBelow100() {
    ifstream dataFile("items.dat", ios::binary);

    if (!dataFile) {
        cout << "File not found.\n";
        return;
    }

    Item it;
    bool found = false;

    cout << "Items with Price Below 100:\n";
    while (dataFile.read(reinterpret_cast<char*>(&it), sizeof(Item))) {
        if (it.price < 100.0) {
            cout << "Item Number: " << it.itemNo << ", Name: " << it.name << ", Price: " << it.price << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No items found with price below 100.\n";
    }

    dataFile.close();
}

int main() {
    createIndexedFile();
    listItemsBelow100();

    return 0;
}
