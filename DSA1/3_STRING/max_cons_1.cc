#include <iostream>
#include <cmath>
using namespace std;

int maxConsecutiveOnes(int arr[], int n) {
    int maxCount = 0, currentCount = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == 1) {
            currentCount++;
            maxCount = max(maxCount, currentCount); // Update maxCount if the current sequence of 1's is greater
        } else {
            currentCount = 0; // Reset count when a 0 is encountered
        }
    }
    
    return maxCount;
}
////
int main() {
    int arr[] = {0, 1, 1, 0, 1, 0, 1, 1, 1, 1};
    int n = 10;
    cout << "Maximum consecutive 1's: " << maxConsecutiveOnes(arr, n) << endl;
    return 0;
}
