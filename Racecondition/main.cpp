

#include <iostream>
#include<bits/stdc++.h>
#include<thread>
#include<chrono>
#include<mutex>
#define num_of_thread 5

using namespace std;
mutex m_mutex;

int shared_res;
void add_value(int count){
    for(int i=0;i<count;i++){
        shared_res++;
    }
}

void test_race_condition(){
    vector<thread>threads;
    for(int i=0;i<num_of_thread;i++){
        threads.push_back(thread(add_value,10000));
    }
    for(int i=0;i<num_of_thread;i++){
        threads[i].join();
    }

}
int main()
{
for(int i=0;i<1000;i++){
    test_race_condition();
    if(shared_res!=50000){
        cout<<"ERROR in count trie : "<<i<<" == "<<shared_res<<endl;
    }
    shared_res=0;
}

    return 0;
}
