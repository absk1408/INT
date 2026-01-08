//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#define loop(x,n) for(int i=x;i<n;i++)
//
using namespace std;
int sumOfDigits(int n)
    {
        if(n<10)return n;
        int ans=n%10;
        return ans+sumOfDigits(n/10);
    }
int main(){
    int a=2368;
    int ans=sumOfDigits(a);
    cout<<ans<<endl;

    return 0;
}