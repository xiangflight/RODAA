#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// find data in the tree
Node* find(Node* root, int data) {
    if (root == nullptr) return root;
    else if (data < root -> data) {
        return find(root -> left, data);
    } else if (data > root -> data) {
        return find(root -> right, data);
    } else {
        return root;
    }
}

// find node with minimum value in BST
Node* findMin(Node* root) {
    if (root == nullptr) return root;
    while (root -> left != nullptr) {
        root = root -> left;
    }
    return root;
}

// find in-order successor in BST
Node* getSuccessor(Node* root, int data) {
    Node* current = find(root, data);
    if (current == nullptr) return nullptr;
    // case 1: Node has right subtree
    if (current -> right != nullptr) {
        return findMin(current -> right);
    // case 2: No right subtree
    } else {
        Node* successor = nullptr;
        Node* ancestor = root;
        while (ancestor != current) {
            if (current -> data < ancestor -> data) {
                successor = ancestor;
                ancestor = ancestor -> left;
            } else {
                ancestor = ancestor -> right;
            }
        }
        return successor;
    }
}

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

    cout << "in-order: ";
    inOrder(root);
    cout << endl;

    Node* successor = getSuccessor(root, 1);
    if (successor == nullptr) {
        cout << "No successor found!" << endl;
    } else {
        cout << "Successor is " << successor -> data << endl;
    }
    return 0;
}



