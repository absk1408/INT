//ABHISHEK YADAV/absk1408
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<fstream>
#include<string>
using namespace std;
//
int main(){
    fstream file("file.txt",ios::in|ios::out|ios::app);
    string input((istreambuf_iterator<char>(file)),istreambuf_iterator<char>());
    cout<<input<<endl;
    file.seekg(0);
    string str;
    while(getline(file,str,'.')){
        cout<<str<<endl;
    }
    file.clear();
   // ofstream wfile("file.txt",ios::app);
    file<<endl<<"i wrote this"<<endl;
    file<<"yes i did this"<<endl;
    file.close();



    return 0;
}