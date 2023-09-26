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

 Parse_Files();
 Parse_Files();
  if(files==2){
      Do_Task();
  }
// pares_files function takes 2 sec and there are two the 4 sec and do task takes 2 sec
 // then the total time used is 6 seconds
  // how we can reduce the total time using threads
  auto end = std::chrono::high_resolution_clock::now();
      auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
          std::cout << "Time used by the program: " << duration.count() << " milliseconds" << std::endl;

    return 0;
}
