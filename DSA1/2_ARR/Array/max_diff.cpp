// C++ program to find Maximum difference
// between two elements such that larger
// element appears after the smaller number
#include <bits/stdc++.h>
using namespace std;

/* The function assumes that there are
at least two elements in array. The
function returns a negative value if the
array is sorted in decreasing order and
returns 0 if elements are equal */
int maxDiff(int arr[], int arr_size){
    int min=0;
    int ans=0;
    for(int i=1;i<arr_size;i++){
        int a=arr[i]-arr[min];
        if(a>ans) ans=a;
        else if(arr[i]<arr[min]) min=i;
    }
    return ans;
}

/* Driver program to test above function */
int main()
{
	int arr[] = {1, 2, 90, 10, 110};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	// Function calling
	cout<<maxDiff(arr, n);

	return 0;
}
