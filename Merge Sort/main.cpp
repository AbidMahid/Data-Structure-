#include <iostream>
using namespace std;

class MergeSort {
private:
    void merge(int arr[], int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;

        int* L = new int[n1];
        int* R = new int[n2];

        for (int i = 0; i < n1; i++) L[i] = arr[l + i];
        for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

        int i = 0, j = 0, k = l;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) arr[k++] = L[i++];
            else arr[k++] = R[j++];
        }

        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];

        delete[] L;
        delete[] R;
    }

public:
    void sort(int arr[], int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;
            sort(arr, l, m);
            sort(arr, m + 1, r);
            merge(arr, l, m, r);
        }
    }

    void show(int arr[], int n) {
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    MergeSort ms;
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
    ms.show(arr, n);

    ms.sort(arr, 0, n - 1);

    cout << "Sorted: ";
    ms.show(arr, n);

    delete[] arr;

    return 0;
}
