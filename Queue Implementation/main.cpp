#include <iostream>
using namespace std;

class Queue {
private:
    int arr[100];
    int front, rear;
    int capacity;

public:
    Queue(int size = 100) {
        front = 0;
        rear = -1;
        capacity = size;
    }

    void enqueue(int value) {
        if (rear >= capacity - 1) {
            cout << "Queue Overflow!\n";
            return;
        }
        arr[++rear] = value;
        cout << value << " enqueued to queue\n";
    }

    void dequeue() {
        if (front > rear) {
            cout << "Queue Underflow!\n";
            return;
        }
        cout << arr[front++] << " dequeued from queue\n";
    }

    int getFront() {
        if (front > rear) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (front > rear) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    cout << "Front element: " << q.getFront() << endl;
    return 0;
}
