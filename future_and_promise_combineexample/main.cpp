#include <iostream>
#include <bits/stdc++.h>
using namespace std;
template<class T>
T calc(T val){
    return val*val;
}
void func(promise<int>&&pro){
    int ans=calc(5);
    this_thread::sleep_for(chrono::milliseconds(5000));
    pro.set_value(ans);
}

int main()
{
promise<int>mypromise;
future<int>myfuture=mypromise.get_future();

thread mythread(func,move(mypromise)) ;
if(myfuture.valid()){

    while(myfuture.wait_for(chrono::milliseconds(1))==future_status::timeout){
        cout<<"do somthing else \n";
    }
    try{
        cout<<myfuture.get()<<endl;
    }
    catch (const exception &ex){
        cout<<"catching ex "<<ex.what()<<endl;
    }
}

if(mythread.joinable()){
    mythread.join();
}
cout<<endl;
    return 0;
}
