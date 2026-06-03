#include <iostream>
using namespace std;

class ArrayDS {
private:
    int arr[100];
    int size;

public:
    ArrayDS() {
        size = 0;
    }

    void insert(int position, int value) {
        if (position < 0 || position > size || size >= 100) {
            cout << "Invalid position or array full!\n";
            return;
        }

        for (int i = size; i > position; i--) {
            arr[i] = arr[i - 1];
        }
        arr[position] = value;
        size++;
        cout << "Inserted " << value << " at position " << position << endl;
    }

    void deletion(int position) {
        if (position < 0 || position >= size) {
            cout << "Invalid position!\n";
            return;
        }

        for (int i = position; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        cout << "Deleted element at position " << position << endl;
    }

    void traverse() {
        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int search(int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) return i;
        }
        return -1;
    }
};

int main() {
    ArrayDS arr;
    arr.insert(0, 10);
    arr.insert(1, 20);
    arr.insert(2, 30);
    arr.traverse();
    arr.deletion(1);
    arr.traverse();
    cout << "Search 30: Found at index " << arr.search(30) << endl;
    return 0;
}
