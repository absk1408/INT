//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
void printspiral(int mat[][],int r,int c){
    int top=0,bot=r-1,left=0,right=c-1;
    while(top<=bot&&left<=right){
        for(int i=left;i<=right;i++){
            cout<<mat[top][i]<<" ";
        }
        top++;
        for(int i=top;i<=bot;i++){
            cout<<mat[i][right];
        }
        right--;
        if(top<=bot){
            for(int i=right;i>=left;i--){
                cout<<mat[bot][i];
            }
            bot--;
        }
        if(left<=right){
            for(int i=bot;i>=top;i--){
                cout<<mat[i][left];
            }
        }

    }
}
int main(){
    //
    return 0;
}