#include <iostream>
using namespace std;
void leftRotateByOne(int arr[], int n) {
    int first = arr[0];  // store first element

    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1]; // shift elements left
    }

    arr[n - 1] = first;  // put first element at end
}
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    leftRotateByOne(arr, n);
    cout << "Array after left rotation: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
