#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

// if(m.try_lock())
// tries to access variable ONCE
//no waiting. if the variable is locked, it skips it n goes on w the rest of its code
// can only be called ONCE per lock attempt
// CANT call without if statement

// use cases: 
// 1. when u want to avoid deadlocks
// 2. when u want to do other stuff if u cant access the variable   
// game loops, ui apps that u dont want to freeze just bc its waiting for access on a resource

int counter = 0;
std::mutex m;

void count_to_100(){
    
    for (int i = 0; i < 100000; i++){
        if (m.try_lock())
        {
            counter++;
            m.unlock();
        }
    }
}

int main(){
   std::thread t1(count_to_100);
   std::thread t2(count_to_100);

   t1.join();
   t2.join();

   // we get random values less than 200 because sometimes
   // one thread cant access the variable so it skips incrementing counter
   cout << "My count: " << counter << endl;

    return 0;
}