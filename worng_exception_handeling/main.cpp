#include <iostream>
#include<bits/stdc++.h>
#include<chrono>
#include<mutex>
#include<thread>
using namespace std;

void Worker(){
    cout<<"start work\n";
    throw runtime_error("error in worker class\n");
}
int main()
{

    try{
        thread t1(Worker);
        t1.join();
    }
    catch(exception &ex){
        cout<<"Thread exited "<<ex.what<<endl;
    }

    return 0;
}
