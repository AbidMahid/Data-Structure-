#include <iostream>
using namespace std;

class CQueue {
private:
    int* arr;
    int f, r;
    int cap;
    int cnt;

public:
    CQueue(int size) {
        cap = size;
        arr = new int[cap];
        f = 0;
        r = -1;
        cnt = 0;
    }

    void push(int val) {
        if (isFull()) {
            cout << "Queue is full!\n";
            return;
        }
        r = (r + 1) % cap;
        arr[r] = val;
        cnt++;
        cout << val << " pushed\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << arr[f] << " popped\n";
        f = (f + 1) % cap;
        cnt--;
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return arr[f];
    }

    bool isEmpty() {
        return cnt == 0;
    }

    bool isFull() {
        return cnt == cap;
    }

    void show() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue: ";
        for (int i = 0; i < cnt; i++) {
            int idx = (f + i) % cap;
            cout << arr[idx] << " ";
        }
        cout << endl;
    }

    ~CQueue() {
        delete[] arr;
    }
};

int main() {
    int size, choice, val;

    cout << "Enter queue size: ";
    cin >> size;

    CQueue q(size);

    do {
        cout << "\n1. Push\n2. Pop\n3. Front\n4. Show\n5. Exit\nChoice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                q.push(val);
                break;
            case 2:
                q.pop();
                break;
            case 3:
                cout << "Front: " << q.front() << endl;
                break;
            case 4:
                q.show();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while(choice != 5);

    return 0;
}
