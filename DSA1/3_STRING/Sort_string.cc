#include <iostream>
#include <string>
#include<algorithm>
using namespace std;
int main() {
    string  st="adjawawdnjawndja";
    sort(st.begin(),st.end(),[](char& a,char& b){return a<b;});
    cout<<st<<endl;
    return 0;
}
