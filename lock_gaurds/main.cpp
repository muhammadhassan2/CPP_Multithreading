#include <iostream>
#include<bits/stdc++.h>
#include<chrono>
#include<mutex>
#include<thread>
using namespace std;
mutex m_mutex;
void printthread(string threadid,int count){
   // lock_guard<mutex>lock(m_mutex);
    for(int i=0;i<count;i++){
        cout<<threadid<<" "<<i<<endl;
    }



}

int main()
{
    thread t1(printthread,"T1",1);
    thread t2(printthread,"T2",10);
    t1.join();
    t2.join();

    return 0;
}
