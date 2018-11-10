#include <iostream>
#include <stack>
using namespace std;
struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void reverse() {
    if (head == nullptr) return;
    stack<Node*> S;
    Node* temp = head;
    while (temp != nullptr) {
        S.push(temp);
        temp = temp -> next;
    }
    temp = S.top();
    head = temp;
    S.pop();
    while (!S.empty()) {
        temp -> next = S.top();
        S.pop();
        temp = temp -> next;
    }
    temp -> next = nullptr;
}

int main() {
    return 0;
}
