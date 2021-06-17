#pragma once
#include <mutex>

using namespace std;

class PriorityMutex {
public:
  PriorityMutex() {};
  ~PriorityMutex() {};
  void lowPriorityLock(){
    low_priority.lock();
    next_to_access.lock();
    data.lock();
    next_to_access.unlock();
  };
  void lowPriorityUnlock(){
    data.unlock();
    low_priority.unlock();
  };
  void highPriorityLock(){
    next_to_access.lock();
    data.lock();
    next_to_access.unlock();
  };
  void highPriorityUnlock(){
    data.unlock();
  };
  
private:
  mutex data;
  mutex next_to_access;
  mutex low_priority;
};
