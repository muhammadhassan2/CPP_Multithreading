#include <iostream>
#include <bits/stdc++.h>
using namespace std;
template<class T>
T calc(T val){
    return val*val;
}
void func(promise<int>&&pro){
    this_thread::sleep_for(chrono::milliseconds(1000));
    pro.set_exception(make_exception_ptr(std::runtime_error("Runtime Error\n")));
}

int main()
{
promise<int>mypromise;
future<int>myfuture=mypromise.get_future();

thread mythread(func,move(mypromise)) ;

try{
    myfuture.get();

}
catch(const exception &ex){
    cout<<"Catching exception :"<<ex.what()<<endl;
}

if(mythread.joinable()){
    mythread.join();
}
cout<<endl;
    return 0;
}
