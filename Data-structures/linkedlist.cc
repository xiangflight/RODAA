// Linked List: Inserting a node
#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node* head; // global varible can be accessed anywhere

void insertAtBeginning(int num);
void insert(int num, int n);
void insertAtEnd(int num);
void deleteNode(int n); // delete node at position n
void reverse();
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
        insertAtBeginning(cur);
        print();
    }
    insert(2,1);
    insert(3,2);
    insert(4,1);
    insert(5,2);
    insertAtEnd(2);
    insertAtEnd(4);
    insertAtEnd(6);
    insertAtEnd(5);
    print();
    std::cout << "Now you will delete a number at an input position: " << std::endl;
    std::cout << "Enter a position which you want to delete: " << std::endl;
    int pos;
    std::cin >> pos;
    deleteNode(pos);
    print();
    std::cout << "Now reverse the list: " << std::endl;
    reverse();
    print();
    return 0;
}
    
void insertAtBeginning(int num) {
    Node* temp = new Node();
    temp -> data = num;
    temp -> next = head;
    head = temp;
}

void insert(int num, int n) {
    Node* temp1 = new Node();
    temp1 -> data = num;
    temp1 -> next = nullptr;
    if (n == 1) {
        temp1 -> next = head;
        head = temp1;
        return;
    }
    Node* temp2 = head;
    for (int i = 0; i < n - 2; i++) {
        temp2 = temp2 -> next;
    }
    temp1 -> next = temp2 -> next;
    temp2 -> next = temp1;
}

void insertAtEnd(int num) {
    Node* temp1 = new Node();
    temp1 -> data = num;
    temp1 -> next = nullptr;
    if (head == nullptr) {
       head = temp1;
       return;
    }
    Node* temp2 = head;
    while (temp2 -> next != nullptr) {
       temp2 = temp2 -> next;
    }
    temp2 -> next = temp1; 
}

void deleteNode(int pos) {
    Node* temp1 = head;
    if (pos == 1) {
        head = temp1 -> next;
        delete temp1;
        return;
    }
    for (int i = 0; i < pos - 2; i++) {
        temp1 = temp1 -> next;
    }
    Node* temp2 = temp1 -> next;
    temp1 -> next = temp2 -> next;
    delete temp2;
}

void reverse() {
    Node *current, *prev, *next;
    current = head;
    prev = nullptr;
    while (current != nullptr) {
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    head = prev;
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
