#include <iostream>
using namespace std;

class QuickSort {
private:
    int part(int arr[], int low, int high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }

public:
    void sort(int arr[], int low, int high) {
        if (low < high) {
            int pi = part(arr, low, high);
            sort(arr, low, pi - 1);
            sort(arr, pi + 1, high);
        }
    }

    void show(int arr[], int n) {
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    QuickSort qs;
    int n;

    cout << "How many numbers? ";
    cin >> n;

    int* arr = new int[n];

    cout << "Enter " << n << " numbers:\n";
    for (int i = 0; i < n; i++) {
        cout << i+1 << ": ";
        cin >> arr[i];
    }

    cout << "\nOriginal: ";
    qs.show(arr, n);

    qs.sort(arr, 0, n - 1);

    cout << "Sorted: ";
    qs.show(arr, n);

    delete[] arr;

    return 0;
}
