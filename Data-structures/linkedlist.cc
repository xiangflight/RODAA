// Linked List: Inserting a node at beginning
#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node* head; // global varible can be accessed anywhere

void insert(int num);
void print();

int main()
{
    head = nullptr; // empty list
    std::cout << "How many numbers?" << std::endl;
    int num;
    std::cin >> num;
    int cur;
    for (int i = 0; i < num; i++) {
        std::cout << "Enter the number:" << std::endl;
        std::cin >> cur;
        insert(cur);
        print();
    }
    return 0;
}
    
void insert(int num) {
    Node* temp = new Node();
    temp -> data = num;
    temp -> next = head;
    head = temp;
}

void print() {
    Node* temp = head;
    std::cout << "list is " << std::endl;
    while (temp != nullptr) {
        std::cout << " " << temp -> data;
        temp = temp -> next;
    }
    std::cout << "" << std::endl;
}
