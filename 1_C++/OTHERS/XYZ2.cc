#include<iostream>
using namespace std;
template<typename T, typename... Args>
void fun(T n, Args... rest){
    cout<<n<<endl;
    if constexpr(sizeof...(rest)>0){
        fun(rest...);
    }
}
int main(){
    return 0;
}
