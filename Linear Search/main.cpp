#include <iostream>
using namespace std;

class LinearSearch {
public:
    int search(int arr[], int n, int key) {
        for (int i = 0; i < n; i++) {
            if (arr[i] == key) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    LinearSearch ls;
    int arr[] = {2, 4, 0, 1, 9, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 5;

    int result = ls.search(arr, n, key);

    if (result != -1) {
        cout << "Element " << key << " found at index " << result << endl;
    } else {
        cout << "Element " << key << " not found\n";
    }

    return 0;
}
