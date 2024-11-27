#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Item {
    int itemNo;
    string name;
    float price;
};

void createFile() {
    ofstream file("items.txt", ios::out);

    int n;
    cout << "Enter number of items: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Item it;
        cout << "Enter Item No: ";
        cin >> it.itemNo;
        cout << "Enter Name: ";
        cin >> ws; // Clear input buffer
        getline(cin, it.name);
        cout << "Enter Price: ";
        cin >> it.price;

        file << it.itemNo << " " << it.name << " " << it.price << endl;
    }

    file.close();
    cout << "File created successfully.\n";
}

void listItemsWithPriceBelow100() {
    ifstream file("items.txt", ios::in);
    Item it;
    bool found = false;

    cout << "Items with Price Below 100:\n";
    while (file >> it.itemNo) {
        file.ignore(); // Ignore space
        getline(file, it.name, ' ');
        file >> it.price;

        if (it.price < 100.0) {
            cout << "Item No: " << it.itemNo << ", Name: " << it.name << ", Price: " << it.price << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No items found with price below 100.\n";
    }

    file.close();
}

int main() {
    createFile();
    listItemsWithPriceBelow100();

    return 0;
}
