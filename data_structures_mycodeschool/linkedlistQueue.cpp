#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;

void enqueue(int i) {
    Node* temp = new Node();
    temp -> data = i;
    temp -> next = nullptr;
    if (front == nullptr && rear == nullptr) {
        front = rear = temp;
        return;
    }
    rear -> next = temp;
    rear = temp;
}

void dequeue() {
    Node* temp = front;
    if (front == nullptr) {
        cout << "Queue is empty!" << endl;
        return;
    }
    if (front == rear) {
        front = rear = nullptr;
    } else {
        front = front -> next;
    }
    delete temp;
}

int Front() {
    if (front == nullptr) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    return front -> data;
}

void print() {
    Node* temp = front;
    cout << "queue is ";
    while (temp != nullptr) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main() {
    enqueue(1); print();
    enqueue(2); print();
    enqueue(11); print();
    dequeue(); print();
    cout << "front is " << Front() << endl;
    return 0;
}
