#include <iostream>
using namespace std;
void leftRotateByOne(int arr[], int n,int d){
    //reverse(arr,0,d-1);
    //reverse(arr,d,n-1);
    //reverse(arr,0,n-1);


}
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    leftRotateByOne(arr, n,2);
    cout << "Array after left rotation: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
