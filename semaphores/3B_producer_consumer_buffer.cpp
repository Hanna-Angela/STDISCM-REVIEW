//PROBLEM 3B: producer-consumer problem (bounded buffer)
// no negative
// MAX n amount of produce


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

// like a parking lot

// signal for users of critical section

// full = how many parking spaces are IN USE/full
counting_semaphore Sc(0);

// empty = how many parking spaces are NOT IN USE/empty
// bounded buffer size 3
counting_semaphore Sb(3); 

void producer(string thName){

	Sb.acquire();
	
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

	Sb.release();

}

int main(){
	cout << "PROBLEM 3B: producer-consumer problem (bounded buffer)\n";

	thread c1(consumer, "c1");
	thread p1(producer, "p1");
	thread p2(producer, "p2");
	thread p3(producer, "p3");
	thread p4(producer, "p4");
	thread p5(producer, "p5");

	c1.join();
	p1.join();
	p4.join();
	p2.join();
	p5.join();
	p3.join();
	
	cout << "PROBLEM 3A: end\n";

	return 0;
}