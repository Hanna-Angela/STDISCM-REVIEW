//PROBLEM 4: readers-writers problem
// multiple readers can acess at once
// only one writer can access at once
// if a writer is writing, no reader can read
// if a reader is reading, no writer can write


//note: critical  section is the PRIORITY.
// ALWAYS check if the ff is true:
// no deadlock
// no starvation
// no race condition

#include <iostream>
#include <thread>
#include <mutex>
#include <string>
#include <semaphore>
#include <chrono>
using namespace std;

int readersCount = 0;

// lock for critical section
counting_semaphore m(1);
counting_semaphore Srw(1);
counting_semaphore Sts(1);


// only the first reader will ACQUIRE the Srw semaphore
// only the last reader will RELEASE the Srw semaphore
void read(string thName){

    //TURNSTILE
    Sts.acquire();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    Sts.release();



	m.acquire();
	readersCount++;
    if (readersCount == 1){
        Srw.acquire();
    }
    m.release();


    for (int i = 0; i < 50; i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
        cout << thName;
    }
    
    m.acquire();
    readersCount--;
    if (readersCount == 0){
        Srw.release();
    }
    m.release();
}

void write(string thName){

    //TURNSTILE
	Sts.acquire();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    Sts.release();



    Srw.acquire();
    for (int i = 0; i < 50; i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
        cout << thName;
    }
    Srw.release();
}



int main(){
	cout << "//PROBLEM 4: readers-writers \n";

    thread w1(write, "w1");
	thread r1(read, "r1");
	thread r2(read, "r2");
    thread w2(write, "w2");
	thread r3(read, "r3");
	thread r4(read, "r4");
	

    w1.join();
	r1.join();
	r2.join();
    w2.join();
	r3.join();
	r4.join();
	

	return 0;
}
