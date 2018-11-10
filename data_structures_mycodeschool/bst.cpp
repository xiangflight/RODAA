#include <iostream>
#include <algorithm>

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

int findMin(BstNode* root) {
    if (root == nullptr) {
        cout << "Error: tree is empty" << endl;
        return -1;
    }
    while (root -> left != nullptr) {
        root = root -> left;
    }
    return root -> data;
}

int findMax(BstNode* root) {
    if (root == nullptr) {
        cout << "Error: tree is empty" << endl;
        return -1;
    }
    while (root -> right != nullptr) {
        root = root -> right;
    }
    return root -> data;
}

int findMinRecursion(BstNode* root) {
    if (root == nullptr) {
        cout << "Error: tree is empty" << endl;
        return -1;
    }
    if (root -> left == nullptr) {
        return root -> data;
    }
    return findMinRecursion(root -> left);
}

int findMaxRecursion(BstNode* root) {
    if (root == nullptr) {
        cout << "Error: tree is empty" << endl;
        return -1;
    }
    if (root -> right == nullptr) {
        return root -> data;
    }
    return findMaxRecursion(root -> right);
}

int findHeight(BstNode* root) {
    if (root == nullptr) {
        return -1;
    }
    return max(findHeight(root -> left), findHeight(root -> right)) + 1;
}

int main() {
    BstNode* root = nullptr; // create an empty tree
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 12);
    root = insert(root, 2);
    root = insert(root, 21);
    root = insert(root, 100);
    int height = findHeight(root);
    int max = findMax(root);
    int min = findMin(root);
    cout << "Tree height: " << height << ", max: " << max << ", min: " << min << endl;
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
