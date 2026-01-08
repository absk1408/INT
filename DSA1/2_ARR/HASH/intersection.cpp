//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<unordered_set>
using namespace std;
int unionSize(int arr1[],int m, int arr2[],int n){
    unordered_set<int> s(arr1,arr1+m);
    s.insert(arr2,arr2+m);
    return s.size();

}
int main(){
    int arr1[] = {2, 8, 3, 5, 6};
    int arr2[] = {4, 8, 3, 6, 1};
    int m = sizeof(arr1)/sizeof(arr1[0]);
    int n = sizeof(arr2)/sizeof(arr2[0]);
    cout << unionSize(arr1, m, arr2, n);
    return 0;
}