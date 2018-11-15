#include <iostream>
#include <climits>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

bool isBinarySearchTree(Node* root);

bool isBstUtil(Node* root, int minValue, int maxValue);

int lastVisited = INT_MIN;

// use inorder traversal to judge, ascending order
bool isBST(Node* root) {
    if (root == nullptr) return true;
    if (!isBST(root -> left)) {
        return false;
    }
    int curVal = root -> data;
    if (curVal < lastVisited) {
        return false;
    }
    lastVisited = curVal;
    if (!isBST(root -> right)) {
        return false;
    }
    return true;
}

int main() {
 
    return 0;
}

bool isBstUtil(Node* root, int minValue, int maxValue) {
    if (root == nullptr) return true;
    if (root -> data > minValue && root -> data < maxValue
            && isBstUtil(root -> left, minValue, root -> data)
            && isBstUtil(root -> right, root -> data, maxValue)) {
        return true;
    } else {
        return false;
    }
}

bool isBinarySearchTree(Node* root) {
    return isBstUtil(root, INT_MIN, INT_MAX);
}



