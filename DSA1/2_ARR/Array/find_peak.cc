#include <iostream>
using namespace std;


int getPeak(int arr[], int n){ //naive 0(n)
    int l=0;int r=n-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if( (mid==0||arr[mid-1]<arr[mid]) && (arr[mid]==n-1|| arr[mid]>arr[mid+1] )){
            return arr[mid];
        }
        else if(arr[mid]>0&&arr[mid]<arr[mid-1]){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
        
    }
    return -1;
}

int main() {
    

 int arr[] = {5, 20, 40, 30, 20, 50, 60}, n = 7;

 cout << getPeak(arr, n);

	return 0;
}