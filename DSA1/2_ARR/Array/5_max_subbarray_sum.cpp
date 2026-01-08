//Kadenes Algo
//should contain negatives.
// if all positive then whole array sum = max sum
#include<iostream>
#include<algorithm>
using namespace std;
int max_sum(int *arr,int n){
    int res=arr[0];
    int curr=arr[0];
    for(int i=1;i<n;i++){
        curr=max(curr+arr[i],arr[i]);
        res=max(res,curr);
    }
    return res;
}
void max_sum_ind(int arr[], int n){
    int res = arr[0], curr = arr[0];

    int start = 0, end = 0;
    int tempStart = 0;

    for(int i = 1; i < n; i++){
        if(arr[i] > curr + arr[i]){
            curr = arr[i];
            tempStart = i;
        } else {
            curr += arr[i];
        }

        if(curr > res){
            res = curr;
            start = tempStart;
            end = i;
        }
    }

    cout << start << "-" << end;
}
int main(){
    const int n=5;
    int arr[n]={2,-1,2,-1,2};
    cout<<max_sum(arr,n)<<endl;
    max_sum_ind(arr,n);
    
    return 0;
}