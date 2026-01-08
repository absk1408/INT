#include<iostream>
using namespace std;
int main(){
    int n=25;
    int ans=0;
    for(int i=2;i<=n;i++){
        int a=i;
        while(a%5==0&&a>=5){
            ans++;
            a=a/5;
        }
    }
    cout<<ans;
}