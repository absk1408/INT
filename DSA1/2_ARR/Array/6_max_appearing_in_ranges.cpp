#include<iostream>
#include<algorithm>
using namespace std;

void optimised(int *left, int *right, int size) {
    int arr[101] = {0};

    // Step 1: Mark frequency changes
    for(int i = 0; i < size; i++) {
        arr[left[i]]++;
        arr[right[i] + 1]--;
    }

    // Step 2: Prefix sum to get actual counts
    int res = 0;
    for(int i = 1; i < 100; i++) {
        arr[i] += arr[i - 1];
        if(arr[i] > arr[res]) {
            res = i;
        }
    }

    cout << res << endl;
}

int main() {
    const int n = 4;
    int arr1[n] = {1, 4, 3, 1};
    int arr2[n] = {15, 8, 5, 4};

    optimised(arr1, arr2, n); 
    return 0;
}
