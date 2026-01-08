#include <iostream>
#include <cmath>
using namespace std;
int remDups(int arr[], int n) //two pointer tech.
{
	int res=1;
    for(int i=1;i<n;i++){
        if(arr[i]!=arr[res-1]){
            arr[res]=arr[i];
            res++;
        }
    }
    return res;
}    
int main() {	
    int arr[] = {10, 10,30,30,30,40}, n = 6;
      cout<<"Before Removal"<<endl;
       for(int i = 0; i < n; i++)
       {
       		cout<<arr[i]<<" ";
       }
       cout<<endl;
       n = remDups(arr, n);
       cout<<n<<endl;
       cout<<"After Removal"<<endl;
       for(int i = 0; i < n; i++)
       {
       		cout<<arr[i]<<" ";  
       }    
}
