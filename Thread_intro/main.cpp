#include <iostream>
#include<bits/stdc++.h>
#include<thread>
#include<chrono>
using namespace std;
int tr=0;
int func(){
    while(!tr){
    cout<<"hello\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
}
int main()
{
        auto start = std::chrono::high_resolution_clock::now();
    thread m_thread(func);
int a;
cin>>a;
tr=1;

    cout<<"main thread id number = "<<this_thread::get_id();

    //1- join the thread with the main thread meaning that the main thread is responsable for handling
     //the recourses Cleanup which used by the thread
// 2- Termination Handling: When a thread finishes its execution, it enters a terminated state. If you don't join()
//a terminated thread, its resources may not be released properly.
 // In some cases, not joining a thread can lead to program termination with an unhandled exception or crash.
if(m_thread.joinable()){
 m_thread.join();
}
// if you want to tell the main thread that someone else will handel resourse cleanup
// detach
// ex: m_thread_detach();


    cout<<"\n";
        auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
                std::cout << "Time used by the program: " << duration.count() << " milliseconds" << std::endl;
    return 0;
}
