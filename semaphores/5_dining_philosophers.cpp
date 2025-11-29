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

int chopstick_Status[5] = {0, 0, 0, 0, 0};
int philosopher_Status[5] = {0, 0, 0, 0, 0};

// lock for critical section
counting_semaphore<1> a(1);
counting_semaphore<1> b(1);
counting_semaphore<1> c(1);
counting_semaphore<1> d(1);
counting_semaphore<1> e(1);
counting_semaphore<1> *s_c[5] = {&a, &b, &c, &d, &e};
counting_semaphore m(1);


void philosophize(int id){
    for (int i = 0; i < 5; i++){
        // wait for two chopsticks
        s_c[id]->acquire();
        s_c[(id + 1) % 5]->acquire();

        // get the two chopsticks
        m.acquire();
        chopstick_Status[(id+0)%5] = 1;
        chopstick_Status[(id+1)%5] = 1;
        string  s = to_string(chopstick_Status[0]);
                s += to_string(chopstick_Status[1]); 
                s += to_string(chopstick_Status[2]); 
                s += to_string(chopstick_Status[3]); 
                s += to_string(chopstick_Status[4]);
        cout << "P" << id << ": " << s << "\n" << endl;
        m.release();


        // philosoper eating
        philosopher_Status[id] = 1;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        philosopher_Status[id] = 0;


        
        // RELEASE
        m.acquire();
        chopstick_Status[id] = 0;
        chopstick_Status[(id + 1) % 5] = 0;
        m.release();

        s_c[id]->release();
        s_c[(id + 1) % 5]->release();


    }
}


int main(){
	cout << "//PROBLEM 4: readers-writers \n";

    thread p0(philosophize, 0);
	thread p1(philosophize, 1);
	thread p2(philosophize, 2);
    thread p3(philosophize, 3);
	thread p4(philosophize, 4);
	

    p0.join();
	p1.join();
	p2.join();
    p3.join();
	p4.join();
	

	return 0;
}