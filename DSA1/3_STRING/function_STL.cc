#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "ABHISHEK";
    string str2="hello world!";
    // Let's say we want to delete the character at index 5 ('W')
    int pos = 5;
    str2.erase(2,1);
    str2.erase(pos,4); // erase 1 character at position 'pos'

   cout << "After deletion: " << str2 << endl;  // Output: Helloorld
    
    str.insert(8,"yadav"); cout<<str<<endl;
    str.insert(8,3,'1'); cout<<str<<endl;  //if number of time then only character are allowed
    // str.insert(8,5,"abhi"); ERROR
    string a="abc"; string temp=""
;    for(int i=0;i<3;i++){
    temp+=a;
    }
    str.insert(8,temp);

    cout<<str<<endl;

    return 0;

}
