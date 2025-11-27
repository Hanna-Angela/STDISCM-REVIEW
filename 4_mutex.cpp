// RACE CONDITION
// 2 threads modifying same variable at same time

// MUTEX
// only 1 thread can access variable at a time

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int myAmount = 1;
std::mutex m;

void addMoney(int amount){
    m.lock();
    myAmount += amount;
    m.unlock();
}

int main(){
   std::thread t1(addMoney, 100);
   std::thread t2(addMoney, 200);

   t1.join();
   cout << "My amount 1: " << myAmount << endl;
   t2.join();

   cout << "My amount: " << myAmount << endl;

    return 0;
}