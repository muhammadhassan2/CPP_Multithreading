#include <iostream>
#include<bits/stdc++.h>
#include<thread>
#include<chrono>
#include<mutex>
using namespace std;
int files;
mutex m_mutex;
void Parse_Files(){
    cout<<"Start parsing\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    cout<<"finish parsing\n";
 //   m_mutex.lock();
    files++;
  //  m_mutex.unlock();
}
void Do_Task(){
    cout<<"Start doing task\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    cout<<"Finished doing task\n";
}
int main()
{

     auto start = std::chrono::high_resolution_clock::now();
    cout<<"Start the main thread\n";
    // we can create 2 thread runs the same function
  thread parse_thread(Parse_Files);
  thread parse_thread2(Parse_Files);
  if(parse_thread.joinable()){
      parse_thread.join();
  }
  if(parse_thread2.joinable()){
      parse_thread2.join();
  }

  if(files==2){
      Do_Task();
  }

  auto end = std::chrono::high_resolution_clock::now();
      auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
          std::cout << "Time used by the program: " << duration.count() << " milliseconds" << std::endl;

    return 0;
}
