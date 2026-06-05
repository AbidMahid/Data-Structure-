#include <iostream>
#include <cstring>
using namespace std;

class CountingSort {
public:
    void sort(int arr[], int n) {
        int max = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] > max) max = arr[i];
        }

        int* count = new int[max + 1]();

        for (int i = 0; i < n; i++) {
            count[arr[i]]++;
        }

        int index = 0;
        for (int i = 0; i <= max; i++) {
            while (count[i] > 0) {
                arr[index++] = i;
                count[i]--;
            }
        }

        delete[] count;
    }

    void display(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    CountingSort cs;
    int arr[] = {4, 2, 2, 8, 3, 3, 1, 4, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    cs.display(arr, n);

    cs.sort(arr, n);

    cout << "Sorted array: ";
    cs.display(arr, n);

    return 0;
}
