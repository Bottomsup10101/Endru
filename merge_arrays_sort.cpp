#include <iostream>
using namespace std;

// Function to merge two sorted arrays into a third array
void mergeArrays(int arr1[], int n1, int arr2[], int n2, int merged[]) {
    int i = 0, j = 0, k = 0;

    // Merge the arrays
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    // Copy remaining elements of arr1, if any
    while (i < n1) {
        merged[k++] = arr1[i++];
    }

    // Copy remaining elements of arr2, if any
    while (j < n2) {
        merged[k++] = arr2[j++];
    }
}

// Function to display an array
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr1[10], arr2[10], merged[20];
    int n1, n2;

    cout << "Enter the number of elements in the first array (max 10): ";
    cin >> n1;
    cout << "Enter the elements of the first array (sorted): ";
    for (int i = 0; i < n1; ++i) {
        cin >> arr1[i];
    }

    cout << "Enter the number of elements in the second array (max 10): ";
    cin >> n2;
    cout << "Enter the elements of the second array (sorted): ";
    for (int i = 0; i < n2; ++i) {
        cin >> arr2[i];
    }

    mergeArrays(arr1, n1, arr2, n2, merged);

    cout << "Merged array:" << endl;
    displayArray(merged, n1 + n2);

    return 0;
}
