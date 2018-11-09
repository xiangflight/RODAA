#include <iostream>

using namespace std;

struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};

// create a new node
BstNode* getNewNode(int data) {
    BstNode* newNode = new BstNode();
    newNode -> data = data;
    newNode -> left = newNode -> right = nullptr;
    return newNode;
}

// insert a new node into bst
BstNode* insert(BstNode* root, int data) {
    if (root == nullptr) {
        root = getNewNode(data);
    } else if (data <= root -> data) {
        root -> left = insert(root -> left, data);
    } else {
        root -> right = insert(root -> right, data);
    }
    return root;
}

// search an element in BST, return true if it is found
bool search(BstNode* root, int data) {
    if (root == nullptr) {
        return false;
    } else if (root -> data == data)  {
        return true;
    } else if (data <= root -> data) {
        return search(root -> left, data);
    } else {
        return search(root -> right, data);
    }
}

int main() {
    BstNode* root = nullptr; // create an empty tree
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 12);
    int num;
    cout << "Please enter a number to be searched: ";
    cin >> num;
    if (search(root, num)) {
        cout << "Found it!";
    } else {
        cout << "Sorry, Not found it!";
    }
    cout << endl;
    return 0;
}
