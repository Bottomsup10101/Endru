#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }

    Node* curr = root;

    while (true) {
        if (val <= curr->data) {
            if (curr->left == NULL) {
                curr->left = new Node(val);
                break;
            } else {
                curr = curr->left;
            }
        } else {
            if (curr->right == NULL) {
                curr->right = new Node(val);
                break;
            } else {
                curr = curr->right;
            }
        }
    }
    return root;
}

Node* findLastRight(Node* root) {
    if (root->right == NULL) {
        return root;
    }
    return findLastRight(root->right);
}

Node* helper(Node* root) {
    if (root->left == NULL) {
        return root->right;
    } else if (root->right == NULL) {
        return root->left;
    }

    Node* rightChild = root->right;
    Node* lastRight = findLastRight(root->left);
    lastRight->right = rightChild;

    return root->left;
}

Node* deleteNode(Node* root, int val) {
    if (root == NULL) {
        return root;
    }

    if (root->data == val) {
        return helper(root);
    }

    Node* dummy = root;

    while (root != NULL) {
        if (root->data > val) {
            if (root->left != NULL && root->left->data == val) {
                root->left = helper(root->left);
                break;
            } else {
                root = root->left;
            }
        } else {
            if (root->right != NULL && root->right->data == val) {
                root->right = helper(root->right);
                break;
            } else {
                root = root->right;
            }
        }
    }
    return dummy;
}

// Inorder traversal
void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;  

    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 20);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 15);

    cout << "Inorder traversal before deletion: ";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 5); 

    cout << "Inorder traversal after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
