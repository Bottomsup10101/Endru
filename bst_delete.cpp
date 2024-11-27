#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


Node* insert(Node* root, int value) {
    if (root == NULL) {
    return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
return root;
}


Node* findMin(Node* root) {
    while (root && root->left != NULL) {
         root = root->left;
    }
    return root;
}


Node* deleteNode(Node* root, int value) {
    if (root == NULL) {
         return root;
    }
    if (value < root->data) {
         root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
         root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
return root;
}

void preorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}


void inorderTraversal(Node* root) {
    if (root == NULL) {
         return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}


void postorderTraversal(Node* root) {
        if (root == NULL) {
        return;
        }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}


int main() {
    Node* root = NULL;
    int choice, value;
    do {
    cout << "\nMenu:\n";
    cout << "1. Insert a Node\n";
    cout << "2. Delete a Specified Node\n";
    cout << "3. Preorder Traversal\n";
    cout << "4. Inorder Traversal\n";
    cout << "5. Postorder Traversal\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
         case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            root = insert(root, value);
            break;
         case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            root = deleteNode(root, value);
            break;
         case 3:
            cout << "Preorder Traversal: ";
            preorderTraversal(root);
            cout << endl;
            break;
         case 4:
            cout << "Inorder Traversal: ";
            inorderTraversal(root);
            cout << endl;
            break;
        case 5:
            cout << "Postorder Traversal: ";
            postorderTraversal(root);
            cout << endl;
            break;
        case 6:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
return 0;
}
