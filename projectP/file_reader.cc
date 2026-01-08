//ABHISHEK YADAV/absk1408
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<fstream>
#include<string>
using namespace std;
//
int main(){
    ifstream file("file.txt");
    string input((istreambuf_iterator<char>(file)),istreambuf_iterator<char>());
    cout<<input<<endl;
    file.clear();
    file.seekg(0);
    string str;
    while(getline(file,str,'.')){
        cout<<str;
    }
    file.clear();
    file.seekg(0);
    file.close();

    ofstream wfile("file.txt",ios::app);
    wfile<<endl<<"i wrote this"<<endl;
    wfile<<"yes i did this"<<endl;
    wfile.close();



    return 0;
}