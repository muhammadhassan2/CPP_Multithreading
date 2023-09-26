#include <iostream>
#include<bits/stdc++.h>
#include<thread>
#include<chrono>
#include<mutex>
using namespace std;
int files;
#define num_of_thread 8
mutex m_mutex;
void Parse_Files(){
    cout<<"Start parsing\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    cout<<"finish parsing\n";
    files++;
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
  vector<thread>threads;
  for(int i=0;i<num_of_thread;i++){
      threads.push_back(thread(Parse_Files));
  }

//  while(files!=num_of_thread);
//      Do_Task();
  for(int i=0;i<num_of_thread;i++){

      if(threads[i].joinable()){
          threads[i].join();
      }
  }
   cout<<files<<endl;
      if(files==num_of_thread){
          Do_Task();
      }

  auto end = std::chrono::high_resolution_clock::now();
      auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
          std::cout << "Time used by the program: " << duration.count() << " milliseconds" << std::endl;

    return 0;
}
