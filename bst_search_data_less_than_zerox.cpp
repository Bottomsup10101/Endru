#include <iostream>
using namespace std;

// Node structure for the BST
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Function to insert a node into the BST
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to list all nodes with data less than zero
void listNodesLessThanZero(Node* root) {
    if (root == nullptr) {
        return;
    }
    // Traverse the left subtree
    listNodesLessThanZero(root->left);

    // Check if the current node's data is less than zero
    if (root->data < 0) {
        cout << root->data << " ";
    }

    // Traverse the right subtree
    listNodesLessThanZero(root->right);
}

int main() {
    Node* root = nullptr;
    int n;

    cout << "Enter the number of nodes: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of nodes. Exiting." << endl;
        return 1;
    }

    cout << "Enter " << n << " node values:" << endl;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        root = insert(root, value);
    }

    cout << "Nodes with data less than zero: ";
    listNodesLessThanZero(root);
    cout << endl;

    return 0;
}
