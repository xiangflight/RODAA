#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node* top = nullptr;

void push(int x) {
    Node* temp = new Node();
    temp -> data = x;
    temp -> next = top;
    top = temp;
}

void pop() {
    if (top == nullptr) return;
    Node* temp = top;
    top = temp -> next;
    delete temp;
}

int Top() {
    if (top == nullptr) return -1;
    return top -> data;
}

bool isEmpty() {
    return nullptr == top;
}

void print() {
    std::cout << "Stack: ";
    Node* temp = top;
    while (temp != nullptr) {
        std::cout << temp -> data << " ";
        temp = temp -> next;
    }
    std::cout << std::endl;
}    

int main() {
    push(2); print();
    push(5); print();
    push(10); print();
    pop(); print();
    push(12); print();
    return 0;
}
