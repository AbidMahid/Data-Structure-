#include <iostream>
#include <algorithm>
using namespace std;

class BinarySearch {
public:
    int search(int arr[], int n, int key) {
        int left = 0, right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == key) {
                return mid;
            } else if (arr[mid] < key) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    BinarySearch bs;
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 10;

    int result = bs.search(arr, n, key);

    if (result != -1) {
        cout << "Element " << key << " found at index " << result << endl;
    } else {
        cout << "Element " << key << " not found\n";
    }

    return 0;
}
