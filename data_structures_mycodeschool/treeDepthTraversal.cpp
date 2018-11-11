#include <iostream>

using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
};

// visit nodes in pre order
void preOrder(Node* root) {
    if (root == nullptr) return;
    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}

// visit nodes in in order
void inOrder(Node* root) {
    if (root == nullptr) return;
    inOrder(root -> left);
    cout << root -> data << " ";
    inOrder(root -> right);
}

// visit nodes in post order
void postOrder(Node* root) {
    if (root == nullptr) return;
    postOrder(root -> left);
    postOrder(root -> right);
    cout << root -> data << " ";
}

Node* insert(Node* root, char data) {
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
    root = insert(root, 'M');
    root = insert(root, 'B');
    root = insert(root, 'Q');
    root = insert(root, 'Z');
    root = insert(root, 'A');
    root = insert(root, 'C');
    cout << "PreOrder: ";
    preOrder(root);
    cout << endl;
    cout << "InOrder: ";
    inOrder(root);
    cout << endl;
    cout << "PostOrder: ";
    postOrder(root);
    cout << endl;
    return 0;
}
