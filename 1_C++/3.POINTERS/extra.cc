class base{
    int a;char c;public:
    base(int a,char c){
    this->a=a;
    this->c=c;}
};
template<typename T, typename... Arg>
SP<T> make_SP(Arg&&... a){
    return SP<T>(new T(forward<Arg> (a)...));
}

int main(){
        //SP<base> up2=make_SP<base>(100,'A');
return 0;
}