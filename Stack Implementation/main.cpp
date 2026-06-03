#include <iostream>
using namespace std;

class Stack {
private:
    int arr[100];
    int top;
    int capacity;

public:
    Stack(int size = 100) {
        top = -1;
        capacity = size;
    }

    void push(int value) {
        if (top >= capacity - 1) {
            cout << "Stack Overflow!\n";
            return;
        }
        arr[++top] = value;
        cout << value << " pushed to stack\n";
    }

    void pop() {
        if (top < 0) {
            cout << "Stack Underflow!\n";
            return;
        }
        cout << arr[top--] << " popped from stack\n";
    }

    int peek() {
        if (top < 0) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top < 0;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    cout << "Top element: " << s.peek() << endl;
    s.pop();
    s.display();
    return 0;
}
