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
    cout<<"gfhg\n";
     auto start = std::chrono::high_resolution_clock::now();
    cout<<"Start the main thread\n";
  thread parse_thread(Parse_Files);
  Parse_Files();
// we create on thread runs the function this reduce the total time used
 while(files!=2);
      Do_Task();


  auto end = std::chrono::high_resolution_clock::now();
      auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
          std::cout << "Time used by the program: " << duration.count() << " milliseconds" << std::endl;
if(parse_thread.joinable()){
    parse_thread.join();
}
    return 0;
}
