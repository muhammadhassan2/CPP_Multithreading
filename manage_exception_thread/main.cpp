
#include <iostream>
#include<bits/stdc++.h>
#include<chrono>
#include<mutex>
#include<thread>
using namespace std;
exception_ptr globall=nullptr;
void Worker(){
    cout<<"start work\n";
    try{
        this_thread::sleep_for(chrono::milliseconds(100));
        throw runtime_error("run time errrrror\n");

    }
    catch(const exception &ex){
        globall=make_exception_ptr(ex);
       // cout<<"Exeption error"<<" "<<ex.what();
    }

}
int main()
{
    thread t1(Worker);
    t1.join();
    if(globall){
    try{
          rethrow_exception(globall);
    }
    catch(const exception &ex){
        cout<<"Thread exited "<<ex.what()<<endl;
    }
}
    return 0;
}
