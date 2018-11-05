#include <iostream>

#define MAX_SIZE 101

int A[MAX_SIZE];
int top = -1;

void push(int x) {
    if (MAX_SIZE == top - 1) {
        std::cout << "Error: Stack overflow!" << std::endl;
        return;
    }
    A[++top] = x;
}

void pop() {
    if (-1 == top) {
        std::cout << "Error: No element to pop!" << std::endl;
        return;
    }
    top--;
}

int Top() {
    if (-1 == top) {
        std::cout << "Error: stack has no element" << std::endl;
        return -1;
    }
    return A[top];
}

bool isEmpty() {
    return -1 == top;
}

void print() {
    int i;
    std::cout << "Stack: ";
    for (i = 0; i <= top; i++) {
        std::cout << A[i] << " ";
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
