#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head; // global variable - pointer to head node.

void print() {
    Node* temp = head;
    std::cout << "Forward: ";
    while (temp != nullptr) {
        std::cout << temp -> data << " ";
        temp = temp -> next;
    }
    std::cout << std::endl;
}

void reversePrint() {
    Node* temp = head;
    if (temp == nullptr) return;
    while (temp -> next != nullptr) {
        temp = temp -> next;
    }
    std::cout << "Backward: ";
    while (temp != nullptr) {
        std::cout << temp -> data << " ";
        temp = temp -> prev;
    }
    std::cout << std::endl;
}

Node* getNewNode(int x) {
    Node* newNode = new Node();
    newNode -> data = x;
    newNode -> next = nullptr;
    newNode -> prev = nullptr;
    return newNode;
}

void insertAtHead(int x) {
    Node* newNode = getNewNode(x);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    head -> prev = newNode;
    newNode -> next = head;
    head = newNode;
}

int main()
{
    head = nullptr; // empty list.
    insertAtHead(2); print(); reversePrint();
    insertAtHead(4); print(); reversePrint();
    insertAtHead(6); print(); reversePrint();
    return 0;
}

