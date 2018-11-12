#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// find min in a binary search tree
Node* findMin(Node* root) {
    while (root -> left != nullptr) {
        root = root -> left;
    }
    return root;
}

// delete a node in a BST
Node* deleteNode(Node* root, int data) {
    if (root == nullptr) return root;
    else if (data < root -> data) {
        root -> left = deleteNode(root -> left, data);
    } else if (data > root -> data) {
        root -> right = deleteNode(root -> right, data);
    } else {
        // case 1: No child
        if (root -> left == nullptr && root -> right == nullptr) {
            delete root;
            root = nullptr;
        } else if (root -> left == nullptr) {
            Node* temp = root;
            root = root -> right;
            delete temp;
        } else if (root -> right == nullptr) {
            Node* temp = root;
            root = root -> left;
            delete temp;
        } else {
            Node* temp = findMin(root -> right);
            root -> data = temp -> data;
            root -> right = deleteNode(root -> right, temp -> data);
        }
    }
    return root;
}

// visit nodes in in-order
void inOrder(Node* root) {
    if (root == nullptr) return;
    inOrder(root -> left);
    cout << root -> data << " ";
    inOrder(root -> right);
}

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        root = new Node();
        root -> data = data;
        root -> left = root -> right = nullptr;
    } else if (data <= root -> data) {
        root -> left = insert(root -> left, data);
    } else {
        root -> right = insert(root -> right, data);
    }
    return root;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 1);
    root = insert(root, 11);

    root = deleteNode(root, 5);
    cout << "In order: ";
    inOrder(root);
    cout << endl;
    return 0;
}
