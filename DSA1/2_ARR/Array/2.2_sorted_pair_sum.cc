#include <iostream>
using namespace std;

bool findPairWithSum(int arr[], int n, int sum){
    int s=0;int e=n-1;
    while(s<e){
        int tot=arr[s]+arr[e];
        if(tot==sum) return true;
        else if(tot>sum){
            e--;
        }
        else{
            s++;
        }
    }
    return false;
}

int main() {
    int arr[] = {1, 2, 3, 4, 6, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 11;
    cout<<boolalpha<<findPairWithSum(arr, n, target);
    return 0;
}
