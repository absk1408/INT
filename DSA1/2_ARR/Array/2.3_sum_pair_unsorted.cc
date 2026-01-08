#include <iostream>
#include <unordered_set>
using namespace std;
bool findPairWithSum(int arr[], int n, int target) {
    unordered_set<int> hm;
    for(int i=0;i<n;i++){
        int res=target-arr[i];
        if(hm.find(res)!=hm.end()){
            return true;
        }
        else{
            hm.insert(arr[i]);
        }
    }
    return false;
}

int main() {
    int arr[] = {8, 7, 2, 5, 13, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    cout<<boolalpha<<findPairWithSum(arr, n, target);
    return 0;
}
