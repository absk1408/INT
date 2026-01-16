//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
//#pragma pack(1)
using namespace std;
struct stru {
    uint8_t a; uint16_t b;

    void showSize() {
        cout << "Size of class: " << sizeof(*this) << " bytes" << endl;
    }
}__attribute__((packed));   //with attribute 3 bytes witjiut 4 bytes
int main(){
    stru st;
    st.showSize();
    return 0;
}