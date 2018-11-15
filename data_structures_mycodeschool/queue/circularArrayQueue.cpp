#include <iostream>

using namespace std;

#define MAX_SIZE 101

class Queue {
    private:
        int A[MAX_SIZE];
        int front, rear;
    public:
        Queue() {
            front = -1;
            rear = -1;
        }
        
        bool isEmpty() {
            return (front == -1 && rear == -1);
        }

        bool isFull() {
            return (rear + 1) % MAX_SIZE == front? true: false;
        }

        void enqueue(int i) {
            cout << "Enqueue " << i << endl;
            if (isFull()) {
                cout << "Error: Queue is full!" << endl;
                return;
            } else if (isEmpty()) {
                front = rear = 0;
            } else {
                rear = (rear + 1) % MAX_SIZE;
            }
            A[rear] = i;
        }

        void dequeue() {
            cout << "Dequeue" << endl;
            if (isEmpty()) {
                cout << "Error:N Queue is empty!" << endl;
                return;
            } else if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % MAX_SIZE;
            }
        }

        int Front() {
            if (front == -1) {
                cout << "Error: cannot return front from empty queue!" << endl;
                return -1;
            }
            return A[front];
        }

        void print() {
            int count = (rear + MAX_SIZE - front) % MAX_SIZE + 1;
            cout << "Queue: ";
            for (int i = 0; i < count; i++) {
                int index = (front + i) % MAX_SIZE;
                cout << A[index] << " ";
            }
            cout << endl;
        }
};

int main() {
    Queue q;
    q.enqueue(2); q.print();
    q.enqueue(3); q.print();
    q.enqueue(5); q.print();
    q.dequeue(); q.print();
    q.enqueue(1); q.print();
    return 0;
}
