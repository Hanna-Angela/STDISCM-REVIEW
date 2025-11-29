//PROBLEM 3A: producer-consumer problem
// no negatve


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
using namespace std;

int count = 0;
// lock for critical section
counting_semaphore m(1);

// signal for users of critical section
counting_semaphore Sc(0);

void producer(string thName){
	m.acquire();
	count++;
	cout << thName << " count = " << count << "\n" << endl;
	m.release();



	//SIGNAL
	Sc.release();
}

void consumer(string thName){
	//SIGNAL
	Sc.acquire();



	m.acquire();
	count--;
	cout << thName << " count = " << count << "\n" << endl;
	m.release();

}

int main(){
	cout << "PROBLEM 3A: producer-consumer problem\n";

	thread c1(consumer, "c1");
	thread p1(producer, "p1");
	thread c2(consumer, "c2");
	thread p2(producer, "p2");
	thread c3(consumer, "c3");
	thread p3(producer, "p3");

	c1.join();
	p1.join();
	c2.join();
	p2.join();
	c3.join();
	p3.join();
	
	cout << "PROBLEM 3A: end\n";

	return 0;
}