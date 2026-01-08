#include <iostream>
#include <vector>
using namespace std;

int maxConsecutiveOnes(vector<int>& arr) {
    int count = 0, maxCount = 0;
    for (int i = 0; i < arr.size(); i++) {
        if(arr[i]==0){
            maxCount=max(count,maxCount);
            count=0;
        }
        else{
            count++;
        }
    }
    maxCount=max(count,maxCount);  //trailing 1's
    return maxCount;
}
int main() {
    vector<int>arr={1, 1, 0, 1, 1, 1, 0, 1, 1};
    cout <<"Maximum Consecutive 1s:" << maxConsecutiveOnes(arr) << endl;
    return 0;
}
