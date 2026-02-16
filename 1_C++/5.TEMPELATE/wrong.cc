//The template<typename T> applies only to the very next entity (function, class, struct).
//If you want to use templates in multiple entities, you must repeat template<typename T> before each.
//or look for specaialzed template options

#include<iostream>
using namespace std;
template<typename T>
T add(T a, T b) {
    return a + b;
}
int main(){
    return 0;
}
