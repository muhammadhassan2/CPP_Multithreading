


//// deadlock.cpp

#include <iostream>
#include <chrono>
#include <mutex>
#include <thread>
using namespace std;
struct CriticalData{
  std::mutex mut;
};

void deadLock(CriticalData& a, CriticalData& b){

  unique_lock<mutex>lck1(a.mut);
  std::cout << "get the first mutex" << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(1));
  if(unique_lock<mutex>lck2(b.mut,std::chrono::milliseconds(1000))){

  }
  else{
      lck1.unlock();
  }
  b.mut.lock();
  std::cout << "get the second mutex" << std::endl;
  // do something with a and b
  a.mut.unlock();
  b.mut.unlock();

}

int main(){
  // this code will wait for ever because
  CriticalData c1;
  CriticalData c2;

  std::thread t1([&]{deadLock(c1,c2);});
  std::thread t2([&]{deadLock(c2,c1);});

  t1.join();
  t2.join();

}
