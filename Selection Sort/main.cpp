#include <iostream>
using namespace std;

class SelectionSort {
public:
    void sort(int arr[], int n) {
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                swap(arr[i], arr[minIndex]);
            }
        }
    }

    void display(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    SelectionSort ss;
    int arr[] = {29, 10, 14, 37, 13, 25};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    ss.display(arr, n);

    ss.sort(arr, n);

    cout << "Sorted array: ";
    ss.display(arr, n);

    return 0;
}
